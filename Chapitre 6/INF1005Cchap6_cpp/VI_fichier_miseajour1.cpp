#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// Fichier en lecture et écriture.
	fstream fichier("entier.bin", ios::in|ios::out|ios::binary);

	// Modifier la troisième valeur du fichier.
	int valeur = 33;
	fichier.seekp(2*sizeof(valeur), ios::beg);     // Positionnement.
	fichier.write((char*)&valeur, sizeof(valeur)); // Écriture.
	fichier.close();
}
