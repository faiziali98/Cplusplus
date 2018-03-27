#include "heirarchy.h"




HumanBeing::HumanBeing(string name , string nation , int age){
	Name=name;
	nationality=nation;
	Age=age;
}

Cricketer::Cricketer(string name, string nation, int age, int maxScr, int wickets, float avg):HumanBeing(name ,nation ,age){
	average=avg;
	maximumRuns=maxScr;
	Wickets=wickets;
}

void HumanBeing::setName(string name){
	Name=name;
}

string HumanBeing::getName(){
	return Name;
}


PhdStudent::PhdStudent(string name, string nation, int age, string advisor, string univ ,int numPubls):HumanBeing(name ,nation ,age){
	advisorName=advisor;
	instituteName=univ;
	numpublications=numPubls;
}

float Cricketer::getAverage(){
	return average;
}

void Cricketer::setMaxScore(int max){
	maximumRuns=max;
}



string PhdStudent::getInstitute(){
	return instituteName;
}

void PhdStudent::setNumPubls(int n){
	numpublications=n;
}
