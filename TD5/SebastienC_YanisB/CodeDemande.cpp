/**
* Différentes opérations sur un nombre.
* \fichier   CodeDemande.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   22 Novembre 2014
* Créé le 12 Novembre 2014
*/


#pragma region "Includes"//{ -------------------------------------------------

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "CodeFourni.hpp"

#include "CodeDemande.hpp"

using namespace std;

#pragma endregion//}


#pragma region "Fonctions"//{ ------------------------------------------------


// TODO: Trouver si la cible à insérer est présente dans la liste.
// TODO: Si la cible est présente, alors la remplacer par la valeur donnée.
// TODO: Si la cible n'est pas présente, alors l'ajouter à la fin s'il y assez
//       de place dans la liste.
// TODO: Trier la liste.
void insererCible(ListeCibles& listeCible, Cible cible)
{
	bool estTrouve = false;
	int nbElements = (int)listeCible.nbElems;
	for (int i = 0; i < nbElements && !estTrouve; i++){
		estTrouve = listeCible.elems[i].id == cible.id;
		if (estTrouve){
			listeCible.elems[i] = cible;
		}
	}
	if (nbElements < (int)MAX_NB_CIBLES && !estTrouve){
		listeCible.elems[(int)listeCible.nbElems] = cible;
		listeCible.nbElems++;
	}
	trierListeCibles(listeCible);
}


// TODO: Ouvrir le fichier texte en entrée.
// TODO: Lire chaque ligne et la convertir en cible.
// TODO: Insérer la cible dans la liste.
void importerCibles(ListeCibles& listeCibles, string nomFichier)
{
	ifstream fichier(nomFichier);
	if (!fichier.fail()){
		string ligne = "";
		while (!ws(fichier).eof()){
			getline(fichier, ligne);
			Cible cible = convertirEnCible(ligne);
			insererCible(listeCibles, cible);
		}
	}
	fichier.close();
}


unsigned tailleDuFichier(fstream& fichier)
{
	streampos anciennePosition = fichier.tellg();
	fichier.seekg(0, ios::end);
	unsigned taille = unsigned(fichier.tellg());
	fichier.seekg(anciennePosition);
	return taille;
}


// TODO: Ouvrir le fichier binaire en entrée.
// TODO: Déterminer le nombre de cibles présentes dans le fichier à partir de la taille du fichier.
// TODO: Lire chaque cible (en binaire) et l'insérer dans la liste.
void chargerToutesCibles(ListeCibles& listeCibles, string nomFichier)
{
	fstream fichier(nomFichier, ios::binary | ios::in);
	if (!fichier.fail()){
		unsigned nbElements = tailleDuFichier(fichier) / sizeof(Cible);
		for (unsigned i = 0; i < nbElements; i++){
			Cible cible;
			fichier.read((char*)&cible, sizeof(cible));
			insererCible(listeCibles, cible);
		}
	}
	fichier.close();
}


// TODO: Ouvrir le fichier binaire en entrée/sortie.
// TODO: Déterminer le nombre de cibles présentes dans le fichier à partir de la taille du fichier.
// TODO: Trouver la cible à sauvegarder dans le fichier binaire.
// TODO: Si la cible est présente, alors l'écraser avec la cible donnée.
// TODO: Si la cible n'est pas déjà dans le fichier, alors l'insérer au bon endroit à l'aide de son numéro. Il faut d'abord décaler toutes
//       les cibles suivantes pour faire de la place, puis écrire la cible dans le trou qui vient d'être fait.
void sauvegarderCible(Cible cible, string nomFichier)
{
	fstream fichier(nomFichier, ios::binary | ios::in | ios::out);

	if (fichier.fail()){
		fichier.open(nomFichier, ios::binary | ios::in | ios::out | ios::trunc);
	}

	unsigned nbElements = tailleDuFichier(fichier) / sizeof(Cible);
	bool estDejaPresent = false;
	fichier.seekg(0, ios::beg);

	for (unsigned i = 0; i < nbElements && !estDejaPresent; i++){
		Cible cibleFichier;
		fichier.read((char*)& cibleFichier, sizeof(cibleFichier));
		estDejaPresent = cible.id == cibleFichier.id;
		if (estDejaPresent){
			fichier.seekg(i * sizeof(cible), ios::beg);
			fichier.write((char*)& cible, sizeof(cible));
		}
	}

	if (!estDejaPresent){
		bool estBonEndroit = false;
		fichier.seekg(0, ios::beg);
		unsigned j = 0;
		for (j; j < nbElements && !estBonEndroit; j++){
			Cible cibleFichier;
			fichier.read((char*)& cibleFichier, sizeof(cibleFichier));
			estBonEndroit = cible.id < cibleFichier.id;
			if (estBonEndroit){
				for (unsigned a = nbElements - 1; a >= j; a--){
					Cible cibleDep;
					fichier.seekg(a * sizeof(cibleDep), ios::beg);
					fichier.read((char*)& cibleDep, sizeof(cibleDep));
					fichier.seekg((a + 1) * (sizeof(cibleDep)), ios::beg);
					fichier.write((char*)& cibleDep, sizeof(cibleDep));
				}
			}
		}
		if (nbElements != 0){
			fichier.seekg(j * sizeof(cible), ios::beg);
			fichier.write((char*)& cible, sizeof(cible));
		}
		else{
			fichier.seekg(0, ios::beg);
			fichier.write((char*)& cible, sizeof(cible));
		}
	}
	fichier.close();
}


// TODO: Ouvrir le fichier texte en supprimant son contenu.
// TODO: Formater chaque cible de la liste et l'ajouter comme une ligne dans le fichier de rapport.
void produireRapport(ListeCibles liste, string nomFichier)
{
	ofstream fichier(nomFichier, ios::trunc);

	for (int i = 0; i < (int)liste.nbElems; i++){
		fichier << formaterCible(liste.elems[i]) << endl;
	}
	fichier.close();
}

// TODO: Afficher le numéro de la cible
// TODO: Demander à l'utilisateur d'entrer toutes les autres valeurs.
// TODO: Si l'utilisateur entre la même chose que DONNEE_INCONNUE, 
//       alors la valeur est ignorée, c'est-à-dire qu'elle  n'est
//       pas changée dans la cible.
// TODO: Prenez toutes les valeurs comme des string, puis faites la conversion
//       et le remplacement si l'utilisateur n'a pas entré DONNEE_INCONNUE.
void demanderMiseAJourCible(Cible& cible)
{
	int numeroCible = cible.id;
	string latitude = "",
		longitude = "",
		orientation = "",
		forme = "",
		couleurForme = "",
		lettres = "",
		couleurLettres = "",
		nomFichierImage = "";

	cout << "Mise a jour de la cible " << numeroCible << " : " << endl;

	cout << "Latitude decimale : ";
	cin >> latitude;
	cout << "Longitude decimale : ";
	cin >> longitude;
	cout << "Orientation en degres : ";
	cin >> orientation;
	cout << "Forme : ";
	cin >> forme;
	cout << "Couleur de la forme : ";
	cin >> couleurForme;
	cout << "Lettres : ";
	cin >> lettres;
	cout << "Couleur des lettres : ";
	cin >> couleurLettres;
	cout << "Nom du fichier image : ";
	cin >> nomFichierImage;

	if (latitude != DONNEE_INCONNUE){
		cible.latitude = convertirLatitude(latitude);
	}
	if (longitude != DONNEE_INCONNUE){
		cible.longitude = convertirLongitude(longitude);
	}
	if (orientation != DONNEE_INCONNUE){
		cible.orientation = stod(orientation);
	}
	if (forme != DONNEE_INCONNUE){
		cible.forme = indexerForme(forme);
	}
	if (couleurForme != DONNEE_INCONNUE){
		cible.couleurForme = indexerCouleur(couleurForme);
	}
	if (lettres != DONNEE_INCONNUE){
		strcpy_s(cible.lettres, lettres.c_str());
	}
	if (couleurLettres != DONNEE_INCONNUE){
		cible.couleurLettres = indexerCouleur(couleurLettres);
	}
	if (nomFichierImage != DONNEE_INCONNUE){
		strcpy_s(cible.nomImage, nomFichierImage.c_str());
	}
}
#pragma endregion//}