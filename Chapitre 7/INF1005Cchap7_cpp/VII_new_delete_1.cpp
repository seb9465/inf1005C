#include <iostream>
using namespace std;
//[
int main()
{
	int index, *ptrInt1, *ptrInt2;

	ptrInt1 = &index;
	*ptrInt1 = 77;
	ptrInt2 = new int;
	*ptrInt2 = 173;
	cout << "Les valeurs sont " << index << "  "
	     << *ptrInt1 << "  " << *ptrInt2 << endl;
	ptrInt1 = new int;
	ptrInt2 = ptrInt1;
	// La mémoire originalement pointée par ptrInt2 est maintenant perdue.
	*ptrInt1 = 999;
	cout << "Les valeurs sont " << index << "  " 
		 << *ptrInt1 << "  " << *ptrInt2 << "\n";
	delete ptrInt1;
	ptrInt1 = 0;
	// delete ptrInt2; donne une erreur car ptrInt2 = ptrInt1 (même adresse pointée).
	delete ptrInt2; // N'affiche pas d'erreur avec VC 2008, mais c'est une erreur.
}

//]