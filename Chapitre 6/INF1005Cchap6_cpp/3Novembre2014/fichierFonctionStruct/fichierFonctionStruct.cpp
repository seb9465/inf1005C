#include<iostream>
#include<fstream>
#include <string>

using namespace std;


struct typeOrdinateur
{
	string format;
	string compagnie;
	float tailleEcran;
	float cpu;
	int memoireRAM;
	int memoireDisque;
};


bool lirefichier(string nomfichier, typeOrdinateur  tousOrdi[], 
	            int & nombreOrdi)
{
	fstream fichier;
	fichier.open(nomfichier, ios::in);
	if (!fichier.fail())
	{
		nombreOrdi = 0;

		while (!ws(fichier).eof()){
			fichier >> tousOrdi[nombreOrdi].format
				>> tousOrdi[nombreOrdi].compagnie
				>> tousOrdi[nombreOrdi].tailleEcran
				>> tousOrdi[nombreOrdi].cpu
				>> tousOrdi[nombreOrdi].memoireRAM
				>> tousOrdi[nombreOrdi].memoireDisque;
			nombreOrdi++;
		}

		return true;
	}
	else
		return false;
}

void afficherlisteOrdi(typeOrdinateur  tousOrdi[], int  nombreOrdi)
{
	for (int i = 0; i < nombreOrdi; i++)
		cout << tousOrdi[i].compagnie << '\t'
		<< tousOrdi[i].format << '\t'
		<< tousOrdi[i].cpu << '\t'
		<< tousOrdi[i].memoireRAM << '\t'
		<< tousOrdi[i].tailleEcran << '\t'
		<< tousOrdi[i].memoireDisque << endl;
}
const int DIMENSION = 50;
int main()
{
	typeOrdinateur tousOrdi[DIMENSION];
	int nombreOrdi;
	if (lirefichier("ordi.txt", tousOrdi, nombreOrdi))
	{
		afficherlisteOrdi(tousOrdi, nombreOrdi);
	}
	else
		cout << "Fichier introuvable";


	return 0;
}