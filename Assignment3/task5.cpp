#include <iostream>
using namespace std;

void displayinstructions();
void initializes(char a[7][7]);
void printtable(char a[7][7]);
char checkturn(int *ch);
void checkvalid(char c,int b,char a[7][7],char k,int g, int *ch);
void checkfour(int win[],char a[7][7]);
void checkthree(int win1[],char a[7][7]);

int main()
{
    int game=1;
    while (game>0){
    displayinstructions();
    char a[7][7];
    initializes(a);
    printtable(a);
    int b; char c;
    int start=1; int g=0; int ch=0; int t1=0;char t2=0;
    int win[2]; int win1[2];
    win[0]=0;win[1]=0;win1[0]=0;win1[1]=0;
    while (start>0)
    {
        char k=checkturn(&ch);
        cin>>c>>b;
        cout<<endl;
        if(c!='x'){
            checkvalid(c,b,a,k,g,&ch);
            printtable(a);cout<<endl;}
        checkfour(win,a);
        checkthree(win1,a);
        g++;
        if(g==25||c=='x')
            start=0;
        if(win[0]==3||win1[0]==2)
        {
            cout<<"Player 1 Wins"<<endl;
            start=0;
        }
        if(win[1]==3||win1[1]==2)
        {
            cout<<"Player 2 Wins"<<endl;
            start=0;
        }
    }

    cout<<endl;
    char ag;
    cout<<"Do you want to play again?y/n"<<endl;
    cin>>ag;
    cout<<endl;

    if (ag=='n'||ag=='N')
        break;
    }
    cout<<"Thanks for playing.  Exiting..."<<endl;
}

void displayinstructions()
{
    cout <<"Welcome to TicTacMore"<<endl
        <<"Author: Faizan"<<endl
        <<"CS 200, program #4.  Written in C++ on Mars Server."<<endl
        <<endl
        <<"The object of the game is to get either 4 in a row or"<<endl
        <<"3 in a row on any edge.  Player X starts and play alternates "<<endl
        <<"until someone wins or the board is full.  You may only move "<<endl
        <<"in a square adjacent to a piece already played."<<endl
        <<endl;
}

void initializes(char a[7][7])
{
    a[0][0]=' ';a[0][6]=' ';a[6][0]=' ';a[6][6]=' ';

    for (int n=1;n<6;n++)
        a[0][n]=n+48;
    for (int n=1;n<6;n++)
        a[6][n]=n+48;
    for (int n=1;n<6;n++)
        a[n][0]=n+64;
    for (int n=1;n<6;n++)
        a[n][6]=n+64;

    for (int n=1;n<6;n++)
    {
        for(int n1=1;n1<6;n1++)
            a[n][n1]='.';
    }
}

void printtable(char a[7][7])
  {
    for (int n=0;n<7;n++)
    {
        for(int n1=0;n1<7;n1++)
            cout<<a[n][n1]<<" ";
        cout<<endl;
    }
  }
char checkturn(int *ch){

    char k;
    if (*ch==0)
        {
            cout<<"Player one's turn"<<endl;
            cout<<"Enter where you want to place O"<<endl;
            *ch=1;k='O';
        }
        else if (*ch==1)
        {
            cout<<"Player two's turn"<<endl;
            cout<<"Enter where you want to place X"<<endl;
            *ch=0;k='X';
        }
    return k;
}

void checkvalid(char c,int b,char a[7][7],char k,int g, int *ch){

        int c1=c;
        int c2=!(a[c1-64][b+1]!='.'||a[c1-64][b-1]!='.'||a[c1-63][b]!='.'||a[c1-65][b]!='.'||a[c1-63][b+1]!='.'||a[c1-65][b+1]!='.'||a[c1-63][b-1]!='.'||a[c1-65][b-1]!='.');
        int c3=!(a[c1-64][b+1]!='.'||a[c1-64][b-1]!='.'||a[c1-63][b]!='.'||a[c1-63][b-1]!='.'||a[c1-63][b+1]!='.');
        int c4=!(a[c1-64][b+1]!='.'||a[c1-64][b-1]!='.'||a[c1-65][b]!='.'||a[c1-65][b+1]!='.'||a[c1-65][b-1]!='.');
        int c5=(a[c1-64][b+1]=='.'&&a[c1-63][b]=='.'&&a[c1-65][b]=='.'&&a[c1-63][b+1]=='.'&&a[c1-65][b+1]=='.');
        int c6=!(a[c1-64][b-1]!='.'||a[c1-63][b]!='.'||a[c1-65][b]!='.'||a[c1-63][b-1]!='.'||a[c1-65][b-1]!='.');
        int c7=(c1==65&&b==1)&&(a[c1-64][b+1]=='.'&&a[c1-63][b]=='.'&&a[c1-63][b+1]=='.');
        int c8=(c1==65&&b==5)&&(a[c1-64][b-1]=='.'&&a[c1-63][b]=='.'&&a[c1-63][b-1]=='.');
        int c9=(c1==69&&b==1)&&(a[c1-65][b]=='.'&&a[c1-64][b+1]=='.'&&a[c1-65][b+1]=='.');
        int c10=(c1==69&&b==5)&&(a[c1-65][b]=='.'&&a[c1-64][b-1]=='.'&&a[c1-65][b-1]=='.');

        if (a[c1-64][b]=='.'){
            if (((b>5||b<1||c>69||c<65)||(((c1>=66&&c1<=68)&&(b>=2&&b<=4))&&c2==1)||((c1==65&&(b>=2&&b<=4))&&(c3==1))||((c1==69&&(b>=2&&b<=4))&&(c4==1))||(((c1>=66&&c1<=68)&&b==1)&&c5==1)||(((c1>=66&&c1<=68)&&b==5)&&c6==1)||c7==1||c8==1||c9==1||c10==1)&& g!=0 )
            {
                cout<<"Invalid move Try Again!"<<endl;
                if (*ch==1)
                    *ch=0;
                else
                    *ch=1;
            }
            else
            {
                int m=c;

                if (*ch==1)
                    a[m-64][b]=k;
                else
                    a[m-64][b]=k;
            }}
        else
        {   cout<<"Invalid move Try Again!"<<endl;
                if (*ch==1)
                    *ch=0;
                else
                    *ch=1;}
}

void checkfour(int win[], char a[7][7]){

    for (int n4=2;n4<5;n4++)
        {
            for(int n1=2;n1<3;n1++)
                {
                    if (a[n4][n1]=='O')
                    {
                    for (int n2=1;n2<4;n2++)
                        {

                            if (n1+n2>5)
                            {win[0]=0;
                                break;}
                            if (a[n4][n1+n2]=='O')
                                win[0]++;
                        }
                    }
                    if (a[n4][n1]=='X')
                    {
                        for (int n2=1;n2<4;n2++)
                        {
                            if (n1+n2>5)
                            {win[1]=0;
                                break;}
                            if (a[n4][n1+n2]=='X')
                                win[1]++;

                        }

                    }
                if (win[0]==3)
                    break;
                else
                    win[0]=0;
                if (win[1]==3)
                    break;
                else
                    win[1]=0;
            }
        }
}

void checkthree(int win1[],char a[7][7]){

    for (int n4=1;n4<6;n4++)
        {
            if (n4==1||n4==5){
            for(int n1=1;n1<6;n1++)
                {
                    if (a[n4][n1]=='O')
                    {
                    for (int n2=1;n2<4;n2++)
                        {

                            if (n1+n2>5)
                            {win1[0]=0;
                                break;}
                            if (a[n4][n1+n2]=='O')
                                win1[0]++;
                        }
                    }
                    if (a[n4][n1]=='X')
                    {
                        for (int n2=1;n2<4;n2++)
                        {
                            if (n1+n2>5)
                            {win1[1]=0;
                                break;}
                            if (a[n4][n1+n2]=='X')
                                win1[1]++;

                        }

                    }
                if (win1[0]==2)
                    break;
                else
                    win1[0]=0;
                if (win1[1]==2)
                    break;
                else
                    win1[1]=0;
            }}
            else
            {
                for(int n1=1;n1<6;n1++)
                {
                    if (n1!=2){
                    if (a[n4][n1]=='O')
                    {
                    for (int n2=1;n2<4;n2++)
                        {

                            if (n1+n2>5)
                            {win1[0]=0;
                                break;}
                            if (a[n4][n1+n2]=='O')
                                win1[0]++;
                        }
                    }
                    if (a[n4][n1]=='X')
                    {
                        for (int n2=1;n2<4;n2++)
                        {
                            if (n1+n2>5)
                            {win1[1]=0;
                                break;}
                            if (a[n4][n1+n2]=='X')
                                win1[1]++;

                        }

                    }
                if (win1[0]==2)
                    break;
                else
                    win1[0]=0;
                if (win1[1]==2)
                    break;
                else
                    win1[1]=0;
            }}
        }
}
}
