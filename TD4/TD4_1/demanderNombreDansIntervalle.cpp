#include "jeuStick.hpp"

int demanderNombreDansIntervalle(int minimum, int maximum) {
	int nbMin = minimum;
	int nbMax = maximum;
	int nombre = 0;
	bool estBon = false;

	cout << "(" << nbMin << "-" << nbMax << ") ? ";

	cin >> nombre;

	if (!cin.fail()){
		estBon = nombre >= nbMin && nombre <= nbMax;
	}
	else{
		cin.clear();
		cin.ignore(80, '\n');
	}

	while (!estBon){
		cout << "Le nombre ne respecte pas l'intervalle." << endl;
		cout << "(" << nbMin << ", " << nbMax << ") ? " << endl;
		cin >> nombre;
		if (!cin.fail()){
			estBon = nombre >= nbMin && nombre <= nbMax;
		}
		else{
			cin.clear();
			cin.ignore(80, '\n');
		}
	}

	return nombre;
}

//----------------------------------------------------------------------------

void test_demanderNombreDansIntervalle() {
	cerr << "Test demanderNombreDansIntervalle:";
	cerr << endl;
	// Décommenter/commenter pour faire des tests à la main ou pas:
	//cout << demanderNombreDansIntervalle(2, 7) << endl;

	// Tests automatisés:
	int resultat;

	simulerCinCout("1\n8\n2\n4\n");
	resultat = demanderNombreDansIntervalle(2, 7);
	ESPERE_EGALITE(resultat, 2);

	simulerCinCout("1\n8\n2\n4\n");
	resultat = demanderNombreDansIntervalle(2, 8);
	ESPERE_EGALITE(resultat, 8);

	simulerCinCout("1\n8\n2\n4\n");
	resultat = demanderNombreDansIntervalle(1, 8);
	ESPERE_EGALITE(resultat, 1);

	simulerCinCout("0\n9\n7\n4\n");
	resultat = demanderNombreDansIntervalle(2, 7);
	ESPERE_EGALITE(resultat, 7);

	simulerCinCout("-1\n5\n4\n");
	resultat = demanderNombreDansIntervalle(2, 7);
	ESPERE_EGALITE(resultat, 5);

	simulerCinCout("du texte\n6\n4\n");
	resultat = demanderNombreDansIntervalle(2, 7);
	ESPERE_EGALITE(resultat, 6);

	affichageStatistiquesTests();
}
