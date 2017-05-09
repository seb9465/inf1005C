/**
* Tableau d'aléatoire.
* \fichier   Exercice10.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout << setprecision(3);

	const int NB_LIGNES = 3,
		NB_COLONNES = 4;

	const double INTERVALLE_MAX = 8.750,
		INTERVALLE_MIN = 2.500;

	double tableau[NB_LIGNES][NB_COLONNES] = {};

	srand(time(nullptr));

	for (int i = 0; i < NB_LIGNES; i++)
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			tableau[i][j] = (double)(rand() % (int)((INTERVALLE_MAX * 1000) - (INTERVALLE_MIN * 1000) + 1))/1000 + INTERVALLE_MIN; //Génération nombre aléatoire
			cout<< tableau[i][j] << "\t";
		}
		cout << endl;
	}

	int indiceColonnePlusGrand = 0;
	double sommePlusGrande = 0.0;
	for (int j = 0; j < NB_COLONNES; j++)
	{
		double somme = 0;
		for (int i = 0; i < NB_LIGNES; i++)
		{
			somme += tableau[i][j];
		}
		if (somme > sommePlusGrande)
		{
			indiceColonnePlusGrand = j;
			sommePlusGrande = somme;
		}
	}

	cout << "La colonne avec la somme la plus elevee est : " << endl;
	for (int i = 0; i < NB_LIGNES; i++)
	{
		cout << tableau[i][indiceColonnePlusGrand] << endl;
	}

	return 0;
}