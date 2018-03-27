#include "F1Racing.cpp"


/*
	You have to write your main here to test functionalities of your classes.
*/
string carName(Driver d);
 bool compareFuel(Driver d1 , Driver d2);
int winsOfOwner(Driver *p , F1Car car, int a);

int main(){
	Driver one("Faizan","Pakistan",100);
	F1Car car4;
	car4.incFuel(5);
	Driver two (car4,"Faizan","Pakistan",100);
	F1Car car3=one.getCar();
	string Nme=carName(one);
	cout<<Nme<<endl;
	bool t=compareFuel(two , one);
	if (t==1)
		cout<<"Yeah Cheez"<<endl;
	else
		cout<<"Nai yaar!!"<<endl;
	int a;
	cout<<"Entet the number of drivers"<<endl;
	cin>>a;
	Driver arr[a];
	for (int n=0;n<a;n++)
	{
		string namofcar;
		int wins;
		cout<<"Enter name of "<<n+1<<" Driver's car"<<endl;
		cin>>namofcar;
		cout<<"Enter wins of "<<n+1<<" Driver"<<endl;
		cin>>wins;
		F1Car car(namofcar,"Tata");
		Driver one(car,"Faizan","Pakistan",wins);
		arr[n]=one;
	}
	Driver *p;
	p=arr;
	F1Car car5;
	int win=winsOfOwner(p,car5,a);
	cout<<win<<endl;
}

string carName(Driver d){
	F1Car car=d.getCar();
	return car.getName();
}
bool compareFuel(Driver d1 , Driver d2){
	F1Car car1=d1.getCar();
	F1Car car2=d2.getCar();
	int f1=car1.getFuel();
	int f2=car2.getFuel();
	if (f1>f2)
		return 1;
	else
		return 0;
}
int winsOfOwner(Driver *p , F1Car car,int a){
	Driver one;
	for (int n=0;n<a;n++)
	{
		one=p[n];
		F1Car car1=one.getCar();
		if (car1.getName()==car.getName())
			break;
	}
	int w=one.getWins();
	return w;
}


