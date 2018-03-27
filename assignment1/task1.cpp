#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout << "Enter the price of the item" << endl;
    cin >>a;
    cout << "Enter the quantity of the item" << endl;
    cin>>b;

    int total=0;
    int k=1;

    while (k>0)
        {
            total=total+(a*b);

            cout<<"Enter 0 to exit and 1 to continue"<<endl;
            cin>>k;

            if (k==1)
            {
                 cout << "Enter the price of the item" << endl;
                cin >>a;
                cout << "Enter the quantity of the item" << endl;
                cin>>b;

            }
        }

	if (total>5000)
        total=total-(total/10);

        cout <<"Total Expense = "<<total<<endl;
}
