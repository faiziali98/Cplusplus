#include<iostream>
using namespace std;

template<typename T,int a,int s1>
T search(const T arr[],T size)
{
 int mid;
 if (size==2 && s1%2==0)
 {
	if (arr[size-1]==a || arr[size-2]==a)
		return 1;
	else
		return -1;
 }
 else if(size==1 && s1%2==0)
 {
	 if (arr[size-1]==a)
                return 1;
         else
                return -1;

 }
 else if(size==0)
	return -1;
 else
 {
	int s=size/2-1;
 	mid = arr[s];

	if (a == mid)
 	{
 		return 1;
 	}
 	else if (a < mid)
 	{
		int k[s];
		for(int n=0;n<size/2-1;n++)
		{
			k[n]=arr[n];
		}
 		int b=search<int, a, s1>(k,s);
		return b;
 	}
 	else if (a > mid)
 	{
		int k[size-(s+1)];
                for(int n=s+1;n<size;n++)
                {
                        k[n-(s+1)]=arr[n];
                }
                int b=search<int ,a,s1>(k,(size-(s+1)));
		return b;
 	}
    }
}

int main(){

	const int arr[6]={1,2,3,4,5,6};
	int b=search<int,3,6>(arr,6);
	cout<<b<<endl;
}
