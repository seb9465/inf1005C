#include <iostream>
using namespace std;
int main()
{ //[
int a, b;
cout << " Entrer deux entiers: "; 
cin >> a >> b;
if (a == b)
	cout << a << " est égal à " << b;
else
	if (a < b)
		cout << a << " est plus petit que " << b;
	else 
		cout << a << " est plus grand que " << b;
	
 
} //]

// vim: ts=3