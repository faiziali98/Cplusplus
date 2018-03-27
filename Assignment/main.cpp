#include <iostream>

using namespace std;

int main()
{
        int a,b;
        char c,d,e,f;

        // Will use N for knight
        cout<<"Select one: [B]ishop,k[N]ight, [K]ing,[R]ook, [P]awn,[Q]ueen"<<endl;
        cin>>c;
        cout<<"Give the initial position"<<endl;
        cin>>d>>a;
        cout<<"Give the final position"<<endl;
        cin>>e>>b;

        // This code Will convert characters into ASCII
        int n=1;
        int dn=d;
        int en=e;

        // This will check if positions are inside the chess boared
        if (a>9 || a<1 || b>9 || b<1 || dn>104 || dn<97 || en>104 || en<97 || (dn==en && a==b))
            {
                cout<<"Its a Illegal Move"<<endl; n=0;
            }

        if ((c=='P' && n>0))
        {
            cout<<"You have selected Pawn"<<endl;

            if (dn==en && b==a+1)
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Its a Illegal Move"<<endl;
        }

        if (c=='K' && n>0)

        {
                cout<<"You have selected King"<<endl;

                if ((dn==en && b==a+1) || (dn==en && b==a-1)||(en==dn+1 && b==a)||(en==dn-1 && b==a)||(en==dn+1 && b==a+1)||(en==dn-1 && b==a-1)||(en==dn+1 && b==a-1)||(en==dn-1 && b==a+1))
                    cout<<"Its a legal move"<<endl;
                else
                    cout<<"Its a Illegal Move"<<endl;
        }

        if (c=='R' && n>0)

        {
            cout<<"You have selected Rook"<<endl;

            if ((dn==en && b<8)||(en<104 && b==a))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Its a Illegal Move"<<endl;
        }

        if (c=='B' && n>0)

        {
            cout<<"You have selected Bishop"<<endl;

            if ((en-dn)==(b-a))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Its a Illegal Move"<<endl;
        }

        if (c=='Q' && n>0)

        {
            cout<<"You have selected Queen"<<endl;

            if  ((en-dn)==(b-a)||(dn==en && b<8)||(en<104 && b==a))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Its a Illegal Move"<<endl;
        }

        if (c=='N' && n>0)

        {
            cout<<"You have selected Knight"<<endl;

            if ((en==dn+1 && b==a+2) || (en==dn-1 && b==a+2)||(en==dn+1 && b==a-2)||(en==dn-1 && b==a-2)||(en==dn+2 && b==a+1)||(en==dn+2 && b==a-1)||(en==dn-2 && b==a+1)||(en==dn-2 && b==a-1))
                cout<<"Its a legal move"<<endl;
            else
                cout<<"Its a Illegal Move"<<endl;
        }

        cout<<endl;
}
