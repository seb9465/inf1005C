	//- EN-TETE DU PROGRAMME -
/**
*  Ce programme calcule et affiche la factorielle d'un nombre lu du clavier.
*  \file    factorielle.cpp
*  \author  Yves BOUDREAULT
*  \date    10 Septembre 2009
**/

#include <iostream>   // Pour l'utilisation de cin et cout.
using namespace std;

int main()  // Fonction principale, début du programme.
{
	//- DECLARATION DES CONSTANTES -
	const int NOMBREMAX = 8;
	
	//- ENTRÉE DES DONNÉES -
	cout << "Entrer un nombre inférieur à "
	     << NOMBREMAX << " : ";
	int nombre;             // Variable de lecture d'un nombre entier.
	cin >> nombre;          // Lecture d'un nombre.
	
	//- TRAITEMENT -
	int factorielle;        // Variable du résultat.
	if (nombre == 0)        // Si le nombre lu est zéro.
		factorielle = 1;
	else {                  // Sinon
		int produit = nombre;       // Variable pour les calculs intermédiaires.
		while (nombre > 1) {        // Répéter tant que le nombre > 1.
			nombre  = nombre - 1;       // Enlever 1 à nombre.
			produit = produit * nombre; // Calculer le produit.
		}
		factorielle = produit;
	} // Fin du sinon.
	
	//- AFFICHAGE DES RÉSULTATS -
	cout << "La factorielle est: " << factorielle;
}

// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=//-,3,//TODO,m3,/**,M0,**/,M0 : colormarker=/*-,-*/,3 : foldseparator=-1