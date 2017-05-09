/**
*  Exemple de "for".
*/
#include <iostream>
using namespace std;

int main()
{
 //[
	string phrase = "il pleut, il vente, il neige et il gresille";
	char lettre = 'e';
	int occurrences = 0;
	for (unsigned i = 0; i < phrase.size(); i++) {
		if (phrase[i] == lettre)
			occurrences++;
	}
	cout << "Le nombre occurrence de la lettre '"
	     << lettre << "' est " << occurrences
	     << endl;
	
//]
}
 
 
