// lire une phrase
// Fonction trouver la fr�quence des lettres
// Fonction trouver la plus grande f�quence des lettres
// Fonction mettre en ordre les lettres de la phrase
#include "listefonctions.hpp"
int main()
{
	int frequence[DIMENSION] = {};
	string phrase;

	cout << "donner une phrase ";
	getline(cin, phrase);

	trouverOccurence(phrase, frequence);
	afficherOccurence(frequence);

	string phraseEnOrdre;
	mettreEnOrdre(phraseEnOrdre, frequence);
	cout << " la phrase tri�e est " << phraseEnOrdre << endl;


	return 0;

}

