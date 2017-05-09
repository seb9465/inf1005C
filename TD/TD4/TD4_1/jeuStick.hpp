#include "test.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int demanderNombreSticks();
int demanderNomsJoueurs(string nomDesJoueurs[2]);
int demanderNombreDansIntervalle(int minimum, int maximum);
void jouer(int nSticksInitial, int nJoueurs, const string nomDesJoueurs[2]);
void jouerOrdinateur(int& nSticks);
void jouerHumain(const string& nom, int& nSticks);

void test_tout();
void test_demanderNombreDansIntervalle();
void test_demanderNombreSticks();
void test_demanderNomsJoueurs();
void test_jouerHumain();
void test_jouerOrdinateur();
