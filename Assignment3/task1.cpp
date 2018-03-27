#include<iostream>
#include<string.h>

using namespace std;

void gnomeSort( int *array, int size );

int main() {
  char c='c';
  int num=0;
  num=c;
  cout<<num<<endl;
}
void gnomeSort( int *q, int a )
  {
   for ( int i = 1; i < a; ) {
     if ( q[i-1] <= q[i] ) {
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
