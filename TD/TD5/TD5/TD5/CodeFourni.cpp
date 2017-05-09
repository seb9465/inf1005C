//////////////////////////////////////////////////////////////////////////////
///    \file CodeFourni.cpp
///  \author Charles Hosson
/// \version Dernière entrée : 10 novembre 2014
///   \since Création : 12 septembre 2014
///
/// L'implémentation du code fourni aux élèves.
//////////////////////////////////////////////////////////////////////////////


#pragma region "Includes"//{ -------------------------------------------------

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>

#include "CodeFourni.hpp"

using namespace std;

#pragma endregion//}


#pragma region "Fonctions"//{ ------------------------------------------------

/**
 * Convertit une latitude décimale en degrés/minutes/secondes selon le
 * format spécifique de la compétition, c'est à dire "A## ## ##.###", où
 * 'A' est soit 'N' ou 'S'
 * 
 *  \param [in] latitude
 *         La latitude numérique en degrés décimaux.
 * \return La latitude formatée en degrés/minutes/secondes.
 */
string
formaterLatitude ( double latitude )
{
	string resultat;
	
	if ( -90.0 <= latitude and latitude <= 90.0 ) {
		double absLatitude = abs(latitude);
		
		double secondes = fmod(absLatitude / (1.0 / 60.0 / 60.0), 60.0);
		int minutes = (int)(absLatitude / (1.0 / 60.0)) % 60;
		int degres = (int)floor(absLatitude);
		
		char tampon[64] = "";
		sprintf_s(tampon, "%02i %02i %06.3f", degres, minutes, secondes);
		
		resultat = (( latitude < 0.0 ) ? "S" : "N");
		resultat += tampon;
	}
	else {
		resultat = DONNEE_INCONNUE;
	}
	
	return resultat;
}


/**
 * Convertit une longitude décimale en degrés/minutes/secondes selon le
 * format spécifique de la compétition, c'est à dire "A### ## ##.###", où
 * 'A' est soit 'W' ou 'E'
 * 
 *  \param [in] longitude
 *         La longitude numérique en degrés décimaux.
 * \return La longitude formatée en degrés/minutes/secondes.
 */
string
formaterLongitude ( double longitude )
{
	string resultat;
	
	if ( -180.0 <= longitude and longitude <= 180.0 ) {
		double absLongitude = abs(longitude);
		
		double secondes = fmod(absLongitude / (1.0 / 60.0 / 60.0), 60.0);
		int minutes = (int)(absLongitude / (1.0 / 60.0)) % 60;
		int degres = (int)floor(absLongitude);
		
		char tampon[64] = "";
		sprintf_s(tampon, "%03i %02i %06.3f", degres, minutes, secondes);
		
		resultat = (( longitude < 0.0 ) ? "W" : "E");
		resultat += tampon;
	}
	else {
		resultat = DONNEE_INCONNUE;
	}
	
	return resultat;
}


/**
 * Arrondit l'orientation en degrés à un huitième de la rose des vents,
 * c'est-à-dire N, NE, E, SE, S, SW, W, NW.
 *
 *  \param [in] orientation
 *         L'orientation en degrés (sens horaire, partant du Nord).
 * \return Le point cardinal le plus proche.
 */
string
formaterOrientation ( double orientation )
{
	string resultat;
	
	if ( 0.0 <= orientation and orientation <= 360.0 ) {
		int secteur = (int)round(orientation / 45.0) % 8;
		
		resultat = POINTS_CARDINAUX[secteur];
	}
	else {
		resultat = DONNEE_INCONNUE;
	}
	
	return resultat;
}


/**
 * Prend une cible et construit une string selon le format de la compétition.
 *
 *  \param [in] cible
 *         La cible à formater.
 * \return La chaîne formatée.
 */
string
formaterCible ( const Cible& cible )
{
	ostringstream resultat;
	
	resultat << setfill('0') << setw(2) << cible.id << "\t"
	         << formaterLatitude(cible.latitude) << "\t"
	         << formaterLongitude(cible.longitude) << "\t"
	         << formaterOrientation(cible.orientation) << "\t";
	
	if ( cible.forme != FORME_INCONNUE )
		resultat << NOMS_FORMES[cible.forme] << "\t";
	else
		resultat << DONNEE_INCONNUE << "\t";
	
	if ( cible.couleurForme != COULEUR_INCONNUE )
		resultat << NOMS_COULEURS[cible.couleurForme] << "\t";
	else
		resultat << DONNEE_INCONNUE << "\t";
	
	if ( cible.lettres != string("") )
		resultat << cible.lettres << "\t";
	else
		resultat << DONNEE_INCONNUE << "\t";
	
	if ( cible.couleurLettres != COULEUR_INCONNUE )
		resultat << NOMS_COULEURS[cible.couleurLettres] << "\t";
	else
		resultat << DONNEE_INCONNUE << "\t";
	
	resultat << cible.nomImage;
	
	return resultat.str();
}


/**
 * Convertit la latitude formatée selon les requis de la compétition en
 * valeur décimale.
 *
 *  \param [in] latitude
 *         La latitude formatée en degrés/minutes/secondes.
 * \return La latitude numérique en degrés décimaux.
 */
double
convertirLatitude ( const string& latitude )
{
	double resultat = stod(latitude.substr(1, 2)) +
	                  stod(latitude.substr(4, 2)) / 60.0 +
	                  stod(latitude.substr(7, 6)) / 60.0 / 60.0;
	
	if ( latitude[0] == 'S' )
		resultat *= -1.0;
	
	return resultat;
}


/**
 * Convertit la longitude formatée selon les requis de la compétition en
 * valeur décimale.
 *
 *  \param [in] longitude
 *         La longitude formatée en degrés/minutes/secondes.
 * \return La longitude numérique en degrés décimaux.
 */
double
convertirLongitude ( const string& longitude )
{
	double resultat = stod(longitude.substr(1, 3)) +
	                  stod(longitude.substr(5, 2)) / 60.0 +
	                  stod(longitude.substr(8, 6)) / 60.0 / 60.0;
	
	if ( longitude[0] == 'W' )
		resultat *= -1.0;
	
	return resultat;
}


/**
 * Prend une string formatée selon le format décrit dans l'énoncé, et
 * construit une cible à partir de ces informations. La vérification du
 * format de la string n'est pas nécessaire.
 *
 *  \param [in] ligne
 *         La ligne formatée à interpréter.
 * \return La cible construite.
 */
Cible
convertirEnCible ( const string& ligne )
{
	Cible resultat = {};
	
	istringstream sstrm(ligne);
	
	sstrm >> dec >> resultat.id; sstrm.ignore();
	
	string str;
	
	getline(sstrm, str, '\t');
	resultat.latitude = convertirLatitude(str);
	
	getline(sstrm, str, '\t');
	resultat.longitude = convertirLongitude(str);
	
	sstrm >> str;
	for ( int i = 0; i < 8; i++ ) {
		if ( str == POINTS_CARDINAUX[i] )
			resultat.orientation = (double)i * 45.0;
	}
	
	sstrm >> str;
	resultat.forme = indexerForme(str);
	
	sstrm >> str;
	resultat.couleurForme = indexerCouleur(str);
	
	sstrm >> str;
	strncpy_s(resultat.lettres, 4, str.c_str(), str.length());
	
	sstrm >> str;
	resultat.couleurLettres = indexerCouleur(str);
	
	sstrm.get(); getline(sstrm, str);
	strncpy_s(resultat.nomImage, TAILLE_NOM_IMAGE, str.c_str(), str.length());
	
	return resultat;
}


/**
 * Trouve l'index, c'est-à-dire la valeur numérique associée à une forme,
 * dans le tableau \c NOMS_FORMES.
 * 
 *  \param [in] nomForme
 *         Le nom de la forme, ex. \c "Cercle".
 * \return L'index du nom de la forme, \c FORME_INCONNUE si le nom
 *         n'est pas connu (présent dans le tableau \c NOMS_FORMES).
 */
IndexForme
indexerForme ( const string& nomForme )
{
	IndexForme resultat = FORME_INCONNUE;
	
	for ( size_t i = 0; i < NB_INDEX_FORME; i++ ) {
		if ( nomForme == NOMS_FORMES[i] )
			resultat = (IndexForme)i;
	}
	
	return resultat;
}


/**
 * Trouve l'index, c'est-à-dire la valeur numérique associée à une couleur,
 * dans le tableau \c NOMS_COULEURS.
 * 
 *  \param [in] nomCouleur
 *         Le nom de la couleur, ex. \c "Bleu".
 * \return L'index du nom de la couleur, \c COULEUR_INCONNUE si le nom
 *         n'est pas connu (présent dans le tableau \c NOMS_COULEURS).
 */
IndexCouleur
indexerCouleur ( const string& nomCouleur )
{
	IndexCouleur resultat = COULEUR_INCONNUE;
	
	for ( size_t i = 0; i < NB_INDEX_COULEUR; i++ ) {
		if ( nomCouleur == NOMS_COULEURS[i] )
			resultat = (IndexCouleur)i;
	}
	
	return resultat;
}


/**
 * Trie la liste de cibles en ordre croissant de numéro.
 * 
 * \param [in,out] cibles
 *        La liste de cibles à trier.
 */
void
trierListeCibles ( ListeCibles& cibles )
{
	auto comparer = []
	( const Cible& lht, const Cible& rht )
	-> bool
	{
		return lht.id < rht.id;
	};
	
	if ( cibles.nbElems > 1 )
		sort(&cibles.elems[0], &cibles.elems[0] + cibles.nbElems, comparer);
}

#pragma endregion//}


#pragma region "Données"//{ --------------------------------------------------

const string
NOMS_FORMES[NB_INDEX_FORME] = {"Triangle", "Cercle", "Losange", "Etoile",
                               "Croix", "Rectangle", "Demi-cercle","Trapeze"};

const string
NOMS_COULEURS[NB_INDEX_COULEUR] = {"Noir", "Rouge", "Vert", "Bleu", "Mauve",
                                   "Orange", "Jaune", "Gris", "Blanc"};

const string
POINTS_CARDINAUX[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

const string
DONNEE_INCONNUE = "N/A";

#pragma endregion//}
