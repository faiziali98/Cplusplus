#include <iostream>
using namespace std;
#include <string.h>

string encryption(string s);
string decryption(string s);

int main()

{
  string s;
  cout << "Enter your message:" << endl;
  getline(cin,s);
  cout<<s<<endl;
  string m=encryption(s);
  string j=decryption(m);
}

string encryption(string s)
{
  int asc;  
  int bac;
  int size=s.size();
  for (int z=0;z<s.size();z++)
	{ 
	  asc=s[z];bac=s[z];
	  if (asc!=32&&(asc>=97 && asc<=122))
		{
		  for(int k=1;k<=5;k++)
			{
			  asc++;
			  if (asc>122)
			    asc=97;
			}
		   s[z]=asc; }
	}

  cout<<s<<endl;
  return s;
}

string decryption(string s)
{
  int asc;
  int bac;
  int size=s.size();
  for (int z=0;z<s.size();z++)
        {
          asc=s[z];bac=s[z];
          if (asc!=32&&(asc>=97 && asc<=122))
                {
                  for(int k=1;k<=5;k++)
                        {
                          asc--;
                          if (asc<97)
                            asc=122;
                        }
                   s[z]=asc; }
        }

  cout<<s<<endl;
  return s;
}

