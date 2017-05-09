#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// liste des prototypes

const int DIMENSION = 26;
void trouverOccurence(string Phrase, int freq[]);
void afficherOccurence(int Freq[]);

char trouverPlusGrandFreq(int freq[]);

void mettreEnOrdre(string & Phrae, int Freq[]);

