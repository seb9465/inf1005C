/**
* Code fournis aux étudiants qui défini les structures d'enregistrement 
* utilisées dans le travail dirigé 6.
* \file   CodeFourni.h
* \author Karim Keddam et François-R Boyer
* \date   25 novembre 2014
* Créé le 20 septembre 2014
*/

#pragma once

/**
* \struct Livre
*  \brief Enregistrement qui représente un livre.
*
* Un livre possède une cote de rangement, un titre, une année d'édition [0, 3000],
* un nombre d'exemplaires [0, 200], et un nombre d'exemplaires disponibles [0, 200].
*/
struct Livre {
	char cote[8];
	wchar_t titre[50];
	short anneeEdition;
	unsigned char  nExemplaires;
	unsigned char nDisponibles;
};

/**
* \struct Collection
*  \brief Enregistrement qui représente une collection de livre.
*
* Une collection sous forme d'un tableau de pointeurs de livres, 
* dont la capacité est déterminée par l'arttribut \c nLivresAlloues .
* \c nbElems donne le nombre de livre contenues dans la collection (pas la 
* taille du tableau).
*/
struct Collection {
	int nLivresAlloues; //taille tableau
	int nLivres;
	Livre** livres;
};
