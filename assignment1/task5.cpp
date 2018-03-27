#include <iostream>

using namespace std;

int main()
{
    int start=1;

    while (start>0)
    {
        int a,b;
        char c,d,e,f;

        cout<<"Which piece do you want to move [B]ishop, [K]ing, [K]night, [R]ook,[Q]ueen,[P]awn"<<endl;
        cin>>c;
        cout<<"Give the initial position"<<endl;
        cin>>d>>a;
        cout<<"Give the final position"<<endl;
        cin>>e>>b;

        int n=1;
        int intd=d;
        int inte=e;
        int intc=c;

        cout<<endl;

        if (intc==75)
            {
                cout<<"King or Knight? Press I for king and K again for Knight"<<endl;
                cin>>c;
                cout<<endl;
                intc=c;
            }

        if (a>9 || a<1 || b>9 || b<1 || intd>104 || intd<97 || inte>104 || inte<97 || (intd==inte && a==b))
            {
                cout<<"Illegal move"<<endl; n=0;
            }

        if ((intc==80 && n>0))
        {
            cout<<"You have selected Pawn"<<endl;
            cout << "You want to move it from "<<d<<a<<" to "<<e<<b<<endl;

            if (intd==inte && b==a+1)
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Illegal Move"<<endl;
        }

        if (intc==73 && n>0)

        {
                cout<<"You have selected King"<<endl;
                cout << "You want to move it from "<<d<<a<<" to "<<e<<b<<endl;

                if ((intd==inte && b==a+1) || (intd==inte && b==a-1)||(inte==intd+1 && b==a)||(inte==intd-1 && b==a)||(inte==intd+1 && b==a+1)||(inte==intd-1 && b==a-1)||(inte==intd+1 && b==a-1)||(inte==intd-1 && b==a+1))
                    cout<<"Its a legal move"<<endl;
                else
                    cout<<"Illegal Move"<<endl;
        }

        if (intc==82 && n>0)

        {
            cout<<"You have selected Rook"<<endl;
            cout << "You want to move it from "<<d<<a<<" to "<<e<<b<<endl;

            if ((intd==inte && b<8)||(inte<104 && b==a))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Illegal Move"<<endl;
        }

        if (intc==66 && n>0)

        {
            cout<<"You have selected Bishop"<<endl;
            cout << "You want to move it from "<<d<<a<<" to "<<e<<b<<endl;

            if ((inte-intd)==(b-a))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Illegal Move"<<endl;
        }

        if (intc==81 && n>0)

        {
            cout<<"You have selected Queen"<<endl;
            cout << "You want to move it from "<<d<<a<<" to "<<e<<b<<endl;

            if  ((inte-intd)==(b-a)||(intd==inte && b<8)||(inte<104 && b==a))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Illegal Move"<<endl;
        }

        if (intc==75 && n>0)

        {
            cout<<"You have selected Knight"<<endl;
            cout << "You want to move it from "<<d<<a<<" to "<<e<<b<<endl;

            if ((inte==intd+1 && b==a+2) || (inte==intd-1 && b==a+2)||(inte==intd+1 && b==a-2)||(inte==intd-1 && b==a-2)||(inte==intd+2 && b==a+1)||(inte==intd+2 && b==a-1)||(inte==intd-2 && b==a+1)||(inte==intd-2 && b==a-1))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Illegal Move"<<endl;
        }

        cout<<endl;

        char i;
        cout<<"Do you want to try again? y/n"<<endl;
        cin>>i;
        cout<<endl;
        int inti=i;

        if (inti==121)
            start=1;
        else if (inti==110)
            start=0;
    }
}

