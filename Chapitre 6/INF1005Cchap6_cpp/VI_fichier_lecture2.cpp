#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// Ouverture du fichier en lecture uniquement.
	ifstream fichier("entier.bin", ios::binary);

	// Déterminer le nombre d'éléments dans le fichier.
	fichier.seekg(0, ios::end); // Positionnement à la fin.
	int nElements = int(fichier.tellg() / sizeof(int));

	fichier.seekg(0, ios::beg); // Repositionnement au début.
	// Lecture et affichage du contenu du fichier.
	for (int i = 0; i < nElements; i++) {
		int valeur;
		fichier.read((char*)&valeur, sizeof(valeur));
		cout << valeur << endl;
	}
	fichier.close();
}
