#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool creerFichierBinaire(string nomFichier, int nValeurs,
	int min, int max)
{
	ofstream fichier(nomFichier, ios::binary);
	if (!fichier.fail()) {
		srand(unsigned(time(nullptr)));
		for (int i = 0; i < nValeurs; i++) {
			double nombre = (rand() % (max*100 - min*100) + min*100) / 100.0;
			fichier.write((char*)&nombre, sizeof(nombre));
		}
		fichier.close();
		return true;
	}
	else {
		return false;
	}
}

void lireFichierReels(string nomFichier) {
	ifstream fichierReels(nomFichier, ios::binary);
	fichierReels.seekg(0, ios::end);
	cout << fichierReels.tellg() << endl;
	cout << sizeof(double) << endl;
	int nElements = int(fichierReels.tellg() / sizeof(double));
	fichierReels.seekg(0, ios::beg);
	for (int i = 0; i < nElements; i++) {
		double nombre;
		fichierReels.read((char*)&nombre, sizeof(nombre));
		cout << nombre << endl;
	}
}

void lireFichierEntiers(string nomFichier) {
	ifstream fichierReels(nomFichier, ios::binary);
	fichierReels.seekg(0, ios::end);
	cout << fichierReels.tellg() << endl;
	cout << sizeof(int) << endl;
	int nElements = int(fichierReels.tellg() / sizeof(int));
	fichierReels.seekg(0, ios::beg);
	for (int i = 0; i < nElements; i++) {
		int nombre;
		fichierReels.read((char*)&nombre, sizeof(nombre));
		cout << nombre << endl;
	}
}

int main()
{
	int min, max, nValeurs;
	cout << "Entrer le minimum : ";
	cin >> min;
	cout << "Entrer le maximum : ";
	cin >> max;
	cout << "Entrer le nombre de valeurs : ";
	cin >> nValeurs;

	if (creerFichierBinaire("reels.bin", nValeurs, min, max)) {
		cout << "Fichier créé" << endl;
		lireFichierReels("reels.bin");
		cout << endl;
		lireFichierEntiers("reels.bin");
	}
	else {
		cout << "Fichier non créé" << endl;
	}

	return 0;
}