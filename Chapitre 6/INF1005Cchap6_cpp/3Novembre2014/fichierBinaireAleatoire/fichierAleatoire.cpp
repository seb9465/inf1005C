
// créeer un fichier binaire de valeurs aleatoires  paires
// l'usager  donne le nombre de fois  que  l'on veut créer des valeurs aléatoires

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
	int nbrFois, valeur, i;
	int nombrePair = 0;
	ofstream ecriture("alea.bin", ios::binary);
	if (!ecriture.fail())
	{
		srand(time(0));
		cout << "veuillez entrer le nombre de fois" << endl;
		cin >> nbrFois;
		for (i = 0; i < nbrFois; i++)
		{
			valeur = rand();
			if (valeur % 2 == 0)
			{
				nombrePair++;
				ecriture.write((char*)&valeur, sizeof(valeur));
			}
		}
		cout << nombrePair << endl;
		cout << sizeof(int) << endl;
		ecriture.seekp(0, ios::end);
		cout << ecriture.tellp();
		ecriture.close();
	}
	else
		cout << "impossible de creer le fichier" << endl;
	return 0;
}
