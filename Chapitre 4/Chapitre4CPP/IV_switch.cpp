#include <iostream>
using namespace std;
int main()
{ //[
int  points = 0;
char note;
cout << "Note = "; cin >> note;
switch (note) {
	case 'A' : points +=4;
	case 'B' : points +=3;
	case 'C' : points +=2;
	           break;
	case 'D' : points = 1;
	           break;
	default  : points = 0;
}
cout << " Cette note vaut " << points; 
 
 
} //]

// vim: ts=3