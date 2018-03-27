#include<iostream>
#include<string>
using namespace std;

//	CLASS DECLARATIONS

class HumanBeing{
	private:
		string Name;
		string nationality;
		int Age;
	public:
		HumanBeing(string a,string b,int c);
		void setName(string a);
		void setAge(int a);
		void setNation(string a);
		string getName();
		string getNation();
		int getAge();
};

class Cricketer:public HumanBeing{
	private:
		float average;
		int maximumRuns;
		int Wickets;
	public:
		Cricketer(string name, string nation, int age, int maxScr, int wickets, float avg);
		float getAverage();
		void setMaxScore(int a);
		int getMax();
		int getWickets();
		void printName();
};

class PhdStudent:public HumanBeing{
	private:
		string advisorName;
		string instituteName;
		int numpublications;
	public:
		PhdStudent(string name, string nation, int age, string advisor, string univ ,int numPubls);
		string getInstitute();
		void setNumPubls(int a);
		string getAdvisor();
		int getPublications();
};
