#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << setprecision(9); // Ajuste le nombre de chiffres significatifs affichés pour les float/double.
	
	cout << "Conversions implicites:" << endl;
//[
	                                 // Affiche:    Type:
	cout << 1 + true << endl;        // 2           int
	cout << 1 + 0.5  << endl;        // 1.5         double
	cout << 2.2 / 2  << endl;        // 1.1         double
	cout << 1 / 2.0  << endl;        // 0.5         double
	cout << -1 * 2   << endl;        // -2          int
	// Ne donne pas ce qu'on pourrait croire :       
	cout << 1 / 2    << endl;        // 0           int
	cout << 'A' + 2  << endl;        // 67          int, noter que 67=='C'
	cout << -1 * 2U  << endl;        // 4294967294  unsigned
//]
	
	cout << "Conversions explicites:" << endl;
//[
	// On aimerait :
	// 1 / 2 = 0.5 , 'A' + 2 = 'C' , -1 * 2U = -2 .

	// Une des syntaxe C++ :
	// Bonne manière :
	cout << double(1) / 2  << endl; // 0.5 (division de double)
	cout << char('A' + 2)  << endl; // C   (résultat converti en char)
	cout << -1 * int(2U)   << endl; // -2  (multiplication de int)
	// Mauvaise manière :
	cout << double(1 / 2)  << endl; // 0   (division de int)
	cout << 'A' + char(2)  << endl; // 67  (résultat est un int)
	cout << int(-1 * 2U)   << endl; // -2  (bon résultat dans notre cas mais est
	                                //     "implementation-defined" selon C++11 §4.7¶3)
	
	// Mêmes conversion mais avec la syntaxe C :
	cout << (double)1 / 2   << endl; // 0.5
	cout << (char)('A' + 2) << endl; // C
	cout << -1 * (int)2U    << endl; // -2
	// Mauvaise manière :
	cout << (double)(1 / 2) << endl; // 0
	cout << 'A' + (char)2   << endl; // 67
	cout << (int)(-1 * 2U)  << endl; // -2
	
//]
}
 
