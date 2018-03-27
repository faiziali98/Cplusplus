#include <curses.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;

    input.open("high.txt");
    //Initialization:

    wtimeout(stdscr,1);
    int s=0;
    int start=1;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    int food=0;
    int high1=0;
    input >> high1;
    mvprintw(0,25,"High Score = %d",high1);
    //Making Food:

    int r;
    int c;
    getmaxyx(stdscr,r,c);
    string score[r][c];

    for (int j=1;j<r;j++)
        {
          for(int k=0;k<c;k++)
                {
                  score[j][k]=".";
                  mvprintw(j,k,".");
                  food=food+1;

                }
        }

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
    mvprintw(0,60,"Press 'e' to exit"); mvprintw(0,10,"Score = %d",s);  mvprintw(0,45,"Ghost = G");

    //Making Pacman:

    int p1=r/2;
    int p2=c/2;
    int p=0;

    srand (time(NULL));
    int pg[3][2];int c1;int c2;

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

            c1=((pg[x][0]==5 && pg[x][1]==10)||(pg[x][0]==20 && pg[x][1]==10)||(pg[x][0]==11 && pg[x][1]==10)||(pg[x][0]==14 && pg[x][1]==10));
            c2=((pg[x][0]==5 && pg[x][1]==70)||(pg[x][0]==20 && pg[x][1]==70)||(pg[x][0]==11 && pg[x][1]==70)||(pg[x][0]==14 && pg[x][1]==70));

            if(c1==1)
                pg[x][1]=pg[x][1]-1;
            if (c2==1)
                pg[x][1]=pg[x][1]+1;

        if (x==0)
                init_pair(3,COLOR_RED,COLOR_BLACK);
        else if (x==1)
                init_pair(4,COLOR_BLUE,COLOR_BLACK);
        else if (x==2)
                init_pair(5,COLOR_GREEN,COLOR_BLACK);

        attron(COLOR_PAIR(x+3));
        mvprintw(pg[x][0],pg[x][1],"G");
        attroff(COLOR_PAIR(x+3));
    }



    mvprintw(p1,p2,"<");
    int h=0;
    int w=3;
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

                if ((p1==5 && p2==10)||(p2==10 && (p1>=5 && p1<=11))||(p2==70 && (p1>=5 && p1<=11))||(p1==11 && p2==50))
                    p2=p2-1;
                if ((p1==20 && p2==10)||(p2==10 && (p1>=14 && p1<=20))||(p2==70 && (p1>=14 && p1<=20))||(p1==14 && p2==50))
                    p2=p2-1;

                if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,10,"Score = %d",s);}

                if (p>1)
                    p=0;

                if (p2>=c-1)
                    p2=c-2;

                if (p==0)
                    mvprintw(p1,p2,"<");
                else if (p==1)
                    mvprintw(p1,p2,"O");

            case 4:

                mvprintw(p1,p2," ");
                p2=p2-1;
                p=p+1;

                if ((p1==5 && p2==70)||(p2==10 && (p1>=5 && p1<=11))||(p2==70 && (p1>=5 && p1<=11))||(p1==11 && p2==30))
                    p2=p2+1;
                if ((p1==20 && p2==70)||(p2==10 && (p1>=14 && p1<=20))||(p2==70 && (p1>=14 && p1<=20))||(p1==14 && p2==30))
                    p2=p2+1;

                if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,10,"Score = %d",s);}

                if (p>1)
                    p=0;

                if (p2<=1)
                    p2=1;

                if (p==0)
                    mvprintw(p1,p2,">");
                else if (p==1)
                    mvprintw(p1,p2,"O");

           case 1:
               mvprintw(p1,p2," ");
               p1=p1-1;
               p=p+1;

               if ((p1==11 && (p2>=10 && p2<=30))||(p1==5 && (p2>=10 && p2<=70))||(p1==11 && (p2>=50 && p2<=70)))
                    p1=p1+1;
                if ((p1==14 && (p2>=10 && p2<=30))||(p1==20 && (p2>=10 && p2<=70))||(p1==14 && (p2>=50 && p2<=70)))
                    p1=p1+1;

               if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,10,"Score = %d",s);}

               if (p>1)
                    p=0;

               if (p1<=2)
                   p1=2;

               if (p==0)
                    mvprintw(p1,p2,"V");
               else if (p==1)
                    mvprintw(p1,p2,"O");
           case 2:

               mvprintw(p1,p2," ");
               p1=p1+1;
               p=p+1;

               if ((p1==11 && (p2>=10 && p2<=30))||(p1==5 && (p2>=10 && p2<=70))||(p1==11 && (p2>=50 && p2<=70)))
                    p1=p1-1;
                if ((p1==14 && (p2>=10 && p2<=30))||(p1==20 && (p2>=10 && p2<=70))||(p1==14 && (p2>=50 && p2<=70)))
                    p1=p1-1;

               if (score[p1][p2]==".")
                    {s=s+1;
                     score[p1][p2]=" ";
                     mvprintw(0,10,"Score = %d",s);}

               if (p>1)
                    p=0;

               if (p1>=23)
                   p1=23;

               if (p==0)
                    mvprintw(p1,p2,"^");
               else if (p==1)
                    mvprintw(p1,p2,"O");
               break;

            case 0:
                start=0;

        }
        attroff(COLOR_PAIR(2));

        if (s==food)
            start=0;

        for (int x=0;x<3;x++)
            if (p1==pg[x][0]&& p2==pg[x][1])
                start=0;

        h=h+1;


        if (h%10==0)
        {
            for (int x=0;x<3;x++)
                {
                    if (score[pg[x][0]][pg[x][1]]==".")
                        mvprintw(pg[x][0],pg[x][1],".");
                    else
                        mvprintw(pg[x][0],pg[x][1]," ");
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

            c1=((pg[x][0]==5 && pg[x][1]==10)||(pg[x][0]==20 && pg[x][1]==10)||(pg[x][0]==11 && pg[x][1]==10)||(pg[x][0]==14 && pg[x][1]==10));
            c2=((pg[x][0]==5 && pg[x][1]==70)||(pg[x][0]==20 && pg[x][1]==70)||(pg[x][0]==11 && pg[x][1]==70)||(pg[x][0]==14 && pg[x][1]==70));

            if(c1==1)
                pg[x][1]=pg[x][1]-1;
            if (c2==1)
                pg[x][1]=pg[x][1]+1;

            if (x==0)
                init_pair(3,COLOR_RED,COLOR_BLACK);
            else if (x==1)
                init_pair(4,COLOR_BLUE,COLOR_BLACK);
            else if (x==2)
                init_pair(5,COLOR_GREEN,COLOR_BLACK);

            attron(COLOR_PAIR(x+3));
            mvprintw(pg[x][0],pg[x][1],"G");
            attroff(COLOR_PAIR(x+3));

            }
            h=0;
        }

        if (start==0&&s>high1)
        {output.open("high.txt");
        high1=s;
        output<<high1;
        output.close();}

    }

    mvprintw(0,30,"Game Over Press any key");
    getch();


    endwin();

}


