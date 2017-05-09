//////////////////////////////////////////////////////////////////////////////
/// VOTRE ENTÊTE ICI
//////////////////////////////////////////////////////////////////////////////


#pragma region "Includes"//{ -------------------------------------------------

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "CodeDemande.hpp"
#include "CodeFourni.hpp"

using namespace std;

#pragma endregion//}


int main ( )
{
	const string nomRapportPartiel = "RapportFinalPartiel.txt";
	const string nomCiblesFournies = "Cibles.data";
	const string nomCiblesAjoutees = "Cibles2.data";
	const string nomRapportFinal = "RapportFinal.txt";
	
	// On crée une liste de cibles vide.
	ListeCibles lesCibles = { {}, 0 };
	
	// TODO: Importer les cibles présentes dans le rapport partiel. Certaines
	//       de ces cibles ont des informations manquantes.
	//       Le nom du fichier est donné par «nomRapportPartiel».
	importerCibles(lesCibles, nomRapportPartiel);
	
	// TODO: Charger les cibles du fichier binaire donné.
	//       Le nom du fichier est donné par «nomCiblesFournies».
	chargerToutesCibles(lesCibles, nomCiblesFournies);
	
	// TODO: Créer un autre fichier binaire qui va contenir les informations
	//       manquantes aux cibles du rapport partiel.
	//       Le nom du fichier est donné par «nomCiblesAjoutees».
	sauvegarderCible(lesCibles.elems[0], nomCiblesAjoutees);
	sauvegarderCible(lesCibles.elems[10], nomCiblesAjoutees);

	// TODO: Demander à l'utilisateur de mettre à jour la cible 1 et 11,
	//       c'est-à-dire les cibles incomplètes. Les cibles mises à jour sont
	//       sauvegardées dans le fichier binaire créé juste avant, pas
	//       directement dans la liste. Utilisez donc une cible temporaire.
	Cible cibleTemp1 = lesCibles.elems[0];
	demanderMiseAJourCible(cibleTemp1);
	Cible cibleTemp11 = lesCibles.elems[10];
	demanderMiseAJourCible(cibleTemp11);
	sauvegarderCible(cibleTemp1, nomCiblesAjoutees);
	sauvegarderCible(cibleTemp11, nomCiblesAjoutees);

	// TODO: Mettre à jour la liste à partir du fichier binaire contenant les
	//       informations ajoutées dans l'énoncé.
	chargerToutesCibles(lesCibles, nomCiblesAjoutees);
	
	// TODO: Produire le rapport final qui devrait contenir les 11 cibles
	//       complétées et formatées en ordre de numéro.
	//       Le nom du fichier est donné par «nomRapportFinal».
	produireRapport(lesCibles, nomRapportFinal);
	
	return 0;
}

