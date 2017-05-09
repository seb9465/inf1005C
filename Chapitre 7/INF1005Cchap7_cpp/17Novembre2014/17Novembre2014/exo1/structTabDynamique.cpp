#include <iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<string>
using namespace std;

struct typeTableau
{
	int* liste;
	int nbElements;
};

void reserverMemoire(typeTableau & tous)
{
	tous.liste = new int[tous.nbElements];
}

void libererMemoire(typeTableau  & tous)
{
	delete[] tous.liste;
	tous.liste = 0;
	tous.nbElements = 0;
}
bool verifierExistenceFichier(string nomFichier, ifstream & lecture)
{
	lecture.open(nomFichier);
	return (!lecture.fail());

}
int trouverNombreElement(ifstream & lecture)
{
	int nbValeur = 0;
	int valeur;
	while (!ws(lecture).eof())
	{
		nbValeur++;
		lecture >> valeur;
	}
	lecture.clear();
	lecture.seekg(0, ios::beg);
	return nbValeur;
}
void lecturefichier(ifstream & lecture, typeTableau & tous)
{
	for (int i = 0; i < tous.nbElements; i++)
		lecture >> tous.liste[i];	
}

void afficherTableau(typeTableau  tous)
{
	cout << " affichage Tableau" << endl;
	for (int i = 0; i < tous.nbElements; i++)
		cout <<  tous.liste[i]<<endl;
}

void ajouterUnElement (typeTableau & tous, int ajout)
{
	int* memoireTemp;
	memoireTemp = new  int[tous.nbElements + 1];
	for (int i = 0; i < tous.nbElements; i++)
		memoireTemp[i] = tous.liste[i];
	memoireTemp[tous.nbElements] = ajout;
	tous.nbElements++;
	delete[] tous.liste;
	tous.liste = memoireTemp;

}
int main()
{
	string nomFichier;
	cout << "Quel est le nom du fichier :";
	cin >> nomFichier;
	typeTableau tous;
	ifstream fichier;
	if (verifierExistenceFichier(nomFichier, fichier))
	{
		tous.nbElements = trouverNombreElement(fichier);
		reserverMemoire(tous);
		lecturefichier(fichier, tous);
		afficherTableau(tous);
		ajouterUnElement(tous, 55);
		afficherTableau(tous);
		libererMemoire(tous);
		fichier.close();
	}
	else
		cout << " fichier non existe";

	return 0;
}
