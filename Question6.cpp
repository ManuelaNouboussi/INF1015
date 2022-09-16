#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void gagnant(vector<char> board)
{
	char lettre='e';
	//3 facons de gagner au tic tac toe

	//#1 (Les lignes)
	if (board[0] == board[1] && board[1] == board[2])
	{
		lettre = board[0];
	}
	else if (board[3] == board[4] && board[4] == board[5])
	{
		lettre = board[3];
	}
	else if (board[6] == board[7] && board[7] == board[8])
	{
		lettre = board[6];
	}

	//#2 (Les colonnes)
	else if (board[0] == board[3] && board[3] == board[6])
	{
		lettre = board[0];
	}
	else if (board[1] == board[4] && board[4] == board[7])
	{
		lettre = board[1];
	}
	else if (board[2] == board[5] && board[5] == board[8])
	{
		lettre = board[2];
	}

	//#3 (Les diagonales)
	else if (board[0] == board[4] && board[4] == board[8])
	{
		lettre = board[0];
	}
	else if (board[2] == board[4] && board[4] == board[6])
	{
		lettre = board[2];
	}

	//Résultat
	switch (lettre)
	{
		case 'x':
			cout << "Le joueur 1 gagne." << endl;
			break;
		case 'o':
			cout << "Le joueur 2 gagne." << endl;
			break;
		default:
			cout << "Egalite" << endl;
			break;
	}
}

//Lecteur du fichier
void lectureFichier(string nomFichier)
{
	//Variable nécessaire
	vector<char> board;
	string text;

	//Initialisation et lecture du fichier
	ifstream myfile;
	myfile.open(nomFichier);

	while (!myfile.eof())
	{
		getline(myfile, text);
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
			{
				board.push_back(text[i]);
			}
		}
	}

	//Fermer le fichier
	myfile.close();
	gagnant(board);
};

int main() 
{
	string file[5]={"grille1.txt","grille2.txt","grille3.txt","grille4.txt", "grille5.txt"};
	for (int i = 0; i < (sizeof(file) / sizeof(file[0])); i++)
	{
		lectureFichier(file[i]);
	}
}