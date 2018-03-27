#include <iostream>

#include <string>
#include <fstream>
using namespace std;
int main()
{
 int a[100][3];
 ifstream input("ATM.txt");
 ofstream output("updated_ATM.txt");

 for (int k=0;k<100;k++)
   { for (int j=0;j<3;j++)
       {  input >>a[k][j];}}

 int yes=1;
 int act; int g;
 
 while (yes>0)
 {
 cout<<"Input your account number :"<<endl;
 cin >>act;

 if (act>0&&act<101)
  {for (int l=0;l<100;l++)
  {
    if(a[l][0]==act)
      {g=l;
       yes=0;
      break;}
  }}
  
 }

 int start=1;  
 
 while (start>0)
  {
    int o;
    int m;
    cout<< "How much money do you want to transact?"<<endl;
    cin >>m;
    cout<< "Do you want to take out money or add it? [1][2]"<<endl;
    cin>>o;

    if (o==1)
      a[g][1]=a[g][1]-m;
    else if (o==2)
      a[g][1]=a[g][1]+m;
    
    a[g][2]=a[g][2]+1;
    
    int h;
    cout <<"Do you want to transact again? [0][1]"<<endl; 
    cin >>h;
    
    if (h==0)
      start=0;
  }
  
  cout<< a[g][1]<<endl;
  cout<< a[g][2]<<endl;

  for (int q=0;q<100;q++)
    {
         output<< a[q][0] << "   "<<a[q][1]<<"    "<<a[q][2]<<endl;
    }
  input.close();
  output.close();       
}
 

