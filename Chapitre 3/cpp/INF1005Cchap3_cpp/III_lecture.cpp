/**
* Programme pour visualiser le comportement de l'entrée avec 'cin'.
* Tous les exemples d'entrées du chapitre 3 jusqu'à III.22.
* \author Francois-R.Boyer@PolyMtl.ca
* \date 2013-09
* \file
**/

#define ENTREE_SIMULEE // Commenter ou décommenter cette ligne pour utiliser le vrai 'cin' ou prendre l'entrée en exemple dans les notes de cours.

bool AFFICHER_FIN_DE_FICHIER = false;
bool AFFICHER_CHAR_LU = false;
bool AFFICHER_APPELS = false;

//----------------------------------------------------------------------------
//{ Version spéciale de istream et ifstream pour afficher une trace du comportement. Vous n'avez pas à essayer de comprendre le code jusqu'au commentaire avec l'accolade fermante.
#define protected public // Ne "jamais" faire ceci dans un réel programme; pour fins pédagogiques, nous voulons visualiser le comportement interne du streambuf associé à cin, et ceci requiert de contourner la protection de la classe.
#include <streambuf>
#undef protected
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdarg>
#include <map>
#include <vector>
#include <typeinfo>

#ifdef ENTREE_SIMULEE
#define SI_ENTREE_SIMULEE(X) X
#else
#define SI_ENTREE_SIMULEE(X)
#endif

#define AFFICHE_ET_EXECUTE(ENONCE) cout << #ENONCE << endl; ENONCE
#define NOM_ET_ADRESSE_DE(X) #X,&X
#define LISTE_DES_VARIABLES ListeDeVariables listeDesVariables
#define AJOUTE_VARIABLE(X) listeDesVariables.ajoute(NOM_ET_ADRESSE_DE(X))

// Les caractères suivants supposent le codepage 850; un coin est utilisé pour le return puisqu'il n'y a pas de flèche dans ce codepage.
static const char COIN_HAUT_GAUCHE    = char(218U),
                  COIN_HAUT_DROIT     = char(191U),
                  COIN_BAS_GAUCHE     = char(192U),
                  COIN_BAS_DROIT      = char(217U),
                  LIGNE_HORIZONTALE   = char(196U),
                  LIGNE_VERTICALE     = char(179U),
                  SYMBOLE_RETURN      = char(217U),
				  CHAR_LU             = char(194U),
				  FIN_DE_FICHIER      = char(176U),
                  FLECHE_VERS_LE_HAUT = '^';

char caractereVersSymbole(char caractere)
{
	switch (caractere) {
		case '\n': caractere = SYMBOLE_RETURN; break;
		case char(-1): caractere = FIN_DE_FICHIER; break;
	}
	return caractere;
}

std::string typeDe(std::string& /*var*/)
{
	return "string";
}
std::string typeDe(const std::string& /*var*/)
{
	return "string";
}
template <typename T>
std::string typeDe(T& /*var*/)
{
	return typeid(T).name();
}
std::string formatteValeur(char val)
{
	return std::string("'") + caractereVersSymbole(val) + '\'';
}
std::string formatteValeur(const std::string& val)
{
	return '"' + val + '"';
}
std::string formatteValeur(float val)
{
	std::ostringstream tamponAffichage;
	tamponAffichage << std::showpoint << std::setprecision(7) << val;
	return tamponAffichage.str();
}
std::string formatteValeur(double val)
{
	std::ostringstream tamponAffichage;
	tamponAffichage << std::showpoint << std::setprecision(15) << val;
	return tamponAffichage.str();
}
std::string formatteValeur(bool val)
{
	return val ? "true" : "false";
}
template <typename T>
std::string formatteValeur(const T& val)
{
	std::ostringstream tamponAffichage;
	tamponAffichage << val;
	return tamponAffichage.str();
}

class ListeDeVariables {
	public:
		ListeDeVariables() { }
		ListeDeVariables(const char* nom, /*void* adresse,*/ ...) {
			va_list vars; va_start(vars, nom);
			const char* prochainNom = nom;
			while (prochainNom != NULL) {
				ajoute(prochainNom, va_arg(vars, void*));
				prochainNom = va_arg(vars, char*);
			}
			va_end(vars);
		}
		~ListeDeVariables() {
			efface();
		}
		void ajoute(const char* nom, void* adresse) {
			laListeGlobale[adresse] = nom;
			listeDAdresses.push_back(adresse);
		}
		void efface() {
			for (unsigned i = 0; i < listeDAdresses.size(); ++i)
				laListeGlobale.erase(listeDAdresses[i]);
			laListeGlobale.clear();
		}
		template <typename T>
		static std::string nomDe(const T& var) {
			std::map<void*, std::string>::const_iterator it = laListeGlobale.find((void*)&var);
			if (it == laListeGlobale.end())
				// Si le nom de la variable n'est pas connu, on utilise son adresse comme nom.
				return "[" + formatteValeur((void*)&var) + "]"; 
			else
				return it->second;
		}
		
		std::vector<void*> listeDAdresses;
		static std::map<void*, std::string> laListeGlobale;
};
std::map<void*, std::string> ListeDeVariables::laListeGlobale;

/// Permet l'affichage de l'état interne du tampon lors de l'entrée.
class StreambufVisuel : public std::streambuf
{
	public:
		StreambufVisuel() : streamSource_(NULL) {
			utiliserLeTamponNul();
		}
		StreambufVisuel(std::istream& streamSource) : streamSource_(&streamSource) {
			utiliserLeTamponNul();
		}
		void afficher(const std::string& texte = "") {
			std::string lignes[3];
			genereAffichageTampon(lignes);
			lignes[1] += "  ";
			lignes[1] += texte;
			for (int i = 0; i < 3; ++i)
				std::cout << lignes[i] << std::endl;
		}
		void remplirTampon(const std::string& texte, const std::string& message = "<- contenu initial du tampon.") {
			tamponString = texte;
			setg(&tamponString[0], &tamponString[0], &tamponString[0]);
			eof_ = false;
			afficher(message);
		}
		std::istream& source() {
			return *streamSource_;
		}
	
	private:
		int_type underflow() { // surcharge de la méthode de la classe de base
			if (gptr() < egptr())
				return *gptr();
			if (gptr() < eback() + tamponString.length()) {
				setg(eback(), gptr(), gptr() + 1);
				return *gptr();
			}
			if (streamSource_ != NULL) {
				std::streambuf* rdbuf = streamSource_->rdbuf();
				streamSource_->clear();
				streamSource_->ignore(rdbuf->in_avail());
				std::cout << "[Lecture alors que le tampon est vide; le programme attend une entree:]" << std::endl;
				streamSource_->peek();
				if (!streamSource_->eof()) {
					remplirTampon(std::string(rdbuf->eback(), size_t(rdbuf->egptr() - rdbuf->eback())),
						"<- tampon immediatement apres l'entree.");
					return *gptr();
				}
				else
					remplirTampon("", "<- fin de fichier sur le flot d'entree");
			}
			std::cout << "[Lecture alors que l'entree est epuisee.]" << std::endl;
			utiliserLeTamponNul();
			eof_ = true;
			return traits_type::eof();
		}
		
		void utiliserLeTamponNul() {
			setg(tamponNul,tamponNul,tamponNul);
		}
		
		void genereAffichageTampon(std::string lignes[3]) {
			char* tampon = eback();
			unsigned longueur = tamponString.length();
			unsigned longueurLue = unsigned(egptr() - tampon) + (eof_?1:0);
			unsigned positionActuelle = unsigned(gptr() - tampon);
			static const unsigned POSITION_DE_DEPART = 1;
			bool doitAfficherFinDeFichier = AFFICHER_FIN_DE_FICHIER && (streamSource_ == NULL || streamSource_->eof());
			genereCadre(longueur + 2 + doitAfficherFinDeFichier, lignes);
			if (AFFICHER_CHAR_LU)
				for (unsigned i = 0; i < longueurLue; ++i)
					lignes[0][POSITION_DE_DEPART + i] = CHAR_LU;
			for (unsigned i = 0; i < longueur; ++i)
				lignes[1][POSITION_DE_DEPART + i] = caractereVersSymbole(tampon[i]);
			if (doitAfficherFinDeFichier)
				lignes[1][POSITION_DE_DEPART + longueur] = FIN_DE_FICHIER;
			lignes[2][POSITION_DE_DEPART + positionActuelle] = FLECHE_VERS_LE_HAUT;
		}
		static void genereCadre(unsigned longueur, std::string lignes[3]) {
			unsigned gaucheDuCadre = 0;
			unsigned droiteDuCadre = longueur - 1;
			for (unsigned i = 0; i < 3; ++i)
				lignes[i].resize(longueur);
			lignes[0][gaucheDuCadre] = COIN_HAUT_GAUCHE;
			lignes[0][droiteDuCadre] = COIN_HAUT_DROIT;
			lignes[2][gaucheDuCadre] = COIN_BAS_GAUCHE;
			lignes[2][droiteDuCadre] = COIN_BAS_DROIT;
			lignes[1][gaucheDuCadre] = lignes[1][droiteDuCadre] = LIGNE_VERTICALE;
			for (unsigned i = gaucheDuCadre + 1; i < droiteDuCadre; ++i)
				lignes[0][i] = lignes[2][i] = LIGNE_HORIZONTALE;
		}
		
		std::istream* streamSource_;
		std::string tamponString;
		static char tamponNul[1];
		bool eof_;
};
char StreambufVisuel::tamponNul[1];

#ifdef ENTREE_SIMULEE
StreambufVisuel streambufVisuel;
#else
StreambufVisuel streambufVisuel(std::cin);
#endif
std::istream entreeVisuelle(&streambufVisuel);

/// Emballage d'un istream pour afficher les entrées faites.
class IStream {
	public:
		IStream(std::istream& leStream) : leStream_(leStream) { }
		void remplirTampon(const std::string& texte) {
			clear();
			StreambufVisuel* buf = dynamic_cast<StreambufVisuel*>(rdbuf());
			if (buf != NULL) // Si c'est un StreambufVisuel, on a une méthode spéciale pour le remplir.
				buf->remplirTampon(texte);
			else {
				std::istringstream* s = dynamic_cast<std::istringstream*>(&leStream_);
				if (s != NULL) // Si c'est un istringstream, il a aussi une méthode pour lui donner son tampon.
					s->str(texte);
				else {
					std::cout << "[**Erreur, ne sait pas comment remplir le tampon.**]" << std::endl;
				}
			}
		}
		void afficher(const std::string& texte = "") {
			StreambufVisuel* buf = dynamic_cast<StreambufVisuel*>(rdbuf());
			if (buf != NULL) // Si c'est un StreambufVisuel, on peut l'afficher.
				buf->afficher(texte);
			else
				std::cout << texte << std::endl;
		}
		template <typename T>
		void affichageApresLecture(const T& valeurLue, bool etaitErreur, bool afficherNomVariable = true, const std::string& message = "") {
			std::ostringstream tamponAffichage;
			if (!leStream_.fail()) {
				if (message == "")
					tamponAffichage << "lu " << typeDe(valeurLue) << " " << formatteValeur(valeurLue);
				else
					tamponAffichage << message;
				if (afficherNomVariable)
					tamponAffichage << ", dans la variable " << ListeDeVariables::nomDe(valeurLue) << ".";
			}
			else {
				if (message != "")
					tamponAffichage << "tentative de " << message << " ";
				if (etaitErreur)
					tamponAffichage << "echoue car deja en erreur";
				else {
					if (message == "")
						tamponAffichage << "lecture de " << typeDe(valeurLue);
					tamponAffichage << " echoue";
				}
				if (afficherNomVariable)
					tamponAffichage << ", " << ListeDeVariables::nomDe(valeurLue) << " contient encore " << formatteValeur(valeurLue) << ".";
				else
					tamponAffichage << ", donne " << typeDe(valeurLue) << " " << formatteValeur(valeurLue) << ".";
			}
			afficher(tamponAffichage.str());
		}
		bool afficherEtat(const std::string& fonction, bool valeur) {
			std::cout << ListeDeVariables::nomDe(*this) << "." << fonction << "() est " << (valeur ? "vrai" : "faux") << std::endl;
			return valeur;
		}
		
		operator std::istream&() { return leStream_; }
		
		// Certaines méthodes standard de istream:
		std::streambuf* rdbuf() { return leStream_.rdbuf(); }
		bool fail() { return afficherEtat("fail", leStream_.fail()); }
		bool eof()  { return afficherEtat("eof", leStream_.eof()); }
		bool good() { return afficherEtat("good", leStream_.good()); }
		operator bool() { return !fail(); }
		bool operator !() { return fail(); }
		void clear(std::ios::iostate state = std::ios::goodbit) { leStream_.clear(state); }
		IStream& get(char& c) {
			if (AFFICHER_APPELS) std::cout << ListeDeVariables::nomDe(*this) << ".get(" << ListeDeVariables::nomDe(c) << ")" << std::endl;
			bool etaitErreur = !leStream_.good();
			leStream_.get(c);
			affichageApresLecture(c, etaitErreur);
			return *this;
		}
		int get() {
			if (AFFICHER_APPELS) std::cout << ListeDeVariables::nomDe(*this) << ".get()" << std::endl;
			bool etaitErreur = !leStream_.good();
			int c = leStream_.get();
			affichageApresLecture(c, etaitErreur, false);
			return c;
		}
		int peek() {
			if (AFFICHER_APPELS) std::cout << ListeDeVariables::nomDe(*this) << ".peek()" << std::endl;
			bool etaitErreur = !leStream_.good();
			int c = leStream_.peek();
			affichageApresLecture(char(c), etaitErreur, false);
			return c;
		}
		IStream& ignore(int n = 1, int fin = std::istream::traits_type::eof()) {
			// bool etaitErreur = !leStream_.good();
			leStream_.ignore(n, fin);
			afficher("apres ignore.");
			return *this;
		}
		
		std::istream& leStream_;
	private:
		IStream& operator = (const IStream&);
};
template <typename T>
IStream& operator >> (IStream& cin, T& valeurLue) {
	if (AFFICHER_APPELS) std::cout << ListeDeVariables::nomDe(cin) << " >> " << ListeDeVariables::nomDe(valeurLue) << std::endl;	
	bool etaitErreur = !cin.leStream_.good();
	cin.leStream_ >> valeurLue;
	cin.affichageApresLecture(valeurLue, etaitErreur);
	return cin;
}
IStream& getline(IStream& cin, std::string& valeurLue, char fin = '\n') {
	bool etaitErreur = !cin.leStream_.good();
	if (AFFICHER_APPELS) std::cout << "getline(" << ListeDeVariables::nomDe(cin) << ", " << ListeDeVariables::nomDe(valeurLue) << ")" << std::endl; //TODO: on devrait afficher 'fin' aussi.	
	getline(static_cast<std::istream&>(cin), valeurLue, fin);
	cin.affichageApresLecture(valeurLue, etaitErreur);
	return cin;
}
IStream& ws(IStream& cin) {
	bool etaitErreur = !cin.leStream_.good();
	std::cout << "ws(" << ListeDeVariables::nomDe(cin) << ")" << std::endl;
	std::ws(static_cast<std::istream&>(cin));
	cin.affichageApresLecture(0, etaitErreur, false, "sauter les espace sur " + ListeDeVariables::nomDe(cin));
	return cin;
}
//}

using namespace std;

int main()
{
	double nbreReel;
	int    entier1, entier2;
	char   car1, car2;
	string chaine1, chaine2, chaine3;
	int    numero;
	string rue;
	
	IStream cin(entreeVisuelle); // Remplace 'cin' par une version qui affiche son état à chaque entrée.
	
	//{ Pour permettre d'afficher les noms des variables.
	LISTE_DES_VARIABLES;
	AJOUTE_VARIABLE(cin);
	AJOUTE_VARIABLE(nbreReel);
	AJOUTE_VARIABLE(entier1);
	AJOUTE_VARIABLE(entier2);
	AJOUTE_VARIABLE(car1);
	AJOUTE_VARIABLE(car2);
	AJOUTE_VARIABLE(chaine1);
	AJOUTE_VARIABLE(chaine2);
	AJOUTE_VARIABLE(chaine3);
	AJOUTE_VARIABLE(numero);
	AJOUTE_VARIABLE(rue);
	//}
	
	cout << "Lecture de valeurs numeriques (III.6-7)" << endl;
	SI_ENTREE_SIMULEE( cin.remplirTampon("  2.34 57   -81\n"); )
	AFFICHE_ET_EXECUTE(
	cin >> nbreReel;
	)
	AFFICHE_ET_EXECUTE(
	cin >> entier1 >> entier2;
	)
	
	cout << "Lecture de caracteres (III.8-9)" << endl;
	SI_ENTREE_SIMULEE( cin.remplirTampon("\n as \n L\n7\n"); )
	AFFICHE_ET_EXECUTE(
	cin >> car1 >> car2;
	)
	AFFICHE_ET_EXECUTE(
	cin >> car1;
	)
	AFFICHE_ET_EXECUTE(
	cin >> car2;
	)
	
	cout << "Lecture de caracteres avec get (III.11-13)" << endl;
	SI_ENTREE_SIMULEE( cin.remplirTampon("\na sL\n \n"); )
	AFFICHE_ET_EXECUTE(
	cin.get(car1);
	)
	AFFICHE_ET_EXECUTE(
	cin.get(car2);
	)
	AFFICHE_ET_EXECUTE(
	cin.get(car1);
	)
	AFFICHE_ET_EXECUTE(
	cin.get(car2);
	)
	AFFICHE_ET_EXECUTE(
	cin.get(car1);
	)
	
	cout << "Lecture de chaines de caracteres (III.14-15)" << endl;
	SI_ENTREE_SIMULEE( cin.remplirTampon("Fenetre ouverte\n"); )
	AFFICHE_ET_EXECUTE(
	cin >> chaine1;
	)
	AFFICHE_ET_EXECUTE(
	cin >> chaine1;
	)
	
	cout << "Lecture de chaines de caracteres avec getline (III.17-18)" << endl;
	SI_ENTREE_SIMULEE( cin.remplirTampon("Le ble est bon\n"); )
	AFFICHE_ET_EXECUTE(
	getline(cin, chaine1);
	)
	
	SI_ENTREE_SIMULEE( cin.remplirTampon("Le\nble \nest\n   "); )
	AFFICHE_ET_EXECUTE(
	getline(cin, chaine1);
	)
	AFFICHE_ET_EXECUTE(
	getline(cin, chaine2);
	)
	
	cout << "Lecture d'un nombre et une chaine avec getline (III.17-18)" << endl;
	SI_ENTREE_SIMULEE( cin.remplirTampon("3537\nGilford\n"); )
	AFFICHE_ET_EXECUTE(
	cin >> numero;
	)
	AFFICHE_ET_EXECUTE(
	getline(cin, rue);
	)
	
	SI_ENTREE_SIMULEE( cin.remplirTampon("3537\nLa bise\n"); )
	AFFICHE_ET_EXECUTE(
	cin >> numero;
	)
	AFFICHE_ET_EXECUTE(
	cin.ignore(1);
	)
	AFFICHE_ET_EXECUTE(
	getline(cin, rue);
	)
}
