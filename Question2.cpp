#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

//Fonctions utiles pour la question 2

double suite(int precision)
{
	//Initialiser les valeurs
	double oldValue = 1,newValue;
	double error = 1 / pow(10, precision);

	while (true)
	{
		newValue = sqrt(2 + oldValue);

		if ((newValue - oldValue) < error)
		{
			break;
		}
		else
		{
			oldValue = newValue;
		}
	}
	return newValue;
}

int main()
{
	int precision;
	cout << "Choisir une precision: ";
	cin >> precision;
	cout<<fixed<<setprecision(precision)<< suite(precision);
}
