#include<iostream>
#include<fstream>
#include <string>

using namespace std;

const int DIMENSION = 50;
struct typeOrdinateur
{
	string format;
	string compagnie;
	float tailleEcran;
	float cpu;
	int memoireRAM;
	int memoireDisque;
};
struct  typeListeOrdi
{
	typeOrdinateur liste[DIMENSION];
	int nombreOrdi;
};

bool lirefichier(string nomfichier, typeListeOrdi & tousOrdi)
{
	fstream fichier;
	fichier.open(nomfichier, ios::in);
	if (!fichier.fail())
	{
		tousOrdi.nombreOrdi = 0;

		while (!ws(fichier).eof()){

			fichier >> tousOrdi.liste[tousOrdi.nombreOrdi].format
				>> tousOrdi.liste[tousOrdi.nombreOrdi].compagnie
				>> tousOrdi.liste[tousOrdi.nombreOrdi].tailleEcran
				>> tousOrdi.liste[tousOrdi.nombreOrdi].cpu
				>> tousOrdi.liste[tousOrdi.nombreOrdi].memoireRAM
				>> tousOrdi.liste[tousOrdi.nombreOrdi].memoireDisque;
			tousOrdi.nombreOrdi++;
		}

		return true;
	}
	else
		return false;
}

void afficherlisteOrdi(typeListeOrdi tousOrdi)
{
	for (int i = 0; i < tousOrdi.nombreOrdi; i++)
		cout << tousOrdi.liste[i].compagnie << '\t'
		<< tousOrdi.liste[i].format << '\t'
		<< tousOrdi.liste[i].cpu << '\t'
		<< tousOrdi.liste[i].memoireRAM << '\t'
		<< tousOrdi.liste[i].tailleEcran << '\t'
		<< tousOrdi.liste[i].memoireDisque << endl;
}

int main(void)
{
	typeListeOrdi tousOrdi;

	if (lirefichier("ordi.txt", tousOrdi))
	{
		afficherlisteOrdi(tousOrdi);
	}
	else
		cout << "Fichier introuvable";


	return 0;
}