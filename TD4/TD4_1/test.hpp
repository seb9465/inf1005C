/**
*  Simples fonctions pour faire des tests unitaires.
*  \author Francois-R.Boyer@PolyMtl.ca
*  \date 2014-10
*  \file
*/
#pragma once
#include <iostream>
#include <string>
#pragma comment(lib, "../Debug/Z test.lib")
void simulerCinCout(const std::string& texte);
void restaureCinCout();
const std::string stringCoutDuTest();

#define ESPERE_EGALITE(a, b) espereEgalite(__LINE__, #a, a, #b, b)

extern int nTests, nTestsPasse;

std::ostream& couleurBon(std::ostream& o);
std::ostream& couleurErreur(std::ostream& o);
std::ostream& couleurAvertissement(std::ostream& o);
std::ostream& couleurNormal(std::ostream& o);

template <typename T>
void affichageValeurTest(const T& valeur) {
	std::cerr << valeur;
}
template <>
void affichageValeurTest(const std::string& valeur);

template <typename T>
void affichageTest(int numeroLigne, const std::string& texteA, const T& a, const std::string& texteB, const T& b, const std::string& texteOperateur, bool testPasse) {
	restaureCinCout();
	std::cerr << "  " << numeroLigne << ": " << texteA << texteOperateur << texteB << " (";
	affichageValeurTest(a);
	std::cerr << texteOperateur;
	affichageValeurTest(b);
	std::cerr << ")" << " ? ";
	nTests++;
	if (testPasse) {
		std::cerr << couleurBon << "oui" << couleurNormal;
		nTestsPasse++;
	}
	else
		std::cerr << couleurErreur << "NON!" << couleurNormal;
	std::cerr << std::endl;
}
template <typename A, typename B>
void espereEgalite(int numeroLigne, const std::string& texteA, const A& a, const std::string& texteB, const B& b) {
	affichageTest(numeroLigne, texteA, a, texteB, b, " == ", a == b);
}

/// reponsePrevue est une chaine contenant des parties de texte séparées par des '\n'.
/// Chaque parties doit se trouver dans la sortie, dans le même ordre, pour être considéré correct.
void verifieCout(const std::string& reponsePrevue);

void affichageStatistiquesTests();
