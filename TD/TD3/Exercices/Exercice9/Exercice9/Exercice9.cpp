l/**
* Le tri de Shell.
* \fichier   Exercice9.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//Initialisation des variables
	const int DIMENSION = 100;
	int tableau[DIMENSION] = {};

	ifstream lecture("liste.txt");
	ofstream ecriture;

	int i = 0;
	while (lecture.peek() != EOF) //transfert des donnees du fichier au tableau
	{
		lecture >> tableau[i];
		i++;
	}
	lecture.close();

	//Algorithme de trie de Shell
	for (int k = DIMENSION / 2; k >= 1; k = k / 2)
	{
		for (int i = k + 1; i < DIMENSION; i++)
		{
			int j = i - k;
			while ((j > 0) && (tableau[j] > tableau[j + k]))
			{
				int tamponTableauJ = tableau[j];
				tableau[j] = tableau[j + k];
				tableau[j + k] = tamponTableauJ;

				j = j - k;
			}
		}
	}

	ecriture.open("liste.txt");

	for (int i = 0; i < DIMENSION; i++) //transfert des donnees du tableau au fichier
	{
		ecriture << tableau[i] << endl;
	}
	ecriture.close();

	return 0;
}
