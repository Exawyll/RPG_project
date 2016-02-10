#ifndef STUFFITEM_H_INCLUDED
#define STUFFITEM_H_INCLUDED

/*- StuffItem.h : contient l'ensemble des caractéristiques d'un objet porté par une créature :
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

//Creation of list for stuffItem
struct node_stuff
{
    StuffItem stuff;
    struct node_stuff *p_next;
    struct node_stuff *p_prev;
} Node_stuff;

typedef struct item
{
    size_t length;
    struct node_stuff *p_tail;
    struct node_stuff *p_head;
} Item;

Item* readFromFile_stuff();
void writeToFile_stuff(Item *p_list);
Item *item_find_all(Item *p_list, StuffItem stuff);
Item *item_find(Item *p_list, StuffItem stuff);
size_t item_length(Item *p_list);
Item *item_remove_id(Item *p_list, int position);
Item *item_remove_all(Item *p_list, int stuff);
Item *item_remove(Item *p_list, StuffItem stuff);
void item_display(Item *p_list);
void item_delete(Item **p_list);
Item *item_insert(Item *p_list, StuffItem stuff, int position);
Item *item_prepend(Item *p_list, StuffItem stuff);
Item *item_append(Item *p_list, StuffItem stuff);
Item *item_new(void);
void printf_struct_stuff(StuffItem* stuff);

#endif // STUFFITEM_H_INCLUDED
