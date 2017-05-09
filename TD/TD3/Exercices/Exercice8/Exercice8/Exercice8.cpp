/**
* Catégorisation d'une population.
* \fichier   Exercice8.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	enum population { ETUDIANT, TRAVAILLEUR, CHOMEUR, RETRAITE, NBPOPULATION };
	int indice;

	srand(time(nullptr));

	int tableau[NBPOPULATION] = {};

	for (int i = 0; i < NBPOPULATION; i++)
	{
		tableau[i] = rand() % 10001;
	}

	indice = 0;
	cout << "Entrer un indice entre 0 et 3 : ";
	cin >> indice;
	cout << "La valeur a l'indice demande : " << tableau[indice] << endl;

	return 0;
}