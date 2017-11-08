//////////////////////////////////////////////////////////////////////////////
///    \file CodeFourni.hpp
///  \author Charles Hosson
/// \version Dernière entrée : 10 novembre 2014
///   \since Création : 12 septembre 2014
///
/// Le code fourni aux élèves est constitué des structures d'enregistrement
/// et des énumérations utilisées, de certaines données globales et de
/// fonctions utilitaires faisant entre autre le formatage et la convertion
/// de différentes données.
//////////////////////////////////////////////////////////////////////////////

#pragma once


#pragma region "Includes"//{ -------------------------------------------------

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <string>

using namespace std;

#pragma endregion//}


#pragma region "Déclarations"//{ ---------------------------------------------

#pragma region "Enums et constantes"//{ --------------------------------------

enum IndexForme : uint32_t
{
	TRIANGLE,
	CERCLE,
	LOSANGE,
	ETOILE,
	CROIX,
	RECTANGLE,
	DEMI_CERCLE,
	TRAPEZE,
	NB_INDEX_FORME,
	FORME_INCONNUE = UINT32_MAX
};

enum IndexCouleur : uint32_t
{
	NOIR,
	ROUGE,
	VERT,
	BLEU,
	MAUVE,
	ORANGE,
	JAUNE,
	GRIS,
	BLANC,
	NB_INDEX_COULEUR,
	COULEUR_INCONNUE = UINT32_MAX
};

static const size_t MAX_NB_CIBLES = 32;

static const size_t TAILLE_NOM_IMAGE = 32;

#pragma endregion//}


#pragma region "Structures d'enregistrement"//{ ------------------------------

/**
 * \struct Cible
 *  \brief Enregistrement qui représente une cible détectée.
 * 
 * Une cible possède un numéro unique dans [1, 99], une position, une
 * orientation, une forme et sa couleur, une séquence de lettre et sa
 * couleur, ainsi que le nom du fichier image la représentant.
 */
struct Cible
{
	uint32_t     id;
	double       latitude;
	double       longitude;
	double       orientation;
	IndexForme   forme;
	IndexCouleur couleurForme;
	char         lettres[4];
	IndexCouleur couleurLettres;
	char         nomImage[TAILLE_NOM_IMAGE];
};


/**
 * \struct ListeCibles
 *  \brief Une liste de plusieurs cibles.
 * 
 * Une liste de cibles sous forme d'un tableau de cibles, dont la capacité
 * est déterminée par la constante \c MAX_NB_CIBLES, qui est donc la taille
 * maximale de la liste. \c nbElems donne le nombre de cibles contenues dans
 * la liste (pas la taille du tableau).
 */
struct ListeCibles
{
	Cible  elems[MAX_NB_CIBLES];
	size_t nbElems;
};

#pragma endregion//}


#pragma region "Entêtes de fonctions"//{ -------------------------------------

string formaterLatitude ( double );

string formaterLongitude ( double );

string formaterOrientation ( double );

string formaterCible ( const Cible& );

double convertirLatitude ( const string& );

double convertirLongitude ( const string& );

Cible convertirEnCible ( const string& );

IndexForme indexerForme ( const string& );

IndexCouleur indexerCouleur ( const string& );

void trierListeCibles ( ListeCibles& );


extern const string NOMS_FORMES[NB_INDEX_FORME];

extern const string NOMS_COULEURS[NB_INDEX_COULEUR];

extern const string POINTS_CARDINAUX[8];

extern const string DONNEE_INCONNUE;

#pragma endregion//}

#pragma endregion//}
