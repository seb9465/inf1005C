#include <iostream> // Pour l'utilisation de cin et cout.
#include <fstream>  // Pour l'utilisation des fichiers.
#include <string>   // Pour l'utilisation des strings.
using namespace std;

int main()
{
	cout << " Quel est le nom du fichier a lire: ";
	string nomFichier;
	cin >> nomFichier;
	ifstream entree(nomFichier); // Ouverture en lecture de entree.
	//NOTE: Avant C++11 il fallait utiliser nomFichier.c_str()
	
	string mot;
	entree >> mot;
	cout << "Le premier mot du fichier est: " << mot << endl;
}
