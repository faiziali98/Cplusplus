#include<iostream>
#include<string>
using namespace std;

class F1Car{
        private:
                string Name;
                string tyre;
                int fuel;

        public:
                F1Car();
                F1Car(string namec, string tyerbr);
                F1Car(const F1Car &car);
                void incFuel(int num);
                string getName();
                string getTyre();
                int getFuel();

};

class Driver{
	private:
		string Name;
        string Country;
        int Wins;
        F1Car card;
	public:
		Driver();
		Driver (string named, string countryd, int winsd);
		Driver (const F1Car &car, string named, string countryd, int winsd);
		void incWins(int num);
		int getWins();
		F1Car getCar();
};
//NOTE THIS SEMICOLON AT THE END OF CLASS DECLARATION

//NOTE THE SEMICOLON AGAIN :P THIS INFACT IS THE MOST FREQUENT+ANNOYING SYNTAX ERROR OUT OF THE MANY WE GET IN 'OOP; :P
