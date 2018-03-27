#include <iostream>
using namespace std;

template<class T>
void print(T n){
        if(n==0)
                cout<<n<<endl;
        else
        {
                cout<<n<<endl;
		print(n-1);
        }
}

int main()
{
	print(5);
}

