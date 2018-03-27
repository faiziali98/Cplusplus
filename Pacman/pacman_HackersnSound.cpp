#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;

    input.open("high.txt");
    //Initialization:

    int s=0;
    int start=1;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    int food=0;
    int high1=0;
    input >> high1;
    mvprintw(0,21,"High Score = %d",high1);
    //Making Food:

    int r;
    int c;
    getmaxyx(stdscr,r,c);
    string score[r][c];

    for (int j=2;j<24;j++)
        {
          for(int k=1;k<c-1;k++)
                {
                  score[j][k]=".";
                  mvprintw(j,k,".");
                  food=food+1;
                }
        }
        mvprintw(3,5,"S");mvprintw(3,74,"S");mvprintw(21,5,"S");mvprintw(21,74,"S");
        score[3][5]="S";score[3][74]="S";score[21][5]="S";score[21][74]="S";
        start_color();
        init_pair(1,COLOR_BLACK,COLOR_BLUE);
        attron(COLOR_PAIR(1));
        //Maze Part I:
        for(int k1=10;k1<71;k1++)
                {int j1=5;score[j1][k1]="I";mvprintw(j1,k1,"I");food=food-1;}
        for(int k1=10;k1<31;k1++)
                {int j1=11;score[j1][k1]="I";mvprintw(j1,k1,"I");food=food-1;}
        for(int k1=50;k1<71;k1++)
                {int j1=11;score[j1][k1]="I";mvprintw(j1,k1,"I");food=food-1;}
        for(int k1=5;k1<12;k1++)
                {int j1=10;score[k1][j1]="I";mvprintw(k1,j1,"I");food=food-1;}
        for(int k1=5;k1<12;k1++)
                {int j1=70;score[k1][j1]="I";mvprintw(k1,j1,"I");food=food-1;}

        //Maze Part II:
        for(int k1=10;k1<71;k1++)
                {int j1=20;score[j1][k1]="I";mvprintw(j1,k1,"I");food=food-1;}
        for(int k1=10;k1<31;k1++)
                {int j1=14;score[j1][k1]="I";mvprintw(j1,k1,"I");food=food-1;}
        for(int k1=50;k1<71;k1++)
                {int j1=14;score[j1][k1]="I";mvprintw(j1,k1,"I");food=food-1;}
        for(int k1=14;k1<21;k1++)
                {int j1=10;score[k1][j1]="I";mvprintw(k1,j1,"I");food=food-1;}
        for(int k1=14;k1<21;k1++)
                {int j1=70;score[k1][j1]="I";mvprintw(k1,j1,"I");food=food-1;}

        for(int k1=1;k1<25;k1++)
                {int j1=0;mvprintw(k1,j1,"|");}
        for(int k1=1;k1<25;k1++)
                {int j1=79;mvprintw(k1,j1,"|");}
        for(int k1=0;k1<80;k1++)
                {int j1=24;mvprintw(j1,k1,"|");}
        for(int k1=0;k1<80;k1++)
                {int j1=1;mvprintw(j1,k1,"|");}

    attroff(COLOR_PAIR(1));
    mvprintw(0,60,"Press 'e' to exit"); mvprintw(0,1,"Score = %d",s);  mvprintw(0,45,"Ghost = G");

    //Making Pacman And Ghost:

    int p1=r/2;
    int p2=c/2;
    int p=0;

    srand (time(NULL));
    int pg[3][2];
    getch();int z1;int z2;


    for (int x=0;x<3;x++)
    {
        pg[x][0]=1;pg[x][1]=1;
    }

    for (int x=0;x<3;x++)
    {
        pg[x][0]=rand() % 21 + 2;pg[x][1]=rand() % 77 + 1;

        if ((pg[x][0]==14 ||pg[x][0]==11||pg[x][0]==5||pg[x][0]==20) && (pg[x][1]>=11 && pg[x][1]<=69))
            {
                int l=rand()%2;
                if (l==1)
                    pg[x][0]=pg[x][0]+1;
                else
                    pg[x][0]=pg[x][0]-1;
            }

            if ((pg[x][1]==10||pg[x][1]==70) && ((pg[x][0]>=6 && pg[x][0]<=10)||(pg[x][0]>=15 && pg[x][0]<=19)))
            {
                int l=rand()%2;
                if (l==1)
                    pg[x][1]=pg[x][1]+1;
                else
                    pg[x][1]=pg[x][1]-1;
            }

            z1=((pg[x][0]==5 && pg[x][1]==10)||(pg[x][0]==20 && pg[x][1]==10)||(pg[x][0]==11 && pg[x][1]==10)||(pg[x][0]==14 && pg[x][1]==10));
            z2=((pg[x][0]==5 && pg[x][1]==70)||(pg[x][0]==20 && pg[x][1]==70)||(pg[x][0]==11 && pg[x][1]==70)||(pg[x][0]==14 && pg[x][1]==70));

            if(z1==1)
                pg[x][1]=pg[x][1]-1;
            if (z2==1)
                pg[x][1]=pg[x][1]+1;

            mvprintw(pg[x][0],pg[x][1],"G");

    }

    mvprintw(p1,p2,"<");
    int dx;int c1;int k1;
    int dy;int c2;int k2;
    int w;int d=0;int q=0;
    int v;
    init_pair(3,COLOR_RED,COLOR_BLACK);
    init_pair(4,COLOR_BLUE,COLOR_BLACK);
    init_pair(5,COLOR_GREEN,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    //Moving Pacman:
    while(start>0)
    {

        wtimeout(stdscr,100);
        init_pair(2,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(2));

        int ch=getch();

        if (ch=='e')
            w=0;
        else if(ch==KEY_UP)
            w=1;
        else if(ch==KEY_DOWN)
            w=2;
        else if(ch==KEY_RIGHT)
            w=3;
        else if(ch==KEY_LEFT)
            w=4;

        switch(w)
        {

            case 3:
                mvprintw(p1,p2," ");
                p2=p2+1;
                p=p+1;

                for (int x=0;x<3;x++)
                    {if ((p1==pg[x][0] && p2==pg[x][1])&&(d==0))
                        start=0;
                     else if ((p1==pg[x][0] && p2==pg[x][1])&&(d==1))
                        {pg[x][0]=r/2;pg[x][1]=c/2;mvprintw(pg[x][0],pg[x][1],"G");PlaySound(TEXT("eg.wav"),NULL,SND_SYNC);}}

                if ((p1==5 && p2==10)||(p2==10 && (p1>=5 && p1<=11))||(p2==70 && (p1>=5 && p1<=11))||(p1==11 && p2==50))
                    p2=p2-1;
                if ((p1==20 && p2==10)||(p2==10 && (p1>=14 && p1<=20))||(p2==70 && (p1>=14 && p1<=20))||(p1==14 && p2==50))
                    p2=p2-1;

                if (mvinch(p1,p2)=='S')
                {
                        d=1;PlaySound(TEXT("ef.wav"),NULL,SND_SYNC);
                }

                if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,1,"Score = %d",s);}

                if (p>1)
                    p=0;

                if (p2>=c-1)
                    p2=c-2;

                if (p==0 && start!=0)
                    mvprintw(p1,p2,"<");
                else if (p==1&&start!=0)
                    mvprintw(p1,p2,"O");
                break;

            case 4:
                mvprintw(p1,p2," ");
                p2=p2-1;
                p=p+1;

                for (int x=0;x<3;x++)
                    {if ((p1==pg[x][0] && p2==pg[x][1])&&(d==0))
                        start=0;
                     else if ((p1==pg[x][0] && p2==pg[x][1])&&(d==1))
                        {pg[x][0]=r/2;pg[x][1]=c/2;mvprintw(pg[x][0],pg[x][1],"G");PlaySound(TEXT("eg.wav"),NULL,SND_SYNC);}}

                if ((p1==5 && p2==70)||(p2==10 && (p1>=5 && p1<=11))||(p2==70 && (p1>=5 && p1<=11))||(p1==11 && p2==30))
                    p2=p2+1;
                if ((p1==20 && p2==70)||(p2==10 && (p1>=14 && p1<=20))||(p2==70 && (p1>=14 && p1<=20))||(p1==14 && p2==30))
                    p2=p2+1;

                if (mvinch(p1,p2)=='S')
                {
                        d=1;PlaySound(TEXT("ef.wav"),NULL,SND_SYNC);
                }

                if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,1,"Score = %d",s);}

                if (p>1)
                    p=0;

                if (p2<=1)
                    p2=1;


                if (p==0&&start!=0)
                    mvprintw(p1,p2,">");
                else if (p==1&&start!=0)
                    mvprintw(p1,p2,"O");
                break;

           case 1:
               mvprintw(p1,p2," ");
               p1=p1-1;
               p=p+1;

               for (int x=0;x<3;x++)
                    {if ((p1==pg[x][0] && p2==pg[x][1])&&(d==0))
                        start=0;
                     else if ((p1==pg[x][0] && p2==pg[x][1])&&(d==1))
                        {pg[x][0]=r/2;pg[x][1]=c/2;mvprintw(pg[x][0],pg[x][1],"G");PlaySound(TEXT("eg.wav"),NULL,SND_SYNC);}}

               if ((p1==11 && (p2>=10 && p2<=30))||(p1==5 && (p2>=10 && p2<=70))||(p1==11 && (p2>=50 && p2<=70)))
                    p1=p1+1;
                if ((p1==14 && (p2>=10 && p2<=30))||(p1==20 && (p2>=10 && p2<=70))||(p1==14 && (p2>=50 && p2<=70)))
                    p1=p1+1;

                if (mvinch(p1,p2)=='S')
                {
                        d=1;PlaySound(TEXT("ef.wav"),NULL,SND_SYNC);
                }

               if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,1,"Score = %d",s);}

               if (p>1)
                    p=0;

               if (p1<=2)
                   p1=2;


               if (p==0&&start!=0)
                    mvprintw(p1,p2,"V");
               else if (p==1&&start!=0)
                    mvprintw(p1,p2,"O");

               break;

           case 2:
               mvprintw(p1,p2," ");
               p1=p1+1;
               p=p+1;

               for (int x=0;x<3;x++)
                    {if ((p1==pg[x][0] && p2==pg[x][1])&&(d==0))
                        start=0;
                     else if ((p1==pg[x][0] && p2==pg[x][1])&&(d==1))
                        {pg[x][0]=r/2;pg[x][1]=c/2;mvprintw(pg[x][0],pg[x][1],"G");PlaySound(TEXT("eg.wav"),NULL,SND_SYNC);}}

               if ((p1==11 && (p2>=10 && p2<=30))||(p1==5 && (p2>=10 && p2<=70))||(p1==11 && (p2>=50 && p2<=70)))
                    p1=p1-1;
                if ((p1==14 && (p2>=10 && p2<=30))||(p1==20 && (p2>=10 && p2<=70))||(p1==14 && (p2>=50 && p2<=70)))
                    p1=p1-1;

                if (mvinch(p1,p2)=='S')
                {
                        d=1;PlaySound(TEXT("ef.wav"),NULL,SND_SYNC);
                }

               if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,1,"Score = %d",s);}

               if (p>1)
                    p=0;

               if (p1>=23)
                   p1=23;


               if (p==0 && start!=0)
                    mvprintw(p1,p2,"^");
               else if (p==1 && start!=0)
                    mvprintw(p1,p2,"O");
               break;

            case 0:
                start=0;
                break;

        }
        attroff(COLOR_PAIR(2));

        if (s==food)
            start=0;


       PlaySound((LPCSTR)("c.wav"),NULL,SND_FILENAME | SND_ASYNC);

        if (d==1)
            q++;
        if(q%15==0)
        {   d=0;
            q=0; mvprintw(0,18," "); }
        mvprintw(0,12," t = %d",q);

        // Ghost moment:
        for (int x=0;x<3;x++)
        {
        dx=p1-pg[x][0];
        dy=p2-pg[x][1];

        if (score[pg[x][0]][pg[x][1]]==".")
            mvprintw(pg[x][0],pg[x][1],".");
        else if (score[pg[x][0]][pg[x][1]]==" ")
            mvprintw(pg[x][0],pg[x][1]," ");
        else if (score[pg[x][0]][pg[x][1]]=="S")
            mvprintw(pg[x][0],pg[x][1],"S");

        if (fabs(dx)>fabs(dy)|| dy==0)
            {
                pg[x][0]=pg[x][0]+(dx/(fabs(dx)));
                if (((pg[x][0]==5||pg[x][0]==20)&&(pg[x][1]>=10 && pg[x][1]<=70))|| ((pg[x][0]==14 ||pg[x][0]==11)&&(pg[x][1]>=10 && pg[x][1]<=30))||((pg[x][0]==14 ||pg[x][0]==11)&&(pg[x][1]>=50 && pg[x][1]<=70)))
                {
                    if (pg[x][0]<p1)
                          {
                            pg[x][0]=pg[x][0]-1;

                            c1=((pg[x][0]!=6 || pg[x][1]!=11)&&(pg[x][0]!=6 || pg[x][1]!=69)&&(pg[x][0]!=19 || pg[x][1]!=11)&&(pg[x][0]!=19 || pg[x][1]!=69));
                            c2=((pg[x][0]!=10 || pg[x][1]!=11)&&(pg[x][0]!=10 || pg[x][1]!=69)&&(pg[x][0]!=15 || pg[x][1]!=11)&&(pg[x][0]!=15 || pg[x][1]!=69));

                            if (fabs(dy)>0 && (c1==1 && c2==1))
                               pg[x][1]=pg[x][1]+(dy/(fabs(dy)));
                        }
                    else if (pg[x][0]>p1)
                        {
                            pg[x][0]=pg[x][0]+1;

                            c1=((pg[x][0]!=6 || pg[x][1]!=11)&&(pg[x][0]!=6 || pg[x][1]!=69)&&(pg[x][0]!=19 || pg[x][1]!=11)&&(pg[x][0]!=19 || pg[x][1]!=69));
                            c2=((pg[x][0]!=10 || pg[x][1]!=11)&&(pg[x][0]!=10 || pg[x][1]!=69)&&(pg[x][0]!=15 || pg[x][1]!=11)&&(pg[x][0]!=15 || pg[x][1]!=69));

                            if (fabs(dy)>0 && (c1==1 && c2==1))
                               pg[x][1]=pg[x][1]+(dy/(fabs(dy)));
                        }
                    else if (pg[x][0]-p1==0)
                        {
                            if (w==1)
                                pg[x][0]=pg[x][0]+1;
                            else if (w==2)
                                pg[x][0]=pg[x][0]-1;
                        }

             }
            }
        else
            {
                pg[x][1]=pg[x][1]+(dy/(fabs(dy)));

                k1=((pg[x][1]==10||pg[x][1]==70) && ((pg[x][0]>=5 && pg[x][0]<=11)||(pg[x][0]>=14 && pg[x][0]<=20)));
                k2=((pg[x][0]==11 && pg[x][1]==30)||(pg[x][0]==11 && pg[x][1]==50)||(pg[x][0]==14 && pg[x][1]==30)||(pg[x][0]==14 && pg[x][1]==50));

                if (k1==1||k2==1)
                {
                    if (pg[x][1]<p2)
                        {
                            pg[x][1]=pg[x][1]-1;

                            c1=((pg[x][0]!=6 || pg[x][1]!=11)&&(pg[x][0]!=6 || pg[x][1]!=69)&&(pg[x][0]!=19 || pg[x][1]!=11)&&(pg[x][0]!=19 || pg[x][1]!=69));
                            c2=((pg[x][0]!=10 || pg[x][1]!=11)&&(pg[x][0]!=10 || pg[x][1]!=69)&&(pg[x][0]!=15 || pg[x][1]!=11)&&(pg[x][0]!=15 || pg[x][1]!=69));

                            if (fabs(dx)>0 && (c1==1 && c2==1))
                                pg[x][0]=pg[x][0]+(dx/(fabs(dx)));
                        }
                    else if (pg[x][1]>p2)
                        {
                            pg[x][1]=pg[x][1]+1;

                            c1=((pg[x][0]!=6 || pg[x][1]!=11)&&(pg[x][0]!=6 || pg[x][1]!=69)&&(pg[x][0]!=19 || pg[x][1]!=11)&&(pg[x][0]!=19 || pg[x][1]!=69));
                            c2=((pg[x][0]!=10 || pg[x][1]!=11)&&(pg[x][0]!=10 || pg[x][1]!=69)&&(pg[x][0]!=15 || pg[x][1]!=11)&&(pg[x][0]!=15 || pg[x][1]!=69));

                            if (fabs(dx)>0 && (c1==1 && c2==1))
                                pg[x][0]=pg[x][0]+(dx/(fabs(dx)));
                        }
                    else if (pg[x][1]-p2==0)
                    {
                        if (w==3)
                            pg[x][1]=pg[x][1]-1;
                        else if (w==4)
                            pg[x][1]=pg[x][1]+1;
                    }
                }
            }

        if ((p1==pg[x][0] && p2==pg[x][1])&&(d==1))
                {pg[x][0]=r/2;pg[x][1]=c/2;PlaySound(TEXT("eg.wav"),NULL,SND_SYNC);}

        for (int k=0;k<3;k++)
        {
            if (k!=x && (pg[x][0]==pg[k][0]&&pg[x][1]==pg[k][1]))
                {
                    if (fabs(dx)>fabs(dy))
                        pg[x][0]=pg[x][0]-(dx/fabs(dx));
                    else
                        pg[x][1]=pg[x][1]-(dy/fabs(dy));
                }
            }

            if (d==0)
                v=x+3;
            else if (d==1)
                v=6;

            attron(COLOR_PAIR(v));
            mvprintw(pg[x][0],pg[x][1],"G");
            attroff(COLOR_PAIR(v));
        }

        for (int x=0;x<3;x++)
            {if ((p1==pg[x][0] && p2==pg[x][1])&&(d==0))
                start=0;}
        if (start==0&&s>high1)
        {output.open("high.txt");
        high1=s;
        output<<high1;
        output.close();}
    }
    mvprintw(0,30,"Game Over Press any key");
    PlaySound(TEXT("d.wav"),NULL,SND_SYNC);
    getch();
    endwin();
}
