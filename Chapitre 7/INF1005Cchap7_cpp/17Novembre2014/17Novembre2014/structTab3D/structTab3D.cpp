#include<iostream>
#include<fstream>
using namespace std;

struct typeTableau
{
	int nbLignes, nbColonnes, nbProfondeurs;
	int*** element3d;
};

int *** alloue3D(int nbLignes, int nbColonnes, int nbProfondeurs)
{
	int*** tableau;
	tableau = new int**[nbLignes];
	
	for (int i = 0; i < nbLignes; i++)
	{
		tableau[i] = new int*[nbColonnes];
		for (int j = 0; j < nbColonnes; j++)	
			tableau[i][j] = new int[nbProfondeurs];				
	}
	return tableau;
}
void detruire3D(int*** tableau, int nbLignes, int nbColonnes)
{
	for (int i = 0; i < nbLignes; i++)
	{
		for (int j = 0; j < nbColonnes; j++)
		{
			delete[]tableau[i][j];
		}
		delete[]tableau[i];
	}
	delete[]tableau;
}

void afficherTableau3D(typeTableau tableau)
{
	for (int k = 0; k < tableau.nbProfondeurs; k++)
	{
		cout << "Profondeur " << k << endl;
		for (int i = 0; i < tableau.nbLignes; i++)
		{
			for (int j = 0; j < tableau.nbColonnes; j++)
				cout << tableau.element3d[i][j][k] << "\t";
			cout << endl;
		}
	}
}

void main()
{
	ifstream fichier;
	typeTableau tableau3D;

	fichier.open("donnees3.txt");
	if (!fichier.fail())
	{
		fichier >> tableau3D.nbLignes >> tableau3D.nbColonnes >> tableau3D.nbProfondeurs;
		if (!fichier.eof())
		{
			tableau3D.element3d = alloue3D(tableau3D.nbLignes, tableau3D.nbColonnes, tableau3D.nbProfondeurs);
			
				for (int k = 0; k < tableau3D.nbProfondeurs; k++)
					for (int i = 0; i < tableau3D.nbLignes; i++)
						for (int j = 0; j < tableau3D.nbColonnes; j++)
							fichier >> tableau3D.element3d[i][j][k];
				fichier.close();
				afficherTableau3D(tableau3D);
				detruire3D(tableau3D.element3d, tableau3D.nbLignes, tableau3D.nbColonnes);				
		}
		else
			cout << "Fichier Vide" << endl;
	}
	else
		cout << "Le fichier n'existe pas" << endl;

}