#include "Lexicon.cpp"
#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
double scoring(int count1, int total1, int count2, int total2);

int main(){
    string file;
    cout<<"Enter file name to open"<<endl;
    cin>>file;
    Lexicon lex(file);
    cout<<lex.count()<<endl;
    string token;
    cout<<"Enter word to search"<<endl;
    cin>>token;
    cout<<lex.count(token)<<endl;
    cout<<lex.contains(token)<<endl;
    lex.increment(token,5);
    cout<<lex.count(token)<<endl;
    lex.remove(token);
    lex.printLexicographically(cout);
    cout<<"Now cardinally"<<endl;
    lex.printCardinally(cout);
    Lexicon lex1(file);
    double i=0;
    i=lex.distanceFrom(lex1,scoring);
    cout<<i<<endl;

}

double scoring(int count1, int total1, int count2, int total2){
    int one=count1/total1;
    int two=count2/total2;
    return (one+two)/2;
}
