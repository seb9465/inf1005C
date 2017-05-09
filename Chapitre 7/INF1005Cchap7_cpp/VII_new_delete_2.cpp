#include <iostream>
using namespace std;
//[
int main()
{
	double *ptrReel1, *ptrReel2 = new double;

	ptrReel1 = new double;
	*ptrReel2 = 3.14159;
	*ptrReel1 = 2.4 * (*ptrReel2);
	delete ptrReel2; 
	ptrReel2 = 0;
	delete ptrReel1;
	ptrReel1 = 0;
}

//]