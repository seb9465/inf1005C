/**
*  Lecture du fichier caractère par caractère avec la fonction get().
*/
#include <iostream>
#include <fstream>

using namespace std; //[
int main()
{
	ifstream ficLu("IV_lecture.txt"); // L'ouverture du fichier
	if (ficLu.fail())                 // est incorrecte
		cout << " Probleme d'ouverture ";
	else {                            // est correcte.
		// Boucle de lecture du fichier, incluant les espaces.
		while (ficLu.peek() != EOF) { 
			char carLu;
			// Lecture d'un caractère avec get.
			ficLu.get(carLu);
			cout << carLu;
		}
		ficLu.close();
	}
}
 
//]
// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=//-,3< : foldseparator=-1