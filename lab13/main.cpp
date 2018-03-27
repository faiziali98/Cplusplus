#include <iostream>
#include<fstream>
using namespace std;
#include "student.cpp"
#include<string.h>
#include<vector>
#include <map>
#include <algorithm>
int main()
{

	ifstream input;
	input.open("student.txt");

	string b;
	int roll=0;
	string name;
	double gpa=0;
	string geni;
	char gen;
	int number=0;
	while (getline(input,b)){
		number++;
	}
	input.close();

	ifstream input1;
        input1.open("student.txt");
	vector<Student> arr(number);
	for(int n=0;n<number;n++){
		input1 >> roll;
		input1 >> name;
		input1 >> geni;
		input1 >> gpa;
		if (geni=="Male")
			gen='M';
		else if (geni=="Female")
                        gen='F';
		Student s1(roll,name,gpa,gen);
		arr[n]=s1;
	}
	for(int n=0;n<number;n++){
		cout<<"Student Info: "<< arr[n]<<endl;
        }
    cout<<"Now sorted "<<endl;
//	sort( arr.begin(), arr.end() );
	for ( int i = 1; i < number; ) {
    		 if ( arr[i-1] < arr[i] ) {
    			   ++i;
    		 }
     		else {
        		Student temp = arr[i-1];
        		arr[i-1] = arr[i];
        		arr[i] = temp;

       			--i;
       			if ( i == 0 ) {
         			i = 1;
       			}
     		}
	   }

	for(int n=0;n<number;n++){
		cout<<"Student Info: "<< arr[n]<<endl;
        }
	map< string, Student > maps;

	for( int i = 0; i < number; i++ ){
		string d;
		d=arr[i].getName();
		cout<<d<<endl;
		maps[d] = arr[i];
	}
	for( map< string, Student >::iterator i = maps.begin(); i != maps.end(); ++i )
		cout << (*i).first << ": " << (*i).second << endl;

}

