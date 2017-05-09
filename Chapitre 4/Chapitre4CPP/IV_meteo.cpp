/**
*  Ce programme lit dans un fichier les températures quotidiennes pour un mois, identifie la température maximale et sa date, calcule la moyenne et trouve le premier jour de gel.
*  \file    meteo.cpp
*  \author  Yves BOUDREAULT
*  \date    17 mai 1994; dernière édition: 7 juillet 1994
**/

#include <fstream>  // Pour l'utilisation des fichiers.
#include <iostream> // Pour l'utilisation de cin et cout.
#include <iomanip>  // Pour l'utilisation de setw() et setprecision().
using namespace std; //[
static const int JOUR_INVALIDE = -1;

int main()
{
	ifstream entree("IV_meteo.txt");
	if (entree.fail())
		cout << " Impossible d'ouvrir le fichier" << endl;
	else {
		// Lecture du fichier.
		double temperatures[31];  // temperatures[0] est la température du premier jour.
		int nbJours =  0;
		while (!ws(entree).eof()) {
			entree >> temperatures[nbJours];
			nbJours++;
		}
		
		// Déterminer la température maximale du mois et la moyenne des températures.
		int jourMax = 0;
		double temperatureMax = -1.0E2;
		double somme   =  0.0;
		for (int jour = 0; jour < nbJours; jour++) {
			somme +=  temperatures[jour];
			if (temperatures[jour] > temperatureMax) {
				temperatureMax = temperatures[jour];
				jourMax = jour + 1;
			}
		}
		
		double temperatureMoyenne = somme / nbJours;
		cout.setf(ios::fixed);
		cout << "maximum: " << temperatureMax << " le" << setw(3) << jourMax << endl;
		cout << "moyenne: " << temperatureMoyenne << endl;

		// Déterminer le premier jour de gel.
		int premierJourDeGel = JOUR_INVALIDE;
		int jour = 0;
		while (premierJourDeGel == JOUR_INVALIDE && jour < nbJours) {
			if (temperatures[jour] <= 0.0)
				premierJourDeGel = jour;
			jour++;
		}
		if (premierJourDeGel != JOUR_INVALIDE)   // S'il y a eu un jour de gel.
			cout << "premier jour de gel: " << (premierJourDeGel + 1);
		else
			cout << "pas de gel durant le mois";
	}
}

//]
// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=/**,M0,**/,M0 : foldseparator=-1