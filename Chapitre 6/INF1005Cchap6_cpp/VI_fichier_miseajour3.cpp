#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	// Fichier en lecture et écriture.
	fstream fichier("entier.bin", ios::in|ios::out|ios::binary);

	// Modifier la troisième valeur du fichier.
	int valeur;
	fichier.seekg(2*sizeof(valeur), ios::beg); // Positionnement.
	fichier.read((char*)&valeur, sizeof(valeur));
	cout << "La valeur actuelle est : " << valeur << endl;
	cout << "Nouvelle valeur : ";
	cin >> valeur;
	
	fichier.seekp(-1*streamoff(sizeof(valeur)), ios::cur); // Repositionnement.
	fichier.write((char*)&valeur, sizeof(valeur));
	fichier.close();
}
