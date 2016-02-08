#ifndef STUFFITEM_H_INCLUDED
#define STUFFITEM_H_INCLUDED

/*- StuffItem.h : contient l'ensemble des caract�ristiques d'un objet port� par une cr�ature :
			- nom
			- valeur (valeur en or)
			- type (tete, torse, jambe, botte, main droite, main gauche)
			- point de vie
			- attaque
			- defense relative
			- defense absolue*/

//Gives attributes to all the items which equip a creature
typedef struct StuffItem{
    char* name;
    int price;
    int type;
    int I_bonusHP;
    int I_bonusATT;
    int I_bonusDEFRel;
    int I_bonusDEFAbs;
}StuffItem;

//prototype for the stuffItem builder
StuffItem* stuffItem_ctor(char* name, int price, int type, int I_bonusHP, int I_bonusATT, int I_bonusDEFRel, int I_bonusDEFAbs);

#endif // STUFFITEM_H_INCLUDED
