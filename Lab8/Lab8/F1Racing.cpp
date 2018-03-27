#include "F1Racing.h"

//Write implementaion of member 'functions' associated to each class declared in F1Racing.h here.

/*
	Consider you have two classes named Class1 and Class2. Now, to write a member function of Class1, we write

	returnType Class1::memberFunc(arguments){
		//implementation goes here
	}

	Similarly to to write a member function of Class2, we write

	returnType Class2::memberFunc(arguments){
		//implementation goes here
	}


	You need to do this w.r.t the Driver and F1Car class and implement the member functions as you declared TASK1 
	inside F1Racing.h file.

	Remember, to implement a function it must be declared first in class declaration. In here you have done class
	declarations in F1Racing.h.

	So,  if a function is declared in class declaration, then it MUST be implemented and vice versa i.e if a function is
	 implemented then  it must be a part of class declaration.
	 In case of not meeting this requirement you will get compilation errors and trust me , compilation errors in unix while
	 dealing with classes are not that easy to understand
*/
	F1Car::F1Car(){
        Name="McLarrens";
		tyre="BMW";
		fuel=0;
     }
	F1Car::F1Car(string namec, string tyerbr){
                Name=namec;
                tyre=tyerbr;
                fuel=0;
        }
	F1Car::F1Car(const F1Car &car){
		Name=car.Name;
		tyre=car.tyre;
		fuel=car.fuel;
	}
	
	void F1Car::incFuel(int num){
		fuel=fuel+num;
	}
	string F1Car::getName(){
		return Name;
	}
	string F1Car::getTyre(){
		return tyre;
	}
	int F1Car::getFuel(){
		return fuel;
	}

	Driver::Driver(){
		Name="Faizan";
		Country="Pakistan";
		Wins=0;
	} 
	Driver::Driver (string named, string countryd, int winsd){
		Name=named;
		Country=countryd;
		Wins=winsd;
	}
	Driver::Driver(const F1Car &car, string named, string countryd, int winsd){
		card=car;
		Name=named;
		Country=countryd;
		Wins=winsd;
	}
	void Driver::incWins(int num){
		Wins=Wins+num;
	}
	F1Car Driver::getCar(){
		return card;
	}
	int Driver::getWins(){
		return Wins;
	}
		
	
