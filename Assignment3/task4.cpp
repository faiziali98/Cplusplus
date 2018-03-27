#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int StringLen(char stringinput[]);
void dispresult(int dd,int dr,int dl,int du,int j,int x,int y);
void copyword(char b[], string c, int j1);
int *dimensions();

int main()
{
    int start=1;
    int *p1;p1=dimensions();int y1=p1[1]+1; int x1=p1[0]+1;
    char a[x1][y1];
    ifstream input;
    input.open("puzzle.txt");
    int n1=0; int n2=0;

    while (n1<x1)
    {
        while (n2<y1)
        {
            if (n2==x1-1 || n1==y1-1)
                {a[n1][n2]='\0';
                n2++;}
            else
                {input>>a[n1][n2];
                    n2++;}

        }
        n1++;n2=0;
    }
    input.close();int gg;

    if(x1>y1)
        gg=x1;
    else
        gg=y1;

    while(start>0) {
        string c;
        cout<<"Enter the word"<<endl;
        getline(cin,c);cout<<endl;
        int j1=c.size();

        if (j1<=gg){
            char b[gg];
            copyword(b,c,j1);
            int j=StringLen(b);
            int dr=0;int dd=0; int x;int y;int dl=0;int du=0;

            for (int k1=0;k1<x1;k1++)
                {
                    for(int k2=0;k2<y1;k2++)
                    {
                    if (a[k1][k2]==b[0])
                    {
                        for(int n3=1;n3<j;n3++)
                            {
                                if ((k1+n3)<x1-1||(k2+n3)<y1-1)
                                    {
                                        if (a[k1+n3][k2]==b[n3])
                                        dd=dd+1;
                                        if (a[k1][k2+n3]==b[n3])
                                        dr=dr+1;}

                                if ((k1-n3)>-1||(k1-n3)>-1)
                                    {
                                        if (a[k1-n3][k2]==b[n3])
                                        du=du+1;
                                        if (a[k1][k2-n3]==b[n3])
                                        dl=dl+1;}
                                    }
                    }

                if (dr==j-1||dd==j-1||du==j-1||dl==j-1)
                    {y=k2;break;}
                else
                    {dr=0;dd=0;}
            }
                if (dr==j-1||dd==j-1||du==j-1||dl==j-1)
                {x=k1;break;}
        }
        dispresult(dd,dr,dl,du,j,x,y); cout<<endl;}

        else
            {cout<<"The word does not exist"<<endl;cout<<endl;}

        char g;
        cout<<"Do you want to try again? y/n"<<endl;
        cin >>g; cout<<endl;
        getline(cin,c);
        if(g=='n'||g=='N')
            break;
    }
    cout<<"Thanks for playing"<<endl;
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

void dispresult(int dd,int dr,int dl,int du,int j,int x,int y){

        if (dd==j-1)
            cout<<"It is at "<<x<<","<<y<<" downwards"<<endl;
        else if (dr==j-1)
            cout<<"It is at "<<x<<","<<y<<" rightwards"<<endl;
        else if (dl==j-1)
            cout<<"It is at "<<x<<","<<y<<" leftwards"<<endl;
        else if (du==j-1)
            cout<<"It is at "<<x<<","<<y<<" upwards"<<endl;
        else
            cout<<"It does not exists"<<endl;
        cout <<endl;

}

void copyword(char b[], string c, int j1){
    for (int n=0;n<j1;n++)
    {
        b[n]=c[n];
    }
    b[j1]='\0';
}

int *dimensions()
{
    string b; int g[2];g[0]=0;g[1]=0;
    ifstream input;
    input.open("puzzle.txt");
    getline(input,b);
    g[1]++;
    int k =b.size();
    for (int l=0;l<k;l++)
    {   if(b[l]!=' '&&b[l]!='\0')
            {g[0]++;}
    }
    while(getline(input,b))
        {g[1]++;}
    input.close();
    int *p; p=g; return p;
}
