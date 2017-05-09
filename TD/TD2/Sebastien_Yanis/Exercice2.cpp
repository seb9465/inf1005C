/**
* Calcul de surface entre un hexagone et un cercle.
* \fichier   Exercice2.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   25 septembre 2014
* Créé le 24 septembre 2014
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//Initialisation des variables
	const double PI = 3.1416;
	double rayon = 0.0;
	double diametre = 0.0;
	double circonference = 0.0;
	double aireCercle = 0.0;
	double surfaceHexagone = 0.0;
	double differenceAireSurface = 0.0;

	//Demander le rayon
	cout << "Entrez le rayon d'un cercle : ";
	cin >> rayon;

	//Calcul du diamètre du cercle & afficher
	diametre = 2 * rayon;
	cout << "Le diametre du cercle est de : " << diametre << "cm" << endl;

	//Caclcul de la circonférence & afficher
	circonference = 2 * PI * rayon;
	cout << "La circonference du cercle est de : " << circonference << "cm" << endl;

	//Calcul de l'aire du cercle & afficher
	aireCercle = PI * pow(rayon, 2);
	cout << "L'aire du cercle est de : " << aireCercle << "cm2" << endl;

	//Calcul de la surface de l'hexagone
	surfaceHexagone = 2 * sqrt(3) * pow(rayon, 2);

	//Calcul de la différence
	differenceAireSurface = surfaceHexagone - aireCercle;
	cout << "La difference de surface entre l'hexagone et le cercle est de : " << differenceAireSurface << "cm2" << endl;

	return 0;
}
