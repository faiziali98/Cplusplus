#include "Lexicon.h"
#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
// Some of the methods have default values to allow the code to
// compile, you are expected to replace these values with actual
// implementations.

using namespace std;

Lexicon::Lexicon(string &filename) {
    try{
        int s=filename.size();
        char b[20];int n;
        for (n=0;n<s;n++)
        {
            b[n]=filename[n];
        }
        b[n]='.';b[n+1]='t';b[n+2]='x';b[n+3]='t';b[n+4]='\0';
        ifstream in;
        in.open(b);
        if (in.fail())
            throw 0;
        if (in.eof())
            cout<<"No data in file"<<endl;
        else{
            string word;
            for (;;){
                in>>word;
                int s1=word.size();
                for (int n1=0;n1<s1;n1++)
                    word.at(n1)=tolower(word.at(n1));
                int ad=1;
                for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                    if ((*i).first==word){
                        (*i).second=(*i).second+1;
                        ad=0;
                    }
                }
                if (ad==1)
                    lex[word]=1;
                if (in.eof())
                    break;
            }
        }
    }catch(int a){
        cout<<"No file found"<<endl;
    }
}

Lexicon::~Lexicon() {
}

int Lexicon::count() {
    int num=0;
    for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                num=num+(*i).second;
    }
    return num;
}

int Lexicon::count(string &token) {
    map< string, int >::iterator it=lex.find (token);
    if ((*it).second!=0)
        return (*it).second;
    else
        return 0;
}

bool Lexicon::contains(string &token) {
    map< string, int >::iterator it=lex.find (token);
    if ((*it).second!=0)
        return true;
    else
        return false;
}

void Lexicon::increment(string &token) {
    for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                if((*i).first==token)
                {
                    (*i).second++;
                    break;
                }
    }
}

void Lexicon::increment(string &token, int n) {
    for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                if((*i).first==token)
                {
                    (*i).second=(*i).second+n;
                    break;
                }
    }
}

void Lexicon::remove(string &token) {
    lex.erase (token);
}

void Lexicon::printLexicographically(ostream &out) {
    for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                cout<<(*i).first<<", "<<(*i).second<<endl;;
    }
}

void Lexicon::printCardinally(ostream &out) {
    typedef pair<int, string> mmap_pair;
    multimap<int, string > temp;
    for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                temp.insert(mmap_pair((*i).second,(*i).first));
    }
    for( multimap< int, string >::reverse_iterator i=temp.rbegin(); i!=temp.rend(); ++i) {
                cout<<(*i).second<<", "<<(*i).first<<endl;;
    }
}


// Extra Credit - you do not need to modify this, but you can
// for extra credit.
double Lexicon::distanceFrom(Lexicon &other, double (*scoringFunction)(int count1, int total1, int count2, int total2)) {
    int c1=0;
    for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                c1=c1+(*i).second;
    }
    return c1;
    int c2=other.count();

    map< string, int > lex1=other.lex;
    int c3=0;
    int c4=0;
    double sum=0;
    for( map< string, int >::iterator i = lex.begin(); i != lex.end(); ++i ){
                c3=(*i).second;
                string f=(*i).first;
                c4=other.count(f);
                sum=sum+scoringFunction(c3,c1,c4,c2);
    }
    cout<<c1<<endl;
    sum=sum/c1;
    return sum;
}

