#include "RPC.cpp"

int main() {
	Scissor *s = new Scissor(5);
	Papper *p = new Papper(5);
	Rock *r = new Rock(5);

	cout << s->fight(p) << ' ' << p->fight(s) << endl;
	cout << p->fight(r) << ' ' << r->fight(p) << endl;
	cout << s->fight(r) << ' ' << r->fight(s) << endl;
}

