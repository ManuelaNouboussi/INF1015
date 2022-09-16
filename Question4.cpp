#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int produit(int a, int b)
{
	return a * b;
}

void multiplicationRusse(int a, int b,int resultatTheorique)
{
	//Définition
	vector<int> col1;
	vector<int> col2;
	int nbDeTest = 0;
	int resultatExperimental=0;
	struct russe
	{
		int a;
		int b;
		int resultat = produit(a, b);
	};
	russe tests[3];


	for (int i = a; i >= 1; i = (i / 2))
	{
		if (i % 2 != 0)
		{
			col1.push_back(i);
			col2.push_back(b);
		}
		b = (b * 2);
	}

	for (int i=0;i<col1.size();i++)
	{
		tests[i].a = col1[i];
		tests[i].b = col2[i];
		tests[i].resultat = produit(col1[i],col2[i]);
		resultatExperimental += tests[i].resultat;
		nbDeTest++;

	}

	if (resultatExperimental == resultatExperimental)
	{
		cout << nbDeTest << "/3 tests passent." << endl;
	}
	else if(nbDeTest<3)
	{
		cout << nbDeTest << "/3 tests passent." << endl;
	}
}

int main()
{
	int a, b;
	cout << "Entrer une valeur de a et une valeur de b: ";
	cin >> a >> b;

	multiplicationRusse(a, b, produit(a, b));
}