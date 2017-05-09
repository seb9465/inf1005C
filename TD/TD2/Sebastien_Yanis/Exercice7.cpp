/*
* Édition d’une facture et utilisation de fichiers.
* \fichier   Exercice7.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   25 septembre 2014
* Créé le 24 septembre 2014
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Initialisation des variables
	string nom;
	string produit1;
	int quantite1;
	int prix1;
	int taxe1;
	int montantHT1;

	string produit2;
	int quantite2;
	int prix2;
	int taxe2;
	int montantHT2;

	string produit3;
	int quantite3;
	int prix3;
	int taxe3;
	int montantHT3;

	int montantTotal;
	int taxeTotal;

	//Ouverture du fichier texte
	ifstream fichierTxt("ventes.txt");

	//Lecture du fichier texte
	//Structure de répétition
	fichierTxt >> nom;
	fichierTxt >> produit1;
	fichierTxt >> quantite1;
	fichierTxt >> prix1;

	fichierTxt >> produit2;
	fichierTxt >> quantite2;
	fichierTxt >> prix2;

	fichierTxt >> produit3;
	fichierTxt >> quantite3;
	fichierTxt >> prix3;

	//Caclcul des montants et taxes
	//Structure de répétition
	montantHT1 = prix1 * quantite1;
	taxe1 = montantHT1 * 0.10;

	montantHT2 = prix2 * quantite2;
	taxe2 = montantHT2 * 0.10;

	montantHT3 = prix3 * quantite3;
	taxe3 = montantHT3 * 0.10;

	montantTotal = montantHT1 + montantHT2 + montantHT3 + taxe1 + taxe2 + taxe3;

	taxeTotal = taxe1 + taxe2 + taxe3;

	//Affichage
	//Structure de répétition
	cout << nom << endl;
	cout << "nomProduit : " << produit1 << " Quantite : " << quantite1 << " Prix : " << prix1 << " Montant HT : " << montantHT1 << " Taxe : " << taxe1 << endl;
	cout << "nomProduit : " << produit2 << " Quantite : " << quantite2 << " Prix : " << prix2 << " Montant HT : " << montantHT2 << " Taxe : " << taxe2 << endl;
	cout << "nomProduit : " << produit3 << " Quantite : " << quantite3 << " Prix : " << prix3 << " Montant HT : " << montantHT3 << " Taxe : " << taxe3 << endl;
	cout << "Montant total de la facture : " << montantTotal << endl;

	//Création du fichier recapitulatif
	ofstream fichierRecap("recapitulatif.txt");

	//Écriture dans le fichier recapitulatif
	fichierRecap << nom <<" " << montantTotal <<" " << taxeTotal;

	//Fermeture des fichiers
	fichierTxt.close();
	fichierRecap.close();

	return 0;
}