#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// Ouverture du fichier en lecture uniquement.
	ifstream fichier("entier.bin", ios::binary);

	// Lecture et affichage du contenu du fichier.
	while (fichier.peek() != EOF) {
		int valeur;
		fichier.read((char*)&valeur, sizeof(valeur));
		cout << valeur << endl;
	}
	fichier.close();
}
