//  demander la taille d'une matrice 
// Fonction lecture par un usager de  la matrice
// Fonction afficher le contenu de la matrice
// Fonction trouver le plus grand élément et  le plus petit
// fonction  pour vérifier si la diagonale de la matrice est nulle
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
const  int DIMENSION = 10;

void remplirMatrice(int tableau[][DIMENSION], int taille)
{

	srand(time(nullptr));
	for (int i = 0; i < taille; i++)
		for (int j = 0; j < taille; j++)
		tableau[i][j] = rand();

}

int main()
{
	int taille;
	 
	int liste[DIMENSION][DIMENSION] = {};

	cout << " dimension";
	cin >> taille;

	remplirMatrice(liste, taille);

}