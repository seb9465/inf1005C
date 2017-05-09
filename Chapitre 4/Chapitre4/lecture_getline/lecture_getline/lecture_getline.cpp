/**
*  Lecture du fichier ligne par ligne à l'aide de la fonction getline().
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std; //[
int main()
{
	ifstream ficLu("lecture.txt"); // L'ouverture du fichier
	if (ficLu.fail())                 // est incorrecte
		cout << " Probleme d'ouverture ";
	else {                            // est correcte.
		// Boucle de lecture du fichier, incluant les espaces.
		while (ficLu.peek() != EOF) {
			string ligneLue;
			// Lecture d'une chaîne avec la fonction getline.
			getline(ficLu, ligneLue);
			cout << ligneLue << endl;
		}
		ficLu.close();
	}
}

//]
// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=//-,3< : foldseparator=-1