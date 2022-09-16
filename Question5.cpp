#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

unsigned int randomNumber() 
{
	srand(time(NULL));
	
	return rand() % 1000;

}
void gestionDeDistance(unsigned int random) 
{
	unsigned int guess;
	int counter=1;
	cout << "Entrez un nombre entier : ";
	cin >> guess;
	while (guess != random)
	{
		if (guess < 0 || guess > 1000)
		{
			cout << "Entrez un nombre entier : ";
			cin >> guess;
			continue;
		}

		else if (guess > random)
		{

			cout << "Trop haut.\n" << "Entrez un nombre entier : ";
			cin >> guess;
		}
		else if (guess < random)
		{
			cout << "Trop bas\n" << "Entrez un nombre entier : ";
			cin >> guess;
		}
		counter++;
	}

	cout << "Bravo! Vous avez reussi en " << counter << " tentatives!";
}

int main() 
{

	//Génération de numéro aléatoire
	unsigned int random = randomNumber();

	//Algorithme
	gestionDeDistance(random);

}