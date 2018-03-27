#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;

void addRandom(int n,int arr[]);
int findMaxCoins(int arr[], int start, int stop);

int main (){
    int numPorts=10;
    int arr[numPorts];
    srand (time(NULL));
    addRandom(numPorts,arr);
    int k=findMaxCoins(arr, 0, numPorts-1);
    int k1=findMaxCoins(arr, 1, numPorts-2);
    cout<<"Maximum Value Player 1 can get if Player 2 is Smart! = "<<k<<endl;
    cout<<"Maximum Value Player 2 can get if Player 1 is Smart! = "<<k1<<endl;
    if (k1>k)
        cout<<"Player 2 Should Win"<<endl;
    else
        cout<<"Player 1 Should win"<<endl;
}

int findMaxCoins(int arr[], int start, int stop)
{
    if (start > stop)
        return 0;

    if (start == stop)
        return arr[start];

    int a = arr[start] + min(findMaxCoins(arr, start+2, stop), findMaxCoins(arr, start+1, stop-1));
    int b = arr[stop]  + min(findMaxCoins(arr, start+1, stop-1), findMaxCoins(arr, start, stop-2));

    return max(a,b);
}
void addRandom (int n,int arr[]){

    for (int i=0; i<n; i++)
    {
        arr[i] = 1+(rand()%10);
        cout<<arr[i]<<", ";
    }

    cout<<endl;
}
