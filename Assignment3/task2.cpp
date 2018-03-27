
#include<iostream>
#include<string.h>

using namespace std;

void gnomeSort( int *array, int size );

int main() {
    int a;
	cout<<"Input the length of array"<<endl;
	cin >> a;
	int b[a];
	int *p1;
	cout<<"Let enter the numbers in the first array"<<endl;

	for (int x=0; x<a;x++)
	{
		cout<< "Enter number at position " <<x+1<<endl;
		cin >> b[x];
	}

    p1=b;
    gnomeSort( p1, a );
}
void gnomeSort( int *q, int a )
  {
   for ( int i = 1; i < a; ) {
     if ( q[i-1] >= q[i] ) {
       ++i;
     }
     else {
        int temp = q[i-1];
        q[i-1] = q[i];
        q[i] = temp;

       --i;
       if ( i == 0 ) {
         i = 1;
       }
     }
   }
   for (int x=0; x<a;x++)
        {
                cout<< q[x]<<endl;
        }
}

