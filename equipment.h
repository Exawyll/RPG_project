#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include "stuffItems.h"

/*- Equipment.h : contient l'ensemble des objets port� par une cr�ature :
			- tete
			- torse
			- jambe
			- botte
			- main droite
			- main gauche*/

typedef struct Equipment{
    StuffItem* head;
    StuffItem* body;
    StuffItem* legs;
    StuffItem* foots;
    StuffItem* rightHand;
    StuffItem* leftHand;
}Equipment;

Equipment* Equipment_ctor(StuffItem* head, StuffItem* body, StuffItem* legs, StuffItem* foots, StuffItem* rightHand, StuffItem* leftHand);

#endif // EQUIPMENT_H_INCLUDED
