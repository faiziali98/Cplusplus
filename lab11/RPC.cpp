#include "RPC.h"


void Tool::setStrength(int x){
	strength=x;
}

Rock::Rock(int b){
	setStrength(b);
	type="rock";
}

int Rock::getStrength(){
	return strength;
}

bool Rock::fight(Tool *t){
	string g=t->type;
	int st=t->strength;
	if (g=="papper")
		setStrength(strength/2);
	else if (g=="scissor")
		setStrength(strength*2);
	if (st>strength)
		{setStrength(strength*2);return 0;}
	else if (st<strength)
		{setStrength(strength/2);return 1;}
}


Papper::Papper(int b){
	setStrength(b);
	type="papper";
}

int Papper::getStrength(){
	return strength;
}

bool Papper::fight(Tool *t){
	string g=t->type;
	int st=t->strength;
	if (g=="scissor")
		setStrength(strength/2);
	else if (g=="rock")
		setStrength(strength*2);
	if (st>strength)
		{ setStrength(strength*2);return 0;}
	else if (st<strength)
		{ setStrength(strength/2);return 1;}
}

Scissor::Scissor(int b){
	setStrength(b);
	type="scissor";
}

int Scissor::getStrength(){
	return strength;
}

bool Scissor::fight(Tool *t){
	string g=t->type;
	int st=t->strength;
	if (g=="rock")
		setStrength(strength/2);
	else if (g=="papper")
		setStrength(strength*2);
	if (st>strength)
		 {setStrength(strength*2);return 0;}
	else if (st<strength)
		{ setStrength(strength/2);return 1;}
}

