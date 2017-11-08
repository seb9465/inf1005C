/**
*  Simples fonctions pour faire des tests unitaires.
*  \author Francois-R.Boyer@PolyMtl.ca
*  \date 2014-10
*  \file
*/
#include <iostream>
#include <sstream>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h> // Pour SetConsoleTextAttribute

int nTests = 0, nTestsPasse = 0, nTestsCumulatif = 0, nTestsPasseCumulatif = 0;

std::streambuf* cinOriginal = std::cin.rdbuf();
std::streambuf* coutOriginal = std::cout.rdbuf();
std::stringbuf  cinPourTests("");
std::stringbuf  coutPourTests("");
static const HANDLE handleStderr = GetStdHandle(STD_ERROR_HANDLE);

std::ostream& couleurBon(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x0A);
	return o;
}
std::ostream& couleurErreur(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x0C);
	return o;
}
std::ostream& couleurAvertissement(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x0E);
	return o;
}
std::ostream& couleurNormal(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x07);
	return o;
}

template <typename T>
void affichageValeurTest(const T& valeur);

template <>
void affichageValeurTest(const std::string& valeur) {
	std::cerr << '"' << valeur << '"';
}

void simulerCinCout(const std::string& texte)
{
	cinPourTests.str(texte);
	std::cin.clear();
	std::cin.rdbuf(&cinPourTests);
	
	coutPourTests.str("");
	std::cout.clear();
	std::cout.rdbuf(&coutPourTests);
}

void restaureCinCout()
{
	std::cin.rdbuf(cinOriginal);
	std::cout.rdbuf(coutOriginal);
}

const std::string stringCoutDuTest()
{
	return coutPourTests.str();
}

void verifieCout(const std::string& reponsePrevue)
{
	restaureCinCout();
	const std::string reponse = stringCoutDuTest();
	unsigned positionDansReponse = 0;
	unsigned positionDebut = 0;
	nTests++;
	while (positionDebut < reponsePrevue.length()) {
		unsigned positionFin = reponsePrevue.find_first_of('\n', positionDebut);
		if (positionFin == std::string::npos)
			positionFin = reponsePrevue.length();
		std::string aChercher = reponsePrevue.substr(positionDebut, positionFin - positionDebut);
		unsigned positionTrouvee = reponse.find(aChercher, positionDansReponse);
		if (positionTrouvee == std::string::npos) {
			std::cerr << "  " << couleurErreur << "N'a pas trouve" << couleurNormal << " '" << aChercher << "' dans '" << reponse.substr(positionDansReponse) << "'" << std::endl;
			return;
		}
		positionDansReponse = positionTrouvee + aChercher.length();
		positionDebut = positionFin + 1;
	}
	std::cerr << "  'cout' " << couleurBon << "correct." << couleurNormal << std::endl;
	nTestsPasse++;
}

static void affichageRatio(int numerateur, int denominateur) {
	if (numerateur == denominateur)
		std::cerr << couleurBon;
	else
		std::cerr << couleurErreur;
	std::cerr << numerateur << "/" << denominateur << couleurNormal;
}
void affichageStatistiquesTests() {
	restaureCinCout();
	nTestsCumulatif += nTests;
	nTestsPasseCumulatif += nTestsPasse;
	std::cerr << "  ";
	affichageRatio(nTestsPasse, nTests);
	std::cerr << " ont reussi (";	
	affichageRatio(nTestsPasseCumulatif, nTestsCumulatif);
	std::cerr << " cumulatif)." << std::endl << std::endl;
	nTests = nTestsPasse = 0;
}
