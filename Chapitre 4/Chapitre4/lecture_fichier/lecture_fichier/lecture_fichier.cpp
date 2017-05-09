/**
*  Lecture d'un fichier.
*/
#include <iostream>
#include <fstream>
using namespace std; //[
int main()
{
	ifstream fichier("lecture_fichier.txt");
	fichier.exceptions(ios::failbit);

	int somme = 0;
	// Boucle tant qu'il reste autre chose que des espaces.
	while (!ws(fichier).eof()) 
	{        //-
		int val1, val2, val3;
		fichier >> val1 >> val2 >> val3; //- Lire les données.

		somme += val1 + val2 + val3;     //- Traitement.
	}
	cout << "La somme est " << somme;
	fichier.close();
}

//]
// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=//-,3< : foldseparator=-1