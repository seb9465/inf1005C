//////////////////////////////////////////////////////////////////////////////
///    \file CodeDemande.hpp
///  \author Charles Hosson
/// \version Dernière entrée : 10 novembre 2014
///   \since Création : 12 septembre 2014
///
/// Les déclarations des fonctions qui doivent être écrites par les élèves.
//////////////////////////////////////////////////////////////////////////////

#pragma once


#pragma region "Includes"//{ -------------------------------------------------

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <string>

#include "CodeFourni.hpp"

using namespace std;

#pragma endregion//}


#pragma region "Déclarations"//{ ---------------------------------------------

#pragma region "Entêtes de fonctions"//{ -------------------------------------

// TODO: Mettre les prototypes ici.
void insererCible(ListeCibles& listeCible, Cible cible);
void importerCibles(ListeCibles& listeCibles, string nomFichier);
void chargerToutesCibles(ListeCibles& listeCibles, string nomFichier);
void sauvegarderCible(Cible cible, string nomFichier);
void produireRapport(ListeCibles liste, string nomFichier);
void demanderMiseAJourCible(Cible& cible);

#pragma endregion//}

#pragma endregion//}

