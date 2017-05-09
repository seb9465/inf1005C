/**
*  Fichier texte.
*/ //[
#include <fstream>
#include <string>
using namespace std;

int main()    
{
	ifstream entree("III_original.txt"); // Ouverture du fichier d'entrée à lire.
	ofstream sortie("III_copie.txt");    // Ouverture du fichier de sortie à créer.
	
	string mot;
	entree >> mot;              // Lecture d'un mot de entree.
	sortie << mot << endl;      // Écriture du mot lu dans sortie.
	int nombre;
	entree >> nombre;           // Lecture d'un nombre de entree.
	sortie << nombre << endl;   // Écriture du nombre lu dans sortie.
	string phrase;
	getline(entree, phrase);    // Lecture d'une phrase de entree.
	sortie << phrase << endl;   // Écriture de la phrase lue dans sortie.
	
	entree.close();             // Fermeture d'un
	sortie.close();             // et de l'autre fichier.
}
 
 
//]