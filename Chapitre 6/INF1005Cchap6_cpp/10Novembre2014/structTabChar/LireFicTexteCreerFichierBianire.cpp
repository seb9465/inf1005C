
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

const int DIMENSION = 50;

struct typePersonne
{
	char nom[40];
	int age;
};

struct typeListePersonne
{
	typePersonne tousPersonne[DIMENSION];
	int nbPersonne;
};

// v�rifier l'existence du fichier 
bool verifierExistenceFichier(string nomFichier, fstream &  fichierIn)
{
	fichierIn.open(nomFichier, ios::in);
	return (!fichierIn.fail());

}
// lire un fichier texte et mettre les infos dans le param�tre ensPersonne
// de type typeListePersonne
void lectureFichierTexte(fstream & fichierIn, typeListePersonne & ensPersonne)
{

	ensPersonne.nbPersonne = 0;
	while (!ws(fichierIn).eof())
	{
		fichierIn >> ensPersonne.tousPersonne[ensPersonne.nbPersonne].nom;
		fichierIn >> ensPersonne.tousPersonne[ensPersonne.nbPersonne].age;
		ensPersonne.nbPersonne++;
	}

}
// demander � l'usager  les info sur  un param�tre de type 
//typePersonne
void demanderInfoPersonne(typePersonne & unePersonne)
{
	cout << "Nom de la personne ";
	cin >> unePersonne.nom;
	cout << "Age de  la personne ";
	cin >> unePersonne.age;
}

//  ajouter le  parametre typePersonne & ajout  au param�tre  
// typeListePersonne & ensPersonne
bool ajouterPersonne(typeListePersonne & ensPersonne, typePersonne & ajout)
{
	if (ensPersonne.nbPersonne < DIMENSION)
	{
		ensPersonne.tousPersonne[ensPersonne.nbPersonne] = ajout;
		ensPersonne.nbPersonne++;
		return true;
	}
	else
		return false;
}

// v�rifier si on peut cr�er le fichier
//
bool verifierCreationFichierBinaire(string nomFichier, fstream & fichierOut)
{
	fichierOut.open(nomFichier, ios::out | ios::binary);
	return !fichierOut.fail();
}


// cr�er le fichier binaire � partir de du param�tre
// typeListePersonne  ensPersonne
void creerFichierBinaire(fstream & fichierOut, typeListePersonne  ensPersonne)
{
	for (int i = 0; i < ensPersonne.nbPersonne; i++)

		fichierOut.write((char *)& ensPersonne.tousPersonne[i], sizeof(typePersonne));
}

// afficher les infos de typeListePersonne  ensPersonne
void afficherInfoPersonne(typeListePersonne  ensPersonne)
{
	for (int i = 0; i < ensPersonne.nbPersonne; i++)
		cout << ensPersonne.tousPersonne[i].nom << " \t"
		<< ensPersonne.tousPersonne[i].age << endl;
}



int main()
{

	fstream fichierIn;
	string nomFichier;

	cout << "donner le nom du fichier ";
	cin >> nomFichier;
	if (verifierExistenceFichier(nomFichier, fichierIn))
	{
		typeListePersonne ensPersonne;
		lectureFichierTexte(fichierIn, ensPersonne);
		afficherInfoPersonne(ensPersonne);

		typePersonne unePersonne;
		demanderInfoPersonne(unePersonne);
		ajouterPersonne(ensPersonne, unePersonne);
		afficherInfoPersonne(ensPersonne);

		cout << "donner le nom du fichier binaire ";
		cin >> nomFichier;

		fstream fichierOut;
		if (verifierCreationFichierBinaire(nomFichier, fichierOut))
		{
			creerFichierBinaire(fichierOut, ensPersonne);
			fichierOut.close();
		}
		else
			cout << "fichier binaire non cr�e " << endl;

		fichierIn.close();

	}
	else
		cout << "le fichier n'existe pas " << endl;

	return 0;
}

