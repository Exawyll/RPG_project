/*- Usableitem.h : contient l'ensemble des objets utilisable par une cr�ature :
			- nom
			- valeur (valeur en or)
			- tour d'effectivit�
			- action point vie
			- action attaque
			- action defense relative
			- action defense absolue
			- action esquive*/

typedef struct UsableItem{
    char* name;
    int price;
    int TimeEffect;
    int bonusHP;
    int bonusATT;
    int bonusDEFRel;
    int bonusDEFAbs;
    int bonusESQ;
}UsableItem;

UsableItem* usableItem_ctor(char* name, int price, int TimeEffect, int bonusHP, int bonusATT, int bonusDEFRel, int bonusDEFAbs, int bonusESQ);
