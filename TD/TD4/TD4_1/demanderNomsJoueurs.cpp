#include "jeuStick.hpp"

int demanderNomsJoueurs(string nomDesJoueurs[2]) {
	const int NB_MAX_JOUEURS = 2,
		NB_MIN_JOUEURS = 1;
	int nbJoueurs = 0;

	cout << "Combien y a-t-il de joueurs ";
	nbJoueurs = demanderNombreDansIntervalle(NB_MIN_JOUEURS, NB_MAX_JOUEURS);

	cout << "Quelle est votre nom ? ";
	cin >> nomDesJoueurs[0];

	if (nbJoueurs == 2){
		cout << "Deuxième joueur, quelle est votre nom? ";
		cin >> nomDesJoueurs[1];
	}
	else{
		nomDesJoueurs[1] = "L'ordinateur";
	}

	return nbJoueurs;
}

//----------------------------------------------------------------------------

void test_demanderNomsJoueurs() {
	cerr << "Test demanderNomsJoueurs:";
	cerr << endl;
	string resultatNoms[2];
	// Décommenter/commenter pour faire des tests à la main ou pas:
	//cout << demanderNomsJoueurs(resultatNoms) << endl;

	// Tests automatisés:
	int resultat;

	simulerCinCout("2\nAbc\nDefg\n");
	resultat = demanderNomsJoueurs(resultatNoms);
	ESPERE_EGALITE(resultat, 2);
	ESPERE_EGALITE(resultatNoms[0], string("Abc"));
	ESPERE_EGALITE(resultatNoms[1], string("Defg"));

	simulerCinCout("0\n3\n1\nEfghi\nJklmn\n");
	resultat = demanderNomsJoueurs(resultatNoms);
	ESPERE_EGALITE(resultat, 1);
	ESPERE_EGALITE(resultatNoms[0], string("Efghi"));
	ESPERE_EGALITE(resultatNoms[1], string("L'ordinateur"));

	affichageStatistiquesTests();
}
