#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Data {
    string  website;
    string text;
    int rankw;
    int rankt;
    Data* next;
};

void print(Data *head);
void menu();
Data *quitwithoutsaving(Data *head);
Data *readData();
Data *reload(Data *head);
void search(Data *head);
void printR(Data *head);
void replacing(Data *a1, Data *b1);
void saveData(Data *head);

int main(){
    Data *head=readData();
    for(;;)
    {
        menu();
        int i;
        cout<<"Enter the choice"<<endl;
        cin >>i;
        if (i==5)
        {
            head=quitwithoutsaving(head);
            break;
        }
        if (i==2)
        {
            head=reload(head);
        }
        if (i==1)
        {
            head=reload(head);
            search(head);
            printR(head);
        }
        if (i==3)
        {
            saveData(head);
        }
        if (i==4)
        {
            saveData(head);
            head=quitwithoutsaving(head);
            break;
        }
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
    head->rankt=0; head->rankw=0;
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
                a->rankt=0; a->rankw=0;
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

void print(Data *head)
{
    if (head!=NULL)
    {
        Data *a=head;
        cout<<a->website<<endl;
        cout<<a->text<<endl;cout<<endl;
        while (a->next!=NULL)
        {
            a=a->next;
            cout<<a->website<<endl;
            cout<<a->text<<endl;
            cout<<endl;
        }
    }
}

void menu()
{
    cout<<"1. Search"<<endl
        <<"2. reload data"<<endl
        <<"3. save data"<<endl
        <<"4. quit and save data"<<endl
        <<"5. quit without saving"<<endl
        <<endl;
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

Data *reload(Data *head){
    head=quitwithoutsaving(head);
    head=readData();
    return head;
}

void search(Data *head)
{
    string lowR;
    cout<<endl;
    string tos;
    cout <<"Enter what to search"<<endl;
    getline(cin,tos);
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
    string b; string c;
    Data *a=head;

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
        a=head;
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
                string temp1=s1;string temp2=s;
                if (temp1==temp2)
                {
                    ifstream in;
                    in.open("lowRank.txt");
                    while(!in.eof())
                    {
                        getline(in,lowR);
                        if (temp2==lowR)
                        {
                            n=count1+1;
                            break;
                        }
                    }
                    a->rankt=a->rankt+1;
                }
            }
            a=a->next;
        }
        a=head;
    }

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

void saveData(Data *head){
    if (head!=NULL)
    {
        Data *a=head;
        if (a->rankw!=0||a->rankt!=0){

            char outfile[16];
            cout<<"Enter the file name"<<endl;
            cin>>outfile;
            ofstream out;
            strcat(outfile,".txt");
            out.open(outfile);
            out<<a->website<<endl;
            out<<a->text<<endl;
            out<<endl;

        while (a->next!=NULL)
        {
            a=a->next;
            if (a->rankw!=0||a->rankt!=0){
                out<<a->website<<endl;
                out<<a->text<<endl;
                out<<endl;
            }
        }
        out<<endl;
        cout<<endl;
        out.close();
    }else
        cout<<"No data searched Yet"<<endl;
    }
}


