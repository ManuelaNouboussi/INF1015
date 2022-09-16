#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int lectureEntier()
{
	//Première entrée
	string element;
	cout << "Entrer un integer: ";
	cin >> element;

	//Detection du integer
	bool condition = true;

	while (condition) 
	{
		for (int i = 0; i < element.length(); i++)
		{
			if (isdigit(element[i]) == false)
			{
				cout << "Entrer un nouvel integer: ";
				cin >> element;
				continue;
			}
		}
		return stoi(element);
	}
}

void sorting(int vecteur[],const int taille) 
{
	//Initialisation
	int newValue= lectureEntier();
	int *intermediate;
	intermediate = new int[taille];

	//Affichage de l'ancien tableau
	cout << "le tableau avant l'insertion: {";
	for (int i = 0; i < taille; i++)
	{
		if (i == taille - 1)
		{
			cout << vecteur[i] << "}" << endl;
		}
		else
		{
			cout << vecteur[i] << ",";
		}
	}

	//Algorithme
	for (int i = 0; i < taille; i++)
	{
		if (newValue < vecteur[i])
		{
			intermediate[i] = newValue;
			newValue = vecteur[i];
			if (i == taille-2)
			{
				intermediate[taille-1] = newValue;
				break;
			}
		}
		else
		{
			if (i==taille-1) 
			{
				intermediate[i] = newValue;
			}
			else
			{
				intermediate[i] = vecteur[i];
			}
		}
	}

	//Affichage du nouveau tableau
	cout << "le tableau après l'insertion: {";
	for (int i = 0; i < taille; i++)
	{
		if (i == taille - 1)
		{
			cout << intermediate[i] << "}" << endl;
		}
		else
		{
			cout << intermediate[i] << ",";
		}
	}
	 
	delete[] intermediate;
	
}

int main()
{
	//Tableau peu importe
	const int size = 6;
	int tableau[size] = { 1,3,4,7,9};

	sorting(tableau,size);

}	