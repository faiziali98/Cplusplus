#include <iostream>

using namespace std;

int main()
{
    int i ;
    cout<<"Enter the dimensions of the grid"<<endl;
    cin>>i;
    int k=0;
    int j=i;

    for (int m=0;m<i;m++)
    {

        while (k<j)
        {

            //cout<<k;


            if (m&k==0)
                cout<<" ";
            else
                cout<<"*";

            k=k+1;

        }

        cout<<endl;

        k=0;
        j=j-1;
    }
}
