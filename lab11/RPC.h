#include <iostream>

using namespace std;

class Tool {
	public:
		int strength;
		string type;
		void setStrength(int x);
		virtual bool fight(Tool *t)=0;
};

class Rock : public Tool {
	public:
	Rock(int b);
	bool fight(Tool *t);
	int getStrength();
};

class Papper : public Tool {
	public:
	Papper(int b);
	bool fight(Tool *t);
	int getStrength();
};

class Scissor : public Tool {
	public:
	Scissor(int b);
	bool fight(Tool *t);
	int getStrength();
};