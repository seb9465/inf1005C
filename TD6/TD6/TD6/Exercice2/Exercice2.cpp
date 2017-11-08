/**
* Représentation interne des données
* \fichier   Exercice2.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date    3 Décembre 2014
* Créé le 26 Novembre 2014
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void convertirEnBinaire(int nb, int resultat[32]){
	int resultatInv[32] = {};
	int cpt = 0;
	while (nb > 0){
		resultat[cpt] = nb % 2;
		nb = nb / 2;
		cpt++;
	}

	int cpt1 = 31;
	int cpt2 = 0;
	while (cpt1 >= 0){
		resultatInv[cpt2] = resultat[cpt1];
		cpt1--;
		cpt2++;
	}

	for (int i = 0; i < 32; i++)
		resultat[i] = resultatInv[i];
}

void afficherNombreBinaire(int nombreBin[32]){
	cout << "nombre en binaire = ";
	bool actif = false;
	for (int i = 0; i < 32; i++){
		if (!actif)
			actif = nombreBin[i] == 1;
		if (actif)
			cout << nombreBin[i];
	}
	cout << endl;
}

void convertirEnHex(const int nbBinaire[32], char nbHex[8]){

	for (int i = 0; i < 8; i++){
		int somme = 0;
		int cpt = 1;
		for (int j = 31 - 4 * i; j > 31 - 4 * (1 + i); j--){
			somme += cpt * nbBinaire[j];
			cpt = cpt * 2;
		}

		if (somme == 10)
			nbHex[i] = 'A';
		else if (somme == 11)
			nbHex[i] = 'B';
		else if (somme == 12)
			nbHex[i] = 'C';
		else if (somme == 13)
			nbHex[i] = 'D';
		else if (somme == 14)
			nbHex[i] = 'E';
		else if (somme == 15)
			nbHex[i] = 'F';
		else
			nbHex[i] = somme;

		cout << nbHex[i];
	}
}

int main()
{
	// TODO: Demander à l'utilisateur d'entrer un réel et le lire
	cout << "Entrez un nombre reel : ";
	float nombre;
	cin >> nombre;

	float* ptr = &nombre;
	// TODO: Découper en 4 blocs
	unsigned char* nb = (unsigned char*)ptr;
	cout << (*nb >> 8) << endl;
	cout << "bloc 1 : " << ((*nb & 0xFF00000) >> 24) << endl;
	cout << "bloc 2 : " << ((*nb & 0xFF000) >> 16) << endl;
	cout << "bloc 3 : " << ((*nb & 0xFF0) >> 8) << endl;
	cout << "bloc 4 : " << (*nb & 0xFF) << endl;

	// TODO: Afficher chaque bloc en hexadécimal
	unsigned nb1;
	cout << "Entrez un nombre : ";
	cin >> nb1;



	int resultatBinaire[32];
	for (int i = 0; i < 32; i++)
		resultatBinaire[i] = 0;
	char resultatHex[8] = {};
	for (int i = 0; i < 8; i++)
		resultatHex[i] = '0';

	convertirEnBinaire(nb1, resultatBinaire);
	afficherNombreBinaire(resultatBinaire);
	convertirEnHex(resultatBinaire, resultatHex);




	return 0;
}

