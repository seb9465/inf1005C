
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

// vérifier l'existence du fichier 
bool verifierExistenceFichier(string nomFichier, fstream &  fichierIn)
{
	fichierIn.open(nomFichier, ios::in);
	return (!fichierIn.fail());

}
// lire un fichier texte et mettre les infos dans le paramètre ensPersonne
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
// demander à l'usager  les info sur  un paramètre de type 
//typePersonne
void demanderInfoPersonne(typePersonne & unePersonne)
{
	cout << "Nom de la personne ";
	cin >> unePersonne.nom;
	cout << "Age de  la personne ";
	cin >> unePersonne.age;
}

//  ajouter le  parametre typePersonne & ajout  au paramètre  
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

// vérifier si on peut créer le fichier
//
bool verifierCreationFichierBinaire(string nomFichier, fstream & fichierOut)
{
	fichierOut.open(nomFichier, ios::out | ios::binary);
	return !fichierOut.fail();
}


// créer le fichier binaire à partir de du paramètre
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
			cout << "fichier binaire non crée " << endl;

		fichierIn.close();

	}
	else
		cout << "le fichier n'existe pas " << endl;

	return 0;
}

