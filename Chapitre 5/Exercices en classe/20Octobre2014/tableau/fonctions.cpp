#include "listefonctions.hpp"
void trouverOccurence(string phrase, int freq[])
{
	for (int i = 0; i < phrase.size(); i++)
	{
		phrase[i] = tolower(phrase[i]);
		if (phrase[i] >= 'a' && phrase[i] < 'z')
		{
			int indice = int(phrase[i] - 'a');
			freq[indice]++;
		}
	}
}

void afficherOccurence(int freq[])
{
	for (int i = 0; i < DIMENSION; i++)
		if (freq[i] !=0)
			cout << char(i + 'a')<<"\t"<<freq[i] << endl;;
}

char trouverPlusGrandFreq(int freq[])
{
	return 'x';
}

void mettreEnOrdre(string & phrase, int freq[])
{
	phrase = "";
	for (int i = 0; i < DIMENSION; i++)
	{
		if (freq[i] != 0)
		for (int j = 0; j < freq[i]; j++)
			phrase = phrase + char(i + 'a');
	}
}
