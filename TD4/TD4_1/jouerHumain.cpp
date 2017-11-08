#include "jeuStick.hpp"

void jouerHumain(const string& nom, int& nSticks) {
	int nbMax = 0;
	const int NB_MIN = 1;
	int nbBatonsUtili = 0;

	if (nSticks < 3){
		nbMax = nSticks;
	}
	else{
		nbMax = 3;
	}
	cout << nom << " : combien de batons voulez-vous prendre ";
	nbBatonsUtili = demanderNombreDansIntervalle(NB_MIN, nbMax);
	
	nSticks -= nbBatonsUtili;
}

//----------------------------------------------------------------------------

void test_jouerHumain() {
	cerr << "Test jouerHumain:";
	cerr << endl;
	// Décommenter/commenter pour faire des tests à la main ou pas:
	//int nSticks = 10; jouerHumain("Vous", nSticks); cout << nSticks << endl;

	// Tests automatisés:
	{
	simulerCinCout("3\n2\n");
	int nSticks = 10;
	jouerHumain("", nSticks);
	ESPERE_EGALITE(nSticks, 7);
	}
	{
	simulerCinCout("0\n4\n1\n");
	int nSticks = 10;
	jouerHumain("", nSticks);
	ESPERE_EGALITE(nSticks, 9);
	}
	{
	simulerCinCout("3\n1\n");
	int nSticks = 2;
	jouerHumain("", nSticks);
	ESPERE_EGALITE(nSticks, 1);
	}

	affichageStatistiquesTests();
}
