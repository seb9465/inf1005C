/**
* Programme pour manipulation et gestion d'une Collection
* \fichier   Exercice1.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date    3 Décembre 2014
* Créé le 26 Novembre 2014
*/

#pragma region "Includes"//{
#define _CRT_SECURE_NO_WARNINGS // On permet d'utiliser les fonctions de copies de chaînes qui sont considérées non sécuritaires.
#include <iostream>
#include <fstream>
#include <string>
#include <cwchar>
#include <limits>
#ifdef _MSC_VER
#include <io.h>      // Pour _setmode et _fileno
#include <fcntl.h>   // Pour _O_U8TEXT et _O_U16TEXT
#endif
int cin, cout; // Après l'initialisation d'Unicode, cin et cout plantent si on tente de les utiliser.  Ces variables feront une erreur de compilation "symbole ambigu" si le programme tente d'utiliser cin ou cout, pour détecter le problème à la compilation plutôt qu'à l'exécution.

#include "Structures.h"

//{ Pour avoir un rapport de fuites incluant les numéros de lignes où l'allocation a été faite.
// (source http://msdn.microsoft.com/en-us/library/x98tx3cf%28v=vs.100%29.aspx)
#define _CRTDBG_MAP_ALLOC ///< Utilise les allocations avec débogage.
#include <stdlib.h>
#include <crtdbg.h>
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ ) ///< Ajoute le numéro de ligne au rapport de fuites.
//}
using namespace std;
#pragma endregion//}

#pragma region "Fonctions pour Unicode"//{

/*************************************************************************//**
*  Initialise la bibliothèque pour pouvoir afficher en Unicode.
*  \return  \c true si réussi.
*/
bool initUnicode()
{
	bool reussi;
	// Sélectionne les paramètres régionnaux par défaut.
	reussi = setlocale(LC_ALL, "") != 0;

	// Sélectionne le mode de sortie et d'entrée;
	// nécessaire sur VisualC mais pas GCC et Clang.
#ifdef _MSC_VER
	reussi = _setmode(_fileno(stdout), _O_U8TEXT) != -1 && reussi;
	reussi = _setmode(_fileno(stdin), _O_U16TEXT) != -1 && reussi;
#endif
	return reussi;
}

/*************************************************************************//**
*  Conversion de 'wstring' en 'string' Latin-1.
*/
string versString(const wstring& chaine) {
	static const char CARACTERE_INCONNU = '?';
	string resultat;
	resultat.resize(chaine.length());
	for (size_t i = 0; i < chaine.length(); ++i) {
		if (chaine[i] < 256)
			resultat[i] = char(chaine[i]);
		else // Le caractère n'existe pas en 'char'.
			resultat[i] = CARACTERE_INCONNU;
	}
	return resultat;
}

/*************************************************************************//**
*  Conversion de 'string' Latin-1/ASCII en 'wstring'.
*/
wstring versWstring(const string& chaine) {
	wstring resultat;
	resultat.resize(chaine.length());
	for (size_t i = 0; i < chaine.length(); ++i)
		resultat[i] = chaine[i] & 0xFF;
	return resultat;
}

/*************************************************************************//**
*  Permet d'afficher une 'string' sur 'wcout' avec l'opérateur << standard.
*/
wostream& operator <<(wostream& flot, const string& chaine)
{
	return flot << versWstring(chaine);
}

#pragma endregion//}

//TODO: Mettre le bon type de retour.
void afficherCollection(Collection collec);
Collection chargerCollection(wstring nomFichier) //TODO: Mettre les bons paramètres.
{
	Collection collec = {};
	//TODO: Ouvrir le fichier qui contient la collection à charger
	string nomFic = versString(nomFichier);
	fstream fichier;
	fichier.open(nomFic, ios::binary | ios::in);

	//TODO: Trouver le nombre de livres dans la collection
	fichier.seekg(0, ios::end);
	int nbElements = fichier.tellg() / sizeof(Livre);
	fichier.seekg(0, ios::beg);

	//TODO: Assigner les bonnes valeurs aux champs nLivres et nLivresAlloues de la collection.
	collec.nLivresAlloues = nbElements + 3;
	collec.nLivres = nbElements;

	//TODO: Allouer l'espace dans le champs livres de la collection
	collec.livres = new Livre *[collec.nLivresAlloues];

	//TODO: Charger les livres du fichier dans la collection, en allouant chaque livre
	for (int i = 0; i < collec.nLivres; i++){
		Livre livre;
		fichier.read((char*)&livre, sizeof(Livre));
		collec.livres[i] = new Livre;
		strncpy(collec.livres[i]->cote, livre.cote, 8);
		wcsncpy(collec.livres[i]->titre, livre.titre, 50);
		collec.livres[i]->anneeEdition = livre.anneeEdition;
		collec.livres[i]->nExemplaires = livre.nExemplaires;
		collec.livres[i]->nDisponibles = livre.nDisponibles;
	}
	//TODO: Retourner la collection
	return collec;
}

//TODO: Mettre le bon type de retour.
void dechargerCollection(Collection& collec) //TODO: Mettre les bons paramètres.
{
	//TODO: Libérer tout l'espace alloué dynamiquemet dans la collection
	for (int i = 0; i < collec.nLivres; i++){
		delete[] collec.livres[i];
	}
	delete[] collec.livres;
	//TODO: Assigner les bonnes valeurs aux champs de la collection pour s'assurer qu'une tentative d'accès à la collection déchargée causera une erreur
	collec.livres = 0;
	collec.nLivres = 0;
	collec.nLivresAlloues = 0;
}

//TODO: Mettre le bon type de retour.
Collection retrouverLivresParNom(wchar_t chaine[50], Collection collec) //TODO: Mettre les bons paramètres.
{
	Collection livreTrouve;
	livreTrouve.nLivresAlloues = 0;
	// TODO: Retrouver les livres dans la collection dont le titre correspond à la recherche
	for (int i = 0; i < collec.nLivres; i++){
		bool trouve = wcsstr(collec.livres[i]->titre, chaine) != NULL;
		if (trouve)
			livreTrouve.nLivresAlloues++;
	}

	// TODO: Allouer l'espace qui contiendra le tableau des livres trouvés
	livreTrouve.livres = new Livre *[livreTrouve.nLivresAlloues];

	// TODO: Copier les pointeurs vers les livres trouvés
	livreTrouve.nLivres = 0;
	for (int i = 0; i < collec.nLivres; i++){
		bool trouve = wcsstr(collec.livres[i]->titre, chaine) != NULL;
		if (trouve){
			livreTrouve.livres[livreTrouve.nLivres] = collec.livres[i];
			livreTrouve.nLivres++;
		}
	}

	// TODO: Retourner le nombre de livres trouvés
	return livreTrouve;
}

//TODO: Mettre le bon type de retour.
void ajouterLivre(Collection& collec) //TODO: Mettre les bons paramètres.
{
	Livre nouvLivre;

	// Lire le livre du clavier
	wcout << "Entrez la cote : ";
	wstring cote;
	wcin >> cote;
	strncpy(nouvLivre.cote, versString(cote).c_str(), 8);

	wcout << "Entrez le titre : ";
	wstring titre;
	wcin >> titre;
	wcsncpy(nouvLivre.titre, titre.c_str(), 50);

	wcout << "Entrez l'annee d'edition : ";
	short anneeEdition;
	wcin >> anneeEdition;
	nouvLivre.anneeEdition = anneeEdition;

	wcout << "Entrez le nombre d'exemplaire : ";
	int nExemplaires;
	wcin >> nExemplaires;
	nouvLivre.nExemplaires = nExemplaires;

	wcout << "Entrez le nombre disponible : ";
	int nDisponible;
	wcin >> nDisponible;
	nouvLivre.nDisponibles = nDisponible;

	// TODO: Vérifier qu'il y a assez de place pour ajouter un livre.
	if (collec.nLivres < collec.nLivresAlloues){
		// TODO: Si il n'y a pas assez de place. Augmenter la taille du tableau dans la collection.
		Livre** nouvelleListe = new Livre*[collec.nLivresAlloues + 3];
		for (int i = 0; i < collec.nLivres; i++)
			nouvelleListe[i] = collec.livres[i];
		delete[]collec.livres;
		collec.livres = nouvelleListe;
		collec.nLivresAlloues += 3;
	}
	// TODO: Ajouter le livre à la collection
	collec.livres[collec.nLivres + 1] = new Livre;
	(*collec.livres[collec.nLivres + 1]) = nouvLivre;
	collec.nLivres++;
}

//TODO: Mettre le bon type de retour.
bool sauvegarderCollection(Collection collec, wstring nomFichier) //TODO: Mettre les bons paramètres.
{
	bool estOk = true;
	// TODO: Ouvrir le fichier
	ofstream fichier(versString(nomFichier), ios::binary);
	if (fichier.fail()){
		fichier.open(versString(nomFichier), ios::binary | ios::trunc);
		if (fichier.fail())
			estOk = false;
	}
	else
	{
		// TODO: Écrire les livres contenus dans la collection
		for (int i = 0; i < collec.nLivres; i++){
			fichier.write((char *)& collec.livres[i], sizeof(Livre));
		}
	}
	return estOk;
}

//TODO: Ajouter d'autres fonctions, pour le menu et l'affichage.


void afficherCollection(Collection collec){
	if (collec.nLivres == 0)
		wcout << "Collection vide." << endl;
	for (int i = 0; i < collec.nLivres; i++){
		wcout << "Cote : " << collec.livres[i]->cote << endl
			<< "Titre : " << collec.livres[i]->titre << endl
			<< "Annee Edition : " << collec.livres[i]->anneeEdition << endl
			<< "Nombre Exemplaires : " << collec.livres[i]->nExemplaires << endl
			<< "Nombre Disponible : " << collec.livres[i]->nDisponibles << endl << endl;
	}
}
void afficherMenu(){
	wcout << "MENU" << endl
		<< "1. Charger collection." << endl
		<< "2. Afficher collection." << endl
		<< "3. Retrouver un livre par son titre." << endl
		<< "4. Ajouter un livre." << endl
		<< "5. Sauvegarder la collection." << endl
		<< "6. Quitter." << endl;
}
void menuUn(Collection &collec){
	wcout << "MENU 1 - CHARGER COLLECTION" << endl
		<< "Entrez le nom du fichier à charger : ";
	wstring nomFichier;
	wcin >> nomFichier;
	collec = chargerCollection(nomFichier);
}
void menuDeux(Collection collec){
	wcout << "MENU 2 - AFFICHER COLLECTION" << endl;
	afficherCollection(collec);
}
void menuTrois(Collection collec){
	wcout << "MENU 3 - RETROUVER UN LIVRE PAR SON TITRE" << endl;
	wcout << "Entrez une chaine de caractere : ";
	wchar_t chaine[50];
	wcin >> chaine;
	Collection trouve = retrouverLivresParNom(chaine, collec);
	wcout << "AFFICHAGE LIVRES TROUVES" << endl;
	afficherCollection(trouve);
}
void menuQuatre(Collection &collec){
	wcout << "MENU 4 - AJOUTER UN LIVRE" << endl;
	ajouterLivre(collec);
}
void menuCinq(Collection collec){
	wcout << "MENU 5 - SAUVEGARDER LA COLLECTION" << endl
		<< "Entrez le nom du fichier pour la sauvegarde : ";
	wstring nomFichier;
	wcin >> nomFichier;
	sauvegarderCollection(collec, nomFichier);
}
void menuSix(bool &estFin){
	estFin = true;
	wcout << "FIN DU PROGRAMME." << endl;
}
void menu(Collection &uneCollection){
	bool estFin = false;
	bool estActif = false;
	do{
		afficherMenu();
		wcout << endl << "Entrez votre choix : ";
		wchar_t choix;
		wcin >> choix;
		wcout << endl;

		switch (choix){
		case '1':
			if (estActif) { dechargerCollection(uneCollection); }
			menuUn(uneCollection);
			estActif = true;
			break;
		case '2': if (estActif) { menuDeux(uneCollection); }
				  break;
		case '3': if (estActif) { menuTrois(uneCollection); }
				  break;
		case '4': if (estActif) { menuQuatre(uneCollection); }
				  break;
		case '5': if (estActif) { menuCinq(uneCollection); }
				  break;
		case '6': menuSix(estFin);
			break;
		}



	} while (!estFin);
}
/*************************************************************************//**
*  Fonction principale.
*/
int main()
{
	_CrtSetDbgFlag(0
		| _CRTDBG_ALLOC_MEM_DF    // Débogage d'allocation mémoire.
		| _CRTDBG_LEAK_CHECK_DF   // Rapport de fuites à la sortie du programme.  Noter que le rapport de fuites sera affiché dans la fenêtre "Sortie" de Visual Studio.
		| _CRTDBG_CHECK_ALWAYS_DF // Vérifie la corruption à chaque new/delete (lent).
		);
	initUnicode();

	// TODO: Afficher un menu et éxecuter les fonctions selon les choix 
	Collection uneCollection;
	menu(uneCollection);

	return 0;
}