#include "jeuStick.hpp"

void jouerOrdinateur(int& nSticks) {
	int nbBatonsOrdi = 0;

	if (nSticks == 4){
		nbBatonsOrdi = 3;
	}
	else if (nSticks == 3) {
		nbBatonsOrdi = 2;
	}
	else if (nSticks == 2){
		nbBatonsOrdi = 1;
	}

	else {
		nbBatonsOrdi = ((int)rand() % 3) + 1;
	}

	nSticks -= nbBatonsOrdi;

	cout << "L'ordinateur a pris " << nbBatonsOrdi << " batons." << endl;
}

//----------------------------------------------------------------------------

void test_jouerOrdinateur() {
	cerr << "Test jouerOrdinateur:";
	cerr << endl;
	srand(unsigned(time(nullptr))); rand();

	// Décommenter/commenter pour faire des tests à la main ou pas:
	int nSticks = 10; jouerOrdinateur(nSticks); cout << nSticks << endl;

	// Tests automatisés:

	// Test le coup gagnant.
	for (int i = 2; i < 5; i++) {
		int nSticks = i;
		simulerCinCout("");
		jouerOrdinateur(nSticks);
		ESPERE_EGALITE(nSticks, 1);
	}

	// Test la distribution des autres coups.
	static const int occurenceEsperee = 50;
	static const int nClasses = 3;
	int occurences[nClasses] = {};
	bool tousDansIntervalle = true;
	for (int i = 0; i < occurenceEsperee * nClasses; i++) {
		static const int nombreInitial = 5;
		int nSticks = nombreInitial;
		simulerCinCout("");
		jouerOrdinateur(nSticks);
		int pris = nombreInitial - nSticks;
		if (pris >= 1 && pris <= 3)
			occurences[pris - 1]++;
		else
			tousDansIntervalle = false;
	}
	ESPERE_EGALITE(tousDansIntervalle, true);
	double khiCarre = 0.0;
	for (int i = 0; i < nClasses; i++)
		khiCarre += pow(occurences[i] - occurenceEsperee, 2.0) / occurenceEsperee;
	ESPERE_EGALITE(khiCarre < 9.21, true); // p-value de 0.01 pour 2 degrés de liberté.  Noter qu'il y a 1% de probabilité que ce test échoue alors que le fonction est bonne.

	affichageStatistiquesTests();
}
