#include <iostream>
using namespace std;

// Mettre dans la ligne suivant un 1 pour le passage par valeur, ou un 0 pour le passage par adresse
#if 0 //[
void permuter(int a, int b)    // Passage par valeur.
//]
#else //[
void permuter(int& a, int& b)  // Passage par adresse.
//]
#endif
//[
{
	
	int tampon = a;
	
	a = b;
	
	b = tampon;
}

int main()
{
	int i = 5;
	int j = 3;
	cout << "I= " << i << " J= " << j << endl;
	permuter(i, j);
	cout << "I= " << i << " J= " << j << endl;
}
//]