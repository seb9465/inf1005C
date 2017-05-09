#include "jeuStick.hpp"

int demanderNombreSticks() {
	const int NB_MAX = 100,
		NB_MIN = 10;
	int nbSticks = 0;

	cout << "Quel est le nombre de batons initial";

	nbSticks = demanderNombreDansIntervalle(NB_MIN, NB_MAX);

	return nbSticks;
}

//----------------------------------------------------------------------------

void test_demanderNombreSticks() {
	cerr << "Test demanderNombreSticks:";
	cerr << endl;
	// Décommenter/commenter pour faire des tests à la main ou pas:
	//cout << demanderNombreSticks() << endl;

	// Tests automatisés:
	int resultat;

	simulerCinCout("9\n101\n10\n50\n");
	resultat = demanderNombreSticks();
	ESPERE_EGALITE(resultat, 10);

	simulerCinCout("9\n100\n50\n");
	resultat = demanderNombreSticks();
	ESPERE_EGALITE(resultat, 100);

	simulerCinCout("50\n");
	resultat = demanderNombreSticks();
	ESPERE_EGALITE(resultat, 50);

	affichageStatistiquesTests();
}
