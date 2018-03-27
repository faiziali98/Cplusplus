#include "student.h"
#include <iostream>

using namespace std;


Student::Student(){
}

Student::Student(int I, string nam, double GP, char gende){
	ID=I;
	name=nam;
	percentage=GP;
	gender=gende;
	
	try {
		int a=ID/10000;
		if (ID<=0 || a!=121){
			throw 0;
		}
	} catch (int b){
		cout<<"ID format is not valid"<<endl;
	} 

	try {
		if (percentage<=0)
			throw 0;
	} catch (int b){
		cout<<"Percentage format is not valid"<<endl;
	} 

}

void Student::setStudent(int I, string nam, double GP, char gende){
	
	ID=I;
	name=nam;
	percentage=GP;
	gender=gende;
	
	try {
		int a=ID/10000;
		
		if (ID<=0 || a!=121){
			throw 0;
		}
	} catch (int b){
		cout<<"ID format is not valid"<<endl;
	} 

	try {
		if (percentage<=0)
			throw 0;
	} catch (int b){
		cout<<"Percentage format is not valid"<<endl;
	} 

}

int Student::getID(){
	return ID;
}

string Student::getName(){
	return name;
}

double Student::getGPA(){
	return percentage;
}

string Student::getGender(){
	if (gender=='M')
		return "Male";
	else if (gender=='F')
		return "Female";
}

bool Student::operator<(const Student& b){
	if (b.percentage>percentage)
		return 1;
	else if (b.percentage<percentage)
		return 0;
}

ostream & operator<<(std::ostream &os, const Student& p){
	if (p.gender=='M')
		cout<<p.name<<" is a Male student his roll number is "<<p.ID<<" and his current percentage is "<<p.percentage<<"%"<<endl;
	else if (p.gender=='F')
		cout<<p.name<<" is a Female student his roll number is "<<p.ID<<" and his current percentage is "<<p.percentage<<"%"<<endl;
}			
