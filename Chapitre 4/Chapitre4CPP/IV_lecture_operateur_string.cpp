/**
*  Lecture du fichier mot par mot à l'aide de l'opérateur >>.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std; //[
int main()
{
	ifstream ficLu("IV_lecture.txt"); // L'ouverture du fichier
	if (ficLu.fail())                 // est incorrecte
		cout << " Probleme d'ouverture ";
	else {                            // est correcte.
		// Boucle de lecture du fichier, sautant les espaces.
		while (!ws(ficLu).eof()) {
			string motLu;
			// Lecture d'une chaîne avec l'opérateur >>.
			ficLu >> motLu;
			cout << motLu;
		}
		ficLu.close();
	}
}
 
//]
// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=//-,3< : foldseparator=-1