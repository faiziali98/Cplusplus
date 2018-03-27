#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

struct Data {
    string  website;
    string text;
    int rankw;
    int rankt;
    Data* next;
};

struct HashTable{
    string word;
    vector<Data*> dat;
    HashTable* next;
};

Data *readData();
Data *quitwithoutsaving(Data *head);
Data *reload(Data *head);
void printR(Data *head);
void replacing(Data *a1, Data *b1);
void hashingd(Data *head);
void printt(HashTable *head);
int hashingWord(string a);
void searchData(HashTable *head,string a);
void searchinweb(Data *head, string s);
void arranging(Data *head);

int main(){
    Data *head=readData();
    string tt;
    while(1){
        hashingd(head);
        printR(head);
        char a;
        cout<<"Do you wish to continue? y/n"<<endl;
        cin>>a;
        getline(cin,tt);
        if(a=='y')
            head=reload(head);
        else
            break;
    }
}

Data *readData(){

    ifstream input;
    input.open("data.txt");
    string s,temp;
    getline (input,s);getline (input,temp);
    Data *head=new Data;
    head->website=s;
    head->text=temp;
    head->next=new Data;
    Data *a=head->next; Data *b=head;
    for (;;)
    {
        getline (input,s);
        if (s.empty())
        {
            getline (input,temp);
            if (temp.empty())
            {
                b->next=NULL;
                break;
            }
            else
            {
                getline (input,s);
                a->website=temp;
                a->text=s;
                a->next=new Data;
                a->rankt=0;a->rankw=0;
                b=a;
                a=a->next;
            }
        }
        else
        {
            b->text=b->text+" "+s;
        }
    }
    input.close();
    return head;
}

Data *reload(Data *head){
    head=quitwithoutsaving(head);
    head=readData();
    return head;
}

void hashingd(Data *head){
        HashTable *has[15];
        for(int n=0;n<15;n++)
        {
            has[n]=NULL;
        }
        Data *a=head;
        string c;
        while (a!=NULL){
            c=a->text;
            int ss=c.size();
            int count1=0;
            for(int n3=0;n3<ss;n3++)
            {
                int l=c[n3];
                if (l==32)
                    count1++;
                else if (c[n3]=='\0')
                    break;
            }
            int k21=0;
            for(int n=0;n<=count1;n++)
            {
                char s1[100];
                int k11=0;

                for (;;)
                {
                    s1[k11]=c[k21];
                    k11++;
                    k21++;
                    int l=c[k21];
                    if (l==32||c[k21]=='\0')
                        { k21++; break;}
                }
                s1[k11]='\0';
                string temp=s1;
                int in=temp.size()%15;

                if(has[in]!=NULL)
                {
                    HashTable *ah=has[in];
                    HashTable *bh=NULL;
                    int sl=0;int sd=1;
                    string lowR;
                    while(ah!=NULL)
                    {
                        if (ah->word==temp)
                        {
                            ifstream in;
                            in.open("lowRank.txt");
                            while(!in.eof())
                            {
                                getline(in,lowR);
                                if (temp==lowR)
                                {
                                    sl=1;
                                    break;
                                }
                            }
                            in.close();
                            if (sl==1)
                            {
                                int si=ah->dat.size();
                                for(int n=0;n<si;n++)
                                {
                                    vector<Data*> temporary=ah->dat;
                                    if(temporary[n]==a)
                                    {
                                       sd=0;
                                       break;
                                    }
                                }
                            }
                            if(sd==0)
                                break;
                            else
                            {
                                ah->dat.push_back(a);
                                break;
                            }
                        }
                        bh=ah;
                        ah=ah->next;
                    }
                    if(ah==NULL)
                    {
                        HashTable *temp1=new HashTable;
                        temp1->word=temp;
                        temp1->next=NULL;
                        temp1->dat.push_back(a);
                        bh->next=temp1;
                    }
                }
                else
                {
                    has[in]=new HashTable;
                    has[in]->word=temp;
                    has[in]->next=NULL;
                    has[in]->dat.push_back(a);
                }
            }
            a=a->next;
        }
        string tos;
        cout <<"Enter what to search"<<endl;
        getline(cin,tos);

        int k=tos.size(); int count=0;
        for(int n=0;n<=k;n++)
        {
            int l=tos[n];
            if (l==32)
                count++;
            else if (tos[n]=='\0')
            {
                count++;
                break;
            }
        }
        int k2=0;
        string b;
        for(int n=0;n<count;n++)
        {
            char s[100];
            int k1=0;
            for (;;)
            {
                s[k1]=tos[k2];
                k1++;
                k2++;
                int l=tos[k2];
                if (l==32||tos[k2]=='\0')
                    { k2++; break;}
            }
            s[k1]='\0';
            b=s;
            int in=hashingWord(b);
            searchData(has[in],b);
            searchinweb(head, b);
        }
    arranging(head);
}

void printt(HashTable *head)
{
    if (head!=NULL)
    {
        HashTable *a=head;
        cout<<a->word<<endl;
        int siz=a->dat.size();

        for(int n=0;n<siz;n++)
        {
            cout<<a->dat[n]->website<<endl;;
        }
        cout<<endl;
        while (a->next!=NULL)
        {
            a=a->next;
            cout<<a->word<<endl;
            int siz=a->dat.size();
            for(int n=0;n<siz;n++)
            {
                cout<<a->dat[n]->website<<endl;;
            }
            cout<<endl;
        }
    }
}

int hashingWord(string a){
    int siz=a.size();
    int in=siz%15;
    return in;
}

void searchData(HashTable *head,string a){
    if (head!=NULL)
    {
        HashTable* b=head;
        while(b!=NULL)
        {
            if(b->word==a)
            {
                int s=b->dat.size();
                for(int n=0;n<s;n++)
                {
                    b->dat[n]->rankt=b->dat[n]->rankt+1;
                }
                break;
            }
            b=b->next;
        }
    }
}

void printR(Data *head){
    if (head!=NULL)
    {
        Data *a=head;
        if (a->rankw!=0||a->rankt!=0){
            cout<<a->website<<endl;
            cout<<a->text<<endl;
            cout<<endl;
        }
        else
            cout<<"No data found"<<endl;
        while (a->next!=NULL)
        {
            a=a->next;
            if (a->rankw!=0||a->rankt!=0){
                cout<<a->website<<endl;
               cout<<a->text<<endl;
                cout<<endl;
            }
        }
    }

}

void replacing(Data *a1, Data *b1){
    string t1=a1->website;string t2=a1->text;
    int r=a1->rankw; int r1=a1->rankt;
    a1->website=b1->website;
    a1->text=b1->text;
    a1->rankw=b1->rankw;
    a1->rankt=b1->rankt;
    b1->website=t1;
    b1->text=t2;
    b1->rankw=r;
    b1->rankt=r1;
}

void searchinweb(Data *head, string s){
    Data *a=head;
    string b;
    string lowR;
    while (a!=NULL){
        b=a->website;
        string temp=s; int t1=temp.size();
        int t=b.size(); int c=0;
        for(int n1=0;n1<=t;n1++)
        {
            if (temp[0]==b[n1])
            {
                c++;
                for(int n2=1;n2<t1;n2++)
                {
                    if(temp[n2]==b[n1+n2])
                        c++;
                    else
                    {
                        c=0; break;
                    }
                }
            }
            if(c==t1)
            {
                n1=n1+t1-1;
                ifstream in;
                in.open("lowRank.txt");
                while(!in.eof())
                {
                    getline(in,lowR);
                    if (temp==lowR)
                    {
                        n1=t+1;
                        break;
                    }
                }
                in.close();
                a->rankw=a->rankw+1;
                c=0;
            }
        }
        a=a->next;
    }
}

void arranging(Data *head){
    Data *a1=head;
    Data *b1;
    while(a1->next!=NULL)
    {
        b1=a1->next;
        while(b1!=NULL)
        {
            if(a1->rankw<b1->rankw)
            {
                replacing(a1,b1);
            }
            else if(a1->rankw==b1->rankw)
            {
                if (a1->rankt<b1->rankt)
                {
                    replacing(a1,b1);
                }
            }
            b1=b1->next;
        }
        a1=a1->next;
    }
}

Data *quitwithoutsaving(Data *head)
{
    if (head!=NULL)
    {
        Data *a=head->next;
        delete(head);
        head=NULL;

        while (a!=NULL)
        {
            Data *temp;
            temp=new Data;
            temp=a->next;
            delete(a);
            a=temp;
        }
    }
    return head;
}
