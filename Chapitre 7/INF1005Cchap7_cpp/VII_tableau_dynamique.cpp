#include <iostream>
using namespace std;
int main()
{
//[
	// Déclaration d'un tableau d'entiers à une dimension.
	int* vecteur;
	
	// Attribution d’un tableau de 150 entiers.
	vecteur = new int[150];
	
	// Adresses du tableau et des cases.
	cout << "Adresse du tableau: " << vecteur << endl;
	for (int i=0; i<3; i++)
		cout << "&vecteur[" << i << "] est " << &vecteur[i] << "; ";
	cout << endl;
	
	// Initialise chaque valeur du tableau à 0.
	for (int i=0; i<150; i++)
		vecteur[i] = 0;
	
	// Remet en disponibilité l'espace mémoire du tableau d'entiers.
	delete[] vecteur;
	vecteur = 0;

	// Affiche:
	// Adresse du tableau: 00032F00
	// &vecteur[0] est 00032F00; &vecteur[1] est 00032F04; &vecteur[2] est 00032F08;
//]
//[
	// Déclaration d'un tableau de réels à deux dimensions,
	// pemettant des lignes de longueurs différentes:
	double** matrice;
	
	// Attribution de l'espace pour un tableau de 20 lignes x 30 colonnes:
	matrice = new double* [20];           // Espace pour les 20 pointeurs de lignes.
	for (int ligne=0; ligne<20; ligne++)  // Pour chaque ligne,
		matrice[ligne] = new double[30];  // espace pour 30 colonnes de la ligne.
	
	// Initialise chaque valeur de la matrice à zéro:
	for (int ligne=0; ligne<20; ligne++)
		for (int colonne=0; colonne<30; colonne++)
			matrice[ligne][colonne] = 0.0;
	
	// Libération de l'espace mémoire:
	for (int ligne=0; ligne<20; ligne++) // Pour chaque ligne,
		delete[] matrice[ligne];         // libérer l'espace pour la ligne.
	
	delete[] matrice;  // Libérer l'espace mémoire des pointeurs de lignes.
	matrice = 0;
	
//]
//[
	// Déclaration d'un tableau de réels à "deux dimensions",
	// en utilisant un tableau une dimension:
	double* matrice2;
	
	// Attribution de l'espace pour un tableau de 20 lignes x 30 colonnes:
	int largeurMatrice2 = 30;
	int hauteurMatrice2 = 20;
	matrice2 = new double [hauteurMatrice2 * largeurMatrice2];
	
	// Initialise chaque valeur de la matrice à zéro:
	for (int ligne=0; ligne<20; ligne++)
		for (int colonne=0; colonne<30; colonne++)
			matrice2[ligne*largeurMatrice2 + colonne] = 0.0;
	
	// Libération de l'espace mémoire:
	delete[] matrice2;
	
//]
}