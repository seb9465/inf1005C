// ajout de ligne dans un fichier
# include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	ifstream lecture("poeme.txt");
	ofstream ecriture;
	string phrase;
	fstream fichierAjouter;
	//lecture.open("poeme.txt");
	if(lecture.fail())
		cout<< "le fichier n'existe pas"<<endl;
	else
	{
		while (!ws(lecture).eof())
		{
			getline(lecture, phrase);
			cout << phrase << endl;
		}
		lecture.close();
	}

	fichierAjouter.open("poeme.txt",ios::app);
	if (fichierAjouter.fail())
		cout<<"le fichier n'existe pas"<<endl;
	else
	{
		cout << "ajout d'une phrase ";
		getline(cin,phrase);
		fichierAjouter<<phrase<<endl;
		fichierAjouter.close();
	}
	return 0;
}
