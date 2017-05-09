/**
*  Ce programme détermine si une année lue au clavier est bissextile.
*  \file    bissextile.cpp
*  \author  Yves BOUDREAULT
*  \date    17 mai 1994; dernière édition: 10 juin 1994
**/

#include <iostream>   // Pour l'utilisation de cin et cout.
#include <string>     // Pour l'utilisation de chaînes de caractères.
using namespace std; //[
int main()
{
	const string BISSEXTILE = " est une annee bissextile. ";
	const string PAS_BISSEXTILE = " n'est pas une annee bissextile. ";
	cout << "Inscrire l'annee dont vous desirez" << endl;
	cout << "connaitre la nature (bissextile ou non) => ";
	int annee;
	cin >> annee;
	string statut;
	if (annee % 4 != 0)           // Année non un multiple de 4.
		statut = PAS_BISSEXTILE;
	else                          // Année multiple de 4 mais 
	if (annee % 100 != 0)      // pas un multiple de 100.
		statut = BISSEXTILE;
	else                       // Année multiple de 4 et de 100
	if (annee % 400 != 0)   // mais pas de 400.
		statut = PAS_BISSEXTILE;
	else                    // Multiple de 4, 100 et 400.
		statut = BISSEXTILE;
	cout << endl << annee << statut;
}

//]
// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=/**,M0,**/,M0 : foldseparator=-1