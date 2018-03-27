#include <iostream>

using namespace std;

int StringLen(char stringinput[]);
int compareString (char string1[], char string2[]);
void stringCase(char stringinput[], bool choice);
void shiftString(int n, char stringinput[]);
void copyword(char b[], string c, int j1);

int main()
{
    string c1;
    cout<<"Enter the input"<<endl;
    getline(cin,c1);
    int s=c1.size();
    char a[s];
    copyword(a,c1,s);
    int j=StringLen(a);
    cout<<"The length of input = "<<j<<endl;cout<<endl;

    string c2;
    cout<<"Enter the input"<<endl;
    getline(cin,c2);
    s=c2.size();
    char b[s];
    copyword(b,c2,s);
    int j1=compareString (a,b);
    cout<<j1<<endl;cout<<endl;

    string c3;
    cout<<"Enter the input"<<endl;
    getline(cin,c3);
    s=c3.size();
    char d[s];
    copyword(d,c3,s);
    int j3=StringLen(d);
    int k;

    for (;;)
        {
        cout<<"Enter the Number of hoops"<<endl;
        cin >>k;
        if (k<0)
            {if (-k<=j3&&k<0)
                break;}
        if (k>0)
            {if (k<=j3)
                break;}
        }
    shiftString(k,d); cout<<endl;

    string c4;
    cout<<"Enter the input"<<endl;
    getline(cin,c4);getline(cin,c4);cout<<endl;
    s=c4.size();
    char c[s];
    copyword(c,c4,s);

    bool ch;
    cout<<"Do you want it to be in lower or upper case? 0/1"<<endl;
    cin >>ch;
    stringCase(c,ch); cout<<endl;
}

int StringLen(char stringinput[]){
    int k=0;
    int j=0;
    for(;;)
    {
        if(stringinput[j]!='\0')
            k++;
        else
            break;
        j++;
    }
    return k;
}

int compareString (char string1[], char string2[]){
    int j1=StringLen(string1);
    int j2=StringLen(string2);
    int j=0;
    if (j1>j2)
        j=j1;
    else
        j=j2;

    for (int n=0; n<j;n++)
    {
        if (n<j1)
        {
            if (isupper(string1[n]))
                string1[n]=tolower(string1[n]);
        }
        if (isupper(string2[n]))
            string2[n]=tolower(string2[n]);
    }
    int c=0;int l;int k;
    for (int n=0; n<j;n++){
        l=string1[n]; k=string2[n];
        if(l==k)
            c++;
        else
            break;
    }
    if (c==j)
        return 0;
    else if (l>k)
        return 1;
    else if (k>l)
        return -1;
}

void stringCase(char stringinput[], bool choice){
    int n=StringLen(stringinput);

    if (choice)
    {
        for (int j=0;j<n;j++)
        {
            int a=stringinput[j];
            if (a>=97&&a<=122&&a!=32)
                {a=a-32;
                stringinput[j]=a;}}
    }
    else
    {
        for (int j=0;j<n;j++)
        {
            int a=stringinput[j];
            cout<<a<<endl;
            if (a>=65&&a<=90&&a!=32)
                {a=a+32;
                cout<<a<<endl;
                stringinput[j]=a;}}
    }
    cout<<stringinput<<endl;
}

void shiftString(int k, char stringinput[]){

    int j=StringLen(stringinput);
    char temp[j+1];temp[j]='\0';
    int n2=0;

    for (int n=0;n<j;n++)
    {
        n2=n;
        if (k<0)
        {
            for (int n1=0;n1<(-k);n1++)
            {
                n2--;
                if(n2<0)
                    n2=j-1;
            }
            temp[n2]=stringinput[n];
        }
        if (k>0)
        {
            for (int n1=0;n1<k;n1++)
            {
                n2++;
                if(n2>j-1)
                    n2=0;
            }
            temp[n2]=stringinput[n];
        }
    }
    cout<<temp<<endl;
}

void copyword(char b[], string c, int j1){
    for (int n=0;n<j1;n++)
    {
        b[n]=c[n];
    }
    b[j1]='\0';
}
