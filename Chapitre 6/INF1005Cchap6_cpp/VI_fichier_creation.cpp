#include <fstream>
using namespace std;

int main()
{
	// Ouverture et création du fichier, en écriture uniquement.
	ofstream fichier("entier.bin", ios::binary);

	// Inscription des valeurs 10, 20, 30, 40 et 50.
	for (int i = 1; i <= 5; i++) {
		int valeur = i * 10;
		fichier.write((char*)&valeur, sizeof(valeur));
	}
	fichier.close();
}
