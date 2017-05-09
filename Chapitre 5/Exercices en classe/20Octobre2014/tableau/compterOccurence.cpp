// lire une phrase
// Fonction trouver la fréquence des lettres
// Fonction trouver la plus grande féquence des lettres
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
	cout << " la phrase triée est " << phraseEnOrdre << endl;


	return 0;

}

