#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


//Fonctions utiles pour la question 1

vector<string> converter(string element) //Conversion d'un string en vecteur
{
	vector<string> liste;
	string concatenation = "";
	for (unsigned int i = 0; i < element.size(); i++)
	{
		if (char(element[i]) != ' ')
		{
			concatenation += element[i];
			if (i == (element.size() -1))
			{
				liste.push_back(concatenation);
				concatenation = "";
			}
		}
		else 
		{
			liste.push_back(concatenation);
			concatenation = "";
		}
	}
	return liste;
}
int longest(vector<string> list) //Analyse du vecteur pour le mot le plus long
{
	int index=0;
	unsigned int length= list[0].size();
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i].size() >= length)
		{
			index = i;
			length = list[i].size();
		}
	}
	return index;
}
int shortest(vector<string> list) //Analyse du vecteur pour le mot le plus court
{
	int index = 0;
	unsigned int length = list[0].size();
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i].size() <= length)
		{
			index = i;
			length = list[i].size();
		}
	}
	return index;
}
float average(vector<string> list) 
{
	float average = 0;
	for (string word : list) 
	{
		average += word.size();
	}
	return average/list.size();
}

void question1() 
{
	string sentence;
	cout << "Saisissez une phrase : ";
	getline(cin, sentence);
	vector<string> list = converter(sentence);
	cout <<"Le mot le plus court est: " << list[shortest(list)]<<endl;
	cout <<"Le mot le long court est: " << list[longest(list)] << endl;
	cout <<"La longueur moyenne est: " << average(list) << " lettres" <<endl;
}

int main()
{
	question1();
}
