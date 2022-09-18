#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Russe
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
};

unsigned int multiRusse(unsigned int num1, unsigned int num2) {
	int result = 0;
	while (num2 > 0) {
		if (num2 & 1)
			result = result + num1;
		num1 = num1 << 1;
		num2 = num2 >> 1;
	}
	return result;
}

bool verif(int a, int b)
{
	return a * b == multiRusse(a, b);
}

int main()
{
	int compteur = 0;
	Russe me;
	me.a = 7;
	me.b = 11;
	me.c = 37;
	me.d = 129;
	me.e = 12;
	me.f = 3765;
	if (verif(me.a, me.b))
		compteur += 1;

	if (verif(me.c, me.d))
		compteur += 1;

	if (verif(me.e, me.f)) 
		compteur += 1;

	cout << compteur << "/3 tests passent." << endl;

	return 0;
		
}
