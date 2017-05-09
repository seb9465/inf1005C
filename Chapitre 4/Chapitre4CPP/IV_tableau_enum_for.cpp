#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cassert>  // Pour assert
using namespace std;
int main()
{ //[
	enum Jour { LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, 
	            SAMEDI, DIMANCHE, NBJOURS };
	enum Periode { AM, PM, SOIR, NBPERIODES };

	string agenda[NBJOURS][NBPERIODES];
	static const string LIBRE = "----";

	for (Jour jour = LUNDI; jour <= DIMANCHE; jour = Jour(jour+1))
		for (Periode periode = AM; periode <= SOIR;
		     periode = Periode(periode+1))
			agenda[jour][periode] = LIBRE;

//]

	// Lecture d'un fichier ayant sur chaque ligne:  numéro_de_jour  numéro_de_période  Description de l'occupation:
	ifstream fichier("IV_tableau_enum_for.txt");
	while (!ws(fichier).eof()) {
		int jour, periode; // On ne peut pas lire des des énumérations, donc on lit les entiers correspondants.
		fichier >> jour >> periode >> ws;
		getline(fichier, agenda[jour][periode]);
	}

	// Affichage d'une des valeurs du tableau:
	cout << "Mardi PM contient: " << agenda[MARDI][PM] << endl;
	
//[
	// Lecture d'un type énuméré en utilisant un tableau:
	static const string nomJours[] = {
		"lundi", "mardi", "mercredi", "jeudi", "vendredi",
		"samedi", "dimanche"
	};
	cout << "Pour quel jour voulez-vous l'horaire? (lundi .. dimanche) ";
	string jourTexte;
	cin >> jourTexte;
	Jour jour = LUNDI;
	while (jour <= DIMANCHE && jourTexte != nomJours[jour])
		jour = Jour(jour+1);
	
	
	// Affichage d'un type énuméré en utilisant un tableau de string:
	assert(jour >= LUNDI && jour <= DIMANCHE); // Erreur si jour pas valide.
	cout << "Le jour est " << nomJours[jour] << endl;
	
//]
//[
	// Lecture d'un type énuméré en utilisant un switch/case:
	switch (jourTexte[0]) {             // Teste la première lettre.
		case 'l': jour = LUNDI;    break;
		case 'm':                        // Pour distinguer "mardi" et "mercredi",
			switch (jourTexte[1]) {       // teste la deuxième lettre.
				case 'a': jour = MARDI;    break;
				case 'e': jour = MERCREDI; break;
			}
			break;
		case 'j': jour = JEUDI;    break;
		case 'v': jour = VENDREDI; break;
		case 's': jour = SAMEDI;   break;
		case 'd': jour = DIMANCHE; break;
	}
	// Affichage d'un type énuméré en utilisant un switch/case:
	switch (jour) {
		case LUNDI:    cout << "lundi";    break;
		case MARDI:    cout << "mardi";    break;
		case MERCREDI: cout << "mercredi"; break;
		case JEUDI:    cout << "jeudi";    break;
		case VENDREDI: cout << "vendredi"; break;
		case SAMEDI:   cout << "samedi";   break;
		case DIMANCHE: cout << "dimanche"; break;
		default:       cout << "invalide"; break;
	}
//]
	static const string nomPeriode[] = {
		"am", "pm", "soir"
	};
	cout << ":  ";
	for (Periode periode = AM; periode <= SOIR; periode = Periode(periode+1)) {
		cout << nomPeriode[periode] << ": "
		     << left << setw(17) << agenda[jour][periode];
	}
	cout << endl;
	
}

// vim: ts=3