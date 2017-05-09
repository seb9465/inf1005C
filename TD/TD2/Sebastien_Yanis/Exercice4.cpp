/**
* Valeur approchée de sin(x).
* \fichier   Exercice4.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   25 septembre 2014
* Créé le 24 septembre 2014
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Initialisation des variables
	double valeur = 0.0;
	double sinusValeur = 0.0;
	double premierTerme = 0.0;
	double deuxiemeTerme = 0.0;
	double troisiemeTerme = 0.0;
	double sommeTroisTermes = 0.0;

	//Génération d'un nombre aléatoire entre 0 et 1
	srand(time(nullptr));
	valeur = (double)rand() / RAND_MAX;
	cout << "Valeur du nombre aleatoire : " << valeur << endl;

	//Calcul de valeur sinus avec le sinus
	sinusValeur = sin(valeur);
	cout << "Valeur du sinus du nombre aleatoire : " << sinusValeur << endl;

	//Calcul de la valeur sinus avec la série
	premierTerme = valeur;
	deuxiemeTerme = pow(valeur, 3) / (3 * 2 * 1); //Structure de répétition pour calculer factorielle
	troisiemeTerme = pow(valeur, 5) / (5 * 4 * 3 * 2 * 1); //Structure de répétition pour calculer factorielle

	sommeTroisTermes = premierTerme - deuxiemeTerme + troisiemeTerme;

	cout << "Somme des trois premiers termes de la serie : " << sommeTroisTermes << endl;

	cout << "Difference entre les deux valeurs : " << sommeTroisTermes - sinusValeur << endl;

	return 0;
}