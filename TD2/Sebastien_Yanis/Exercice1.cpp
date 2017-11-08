/**
* Calcul de distance entre des points.
* \fichier   Exercice1.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   25 septembre 2014
* Créé le 24 septembre 2014
*/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	//Initiation des variables

	double Ax = 0.0;
	double Ay = 0.0;

	double Bx = 00.0;
	double By = 0.0;

	double Cx = 0.0;
	double Cy = 0.0;

	double distanceAB = 0.0;
	double distanceAC = 0.0;
	double distanceBC = 0.0;

	double perimetre = 0.0;

	//Lecture des valeurs du point A et du point B
	//Structure de répétition
	cout << "Entrez la coordonnee de x pour le point A :" << endl;
	cin >> Ax;

	cout << "Entrez la coordonnee de y pour le point A : " << endl;
	cin >> Ay;

	cout << "Entrez la coordonnee de x pour le point B : " << endl;
	cin >> Bx;

	cout << "Entrez la coordonnee de y pour le point B : " << endl;
	cin >> By;

	//Calcul de la distance entre le point A et le point B & afficher
	distanceAB = sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2));
	cout << "La distance entre le point A et le point B est de : " << distanceAB << endl;

	//Lecture des valeurs du point C
	cout << "Entrez la coordonnee de x pour le point C : " << endl;
	cin >> Cx;

	cout << "Entrez la coordonnee de y pour le point C : " << endl;
	cin >> Cy;

	/*Calcul de la distance entre le point A et le point C &
	calcul de la distance entre le point B et le point C
	calcul du périmètre */
	distanceAC = sqrt(pow(Cx - Ax, 2) + pow(Cy - Ay, 2));
	distanceBC = sqrt(pow(Cx - Bx, 2) + pow(Cy - By, 2));

	//Calcul du périmètre
	perimetre = distanceAB + distanceAC + distanceBC;
	cout << "Le perimetre est de : " << perimetre << endl;

	return 0;
}