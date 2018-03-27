#include <iostream>

using namespace std;

int main()
{
    int a,maxm,c;
    cout << "Enter the number" << endl;
    cin>>a;

    maxm=a;
    int minm=a;
    c=1;

    while (c>0)
    {
        cout << "Enter the next number" << endl;
        cin>>a;

        if (a==-1)
            c=0;

        if (c>0)
        {
            if (a>maxm)
                maxm=a;
            if (a<minm)
                minm=a;
        }

    }
    cout<<"Maximum number entered = "<<maxm<<endl;
    cout<<"Minimum number entered = "<<minm<<endl;
}

