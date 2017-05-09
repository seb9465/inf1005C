/**
* Calcul de l'angle entre deux valeurs.
* \fichier   Exercice5.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   25 septembre 2014
* Créé le 24 septembre 2014
*/

#include <iostream>
using namespace std;

int main()
{
	//Initialisation des variables
	const double PI = 3.1416;

	double Ax = 0.0;
	double Ay = 0.0;

	double Bx = 0.0;
	double By = 0.0;

	double angle = 0.0;
	double angleRadians = 0.0;

	//Entrez les valeurs
	//Structure de répétition
	cout << "Entrez la coordonnee en x du vecteur A : " << endl;
	cin >> Ax;
	cout << "Entrez la coordonnee en Y du vecteur A : " << endl;
	cin >> Ay;

	cout << "Entrez la coordonnee en x du vecteur B : " << endl;
	cin >> Bx;
	cout << "Entrez la coordonnee en Y du vecteur B : " << endl;
	cin >> By;

	//Calcul de l'angle entre les deux vecteurs avec la formule scalaire
	angleRadians = acos(((Ax * Bx) + (Ay * By)) / ((sqrt(pow(Ax, 2) + pow(Ay, 2))) * (sqrt(pow(Bx, 2) + pow(By, 2)))));

	//Afficher composante des vecteurs & l'anlge en radians
	//Structure de répétition
	cout << "Vecteur A : (" << Ax << "," << Ay << ")" << endl;
	cout << "Vecteur B : (" << Bx << "," << By << ")" << endl;
	cout << "L'angle entre les deux vecteurs en radians est de : " << angleRadians << endl;

	//Calcul de l'angle en degré & afficher
	angle = 180 * angleRadians / PI;
	cout << "L'angle entre les deux vecteurs en degre est de : " << angle << endl;

	return 0;
}
