#include "jeuStick.hpp"

void jouer(int nSticksInitial, int nJoueurs, const string nomDesJoueurs[2]) {
	int nSticks = nSticksInitial;

	cout << "Il y a " << nSticks << " batons sur la table." << endl;

	int compteurJoueur = 0;
	while (nSticks > 1){
		if (nJoueurs == 1){ // jouer contre l'ordinateur
			if (compteurJoueur == 0){
				jouerHumain(nomDesJoueurs[0], nSticks);
			}
			else{
				jouerOrdinateur(nSticks);
			}
		}
		else { //nombre de joueur = 1
			jouerHumain(nomDesJoueurs[compteurJoueur], nSticks);
		}

		cout << "Il reste " << nSticks << " batons sur la table." << endl;

		compteurJoueur = (compteurJoueur + 1) % 2; //compteur pour le tour des joueurs
	}

	if (nSticks == 1){
		cout << nomDesJoueurs[compteurJoueur] << " a perdu." << endl;
	} else if (nSticks == 0){
		cout << nomDesJoueurs[(compteurJoueur + 1) % 2] << " a perdu." << endl;
	}
}

int main() {
	cout << "Bienvenu dans le 'game of sticks' !" << endl;

	int nombreDeBatons = 0,
		nombreDeJoueur = 0;
	string nomDesJoueurs[2] = {};

	nombreDeBatons = demanderNombreSticks();
	nombreDeJoueur = demanderNomsJoueurs(nomDesJoueurs);

	jouer(nombreDeBatons, nombreDeJoueur, nomDesJoueurs);
}

//----------------------------------------------------------------------------

void test_jouer() {
	cerr << "Test jouer:";
	cerr << endl;

	static const string nomsDeuxJoueurs[] = { "X", "Y" };
	simulerCinCout("2\n3\n1\n3\n1\n");
	jouer(10, 2, nomsDeuxJoueurs);
	verifieCout(
		" 10 baton\n"
		"X\n"
		" 8 baton\n"
		"Y\n"
		" 5 baton\n"
		"X\n"
		" 4 baton\n"
		"Y\n"
		" 1 baton\n"
		"X a perdu"
		);
	simulerCinCout("1\n2\n2\n3\n1\n1\n");
	jouer(10, 2, nomsDeuxJoueurs);
	verifieCout(
		" 10 baton\n"
		"X\n"
		" 9 baton\n"
		"Y\n"
		" 7 baton\n"
		"X\n"
		" 5 baton\n"
		"Y\n"
		" 2 baton\n"
		"X\n"
		" 1 baton\n"
		"Y a perdu"
		);

	static const string nomsUnJoueur[] = { "X", "L'ordinateur" };
	simulerCinCout("3\n1\n1\n1\n2\n1\n");
	jouer(9, 1, nomsUnJoueur);
	verifieCout(
		" 9 baton\n"
		"X\n"
		" 6 baton\n"
		"ordinateur\n"
		"X a perdu"
		);
	affichageStatistiquesTests();
}

void test_tout() {
	test_demanderNombreDansIntervalle();
	test_demanderNombreSticks();
	test_demanderNomsJoueurs();
	test_jouerHumain();
	test_jouerOrdinateur();
	test_jouer();
}
