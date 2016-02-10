#ifndef USABLEITEM_H_INCLUDED
#define USABLEITEM_H_INCLUDED

/*- Usableitem.h : contient l'ensemble des objets utilisable par une créature :
			- nom
			- valeur (valeur en or)
			- tour d'effectivité
			- action point vie
			- action attaque
			- action defense relative
			- action defense absolue
			- action esquive*/

typedef struct UsableItem{
    char* name;
    int price;
    int timeEffect;
    int bonusHP;
    int bonusATT;
    int bonusDEFRel;
    int bonusDEFAbs;
    int bonusESQ;
}UsableItem;

UsableItem* usableItem_ctor(char* name, int price, int TimeEffect, int bonusHP, int bonusATT, int bonusDEFRel, int bonusDEFAbs, int bonusESQ);

//Creation of list for UsableItem
struct node_item
{
    UsableItem item;
    struct node_item *p_next;
    struct node_item *p_prev;
} Node_item;

typedef struct useItem
{
    size_t length;
    struct node_item *p_tail;
    struct node_item *p_head;
} UseItem;

UseItem* readFromFile_item();
void writeToFile_item(UseItem *p_list);
UseItem *useItem_find_all(UseItem *p_list, UsableItem item);
UseItem *useItem_find(UseItem *p_list, UsableItem item);
size_t useItem_length(UseItem *p_list);
UseItem *useItem_remove_id(UseItem *p_list, int position);
UseItem *useItem_remove_all(UseItem *p_list, int item);
UseItem *useItem_remove(UseItem *p_list, UsableItem item);
void useItem_display(UseItem *p_list);
void useItem_delete(UseItem **p_list);
UseItem *useItem_insert(UseItem *p_list, UsableItem item, int position);
UseItem *useItem_prepend(UseItem *p_list, UsableItem item);
UseItem *useItem_append(UseItem *p_list, UsableItem item);
UseItem *useItem_new(void);
void printf_struct_item(UsableItem* item);

#endif // USABLEITEM_H_INCLUDED
