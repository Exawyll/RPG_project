#include <stdio.h>
#include <stdlib.h>

#include "usableItems.h"

/*- Usableitem.c : contient les fonctions suivantes :
			- doUsableItemEffect(Usableitem* item, Mob* mob)
			- removeUsableItemEffect(Usableitem* item, Mob* mob)
			- sellUsableitem(Usableitem* item, Player* player)*/

UsableItem* usableItem_ctor(char* name, int price, int timeEffect, int bonusHP, int bonusATT, int bonusDEFRel, int bonusDEFAbs, int bonusESQ){
    UsableItem* p = malloc(sizeof(UsableItem));
    p->name = name;
    p->price = price;
    p->timeEffect = timeEffect;
    p->bonusHP = bonusHP;
    p->bonusATT = bonusATT;
    p->bonusDEFRel = bonusDEFRel;
    p->bonusDEFAbs = bonusDEFAbs;
    p->bonusESQ = bonusESQ;
    return p;
}

//Allow to display correct info of list items
void printf_struct_item(UsableItem* item)
{
    printf("%s %d %d %d %d %d %d %d\n",item->name,item->price,item->timeEffect,item->bonusHP,item->bonusATT,item->bonusDEFRel,item->bonusDEFAbs,item->bonusESQ);
}

/*int* display_list_ids(UseItem *p_list)
{
}*/

//Create a new list
UseItem *useItem_new(void)
{
    UseItem *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

//Add element at the end of the list
UseItem *useItem_append(UseItem *p_list, UsableItem item)
{
    if (p_list != NULL) /* On vérifie si notre liste a été allouée */
    {
        struct node_item *p_new = malloc(sizeof *p_new); /* Création d'un nouveau node_item */
        if (p_new != NULL) /* On vérifie si le malloc n'a pas échoué */
        {
            p_new->item = item; /* On 'enregistre' notre donnée */
            p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
            if (p_list->p_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
            {
                p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL */
                p_list->p_head = p_new; /* On fait pointer la tête de liste vers le nouvel élément */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers le nouvel élément */
            }
            else /* Cas où des éléments sont déjà présents dans notre liste */
            {
                p_list->p_tail->p_next = p_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
                p_new->p_prev = p_list->p_tail; /* On fait pointer p_prev vers le dernier élément de la liste */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
            }
            p_list->length++; /* Incrémentation de la taille de la liste */
        }
    }
    return p_list; /* on retourne notre nouvelle liste */
}

//Add element at start of the list
UseItem *useItem_prepend(UseItem *p_list, UsableItem item)
{
    if (p_list != NULL)
    {
        struct node_item *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->item = item;
            p_new->p_prev = NULL;
            if (p_list->p_tail == NULL)
            {
                p_new->p_next = NULL;
                p_list->p_head = p_new;
                p_list->p_tail = p_new;
            }
            else
            {
                p_list->p_head->p_prev = p_new;
                p_new->p_next = p_list->p_head;
                p_list->p_head = p_new;
            }
            p_list->length++;
       }
    }
    return p_list;
}

//Insert an element at the position choice
//Warning: position have to start to 1 and end to the current number of items
//Warning: use only if you already have an item in the list
UseItem *useItem_insert(UseItem *p_list, UsableItem item, int position)
{
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list = useItem_append(p_list, item);
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list = useItem_prepend(p_list, item);
                }
                else
                {
                    struct node_item *p_new = malloc(sizeof *p_new);
                    if (p_new != NULL)
                    {
                        p_new->item = item;
                        p_temp->p_next->p_prev = p_new;
                        p_temp->p_prev->p_next = p_new;
                        p_new->p_prev = p_temp->p_prev;
                        p_new->p_next = p_temp;
                        p_list->length++;
                    }
                }
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

//This will unallocate the entire list this cannot be access after
void useItem_delete(UseItem **p_list)
{
    if (*p_list != NULL)
    {
        struct node_item *p_temp = (*p_list)->p_head;
        while (p_temp != NULL)
        {
            struct node_item *p_del = p_temp;
            p_temp = p_temp->p_next;
            free(p_del);
        }
        free(*p_list), *p_list = NULL;
    }
}

//This display the list
void useItem_display(UseItem *p_list)
{
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            printf_struct_item(&p_temp->item);
            fflush(stdout);
            p_temp = p_temp->p_next;
        }
    }
    printf("\n");
}

//Remove the first item regarding the item parameter
UseItem *useItem_remove(UseItem *p_list, UsableItem item)
{
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->item == &item)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

//Remove all items regarding the item parameter
UseItem *useItem_remove_all(UseItem *p_list, int item)
{
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (&p_temp->item == &item)
            {
                struct node_item *p_del = p_temp;
                p_temp = p_temp->p_next;
                if (p_del->p_next == NULL)
                {
                    p_list->p_tail = p_del->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_del->p_prev == NULL)
                {
                    p_list->p_head = p_del->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_del->p_next->p_prev = p_del->p_prev;
                    p_del->p_prev->p_next = p_del->p_next;
                }
                free(p_del);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

//Remove item with selected position
UseItem *useItem_remove_id(UseItem *p_list, int position)
{
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

//Return current list size
size_t useItem_length(UseItem *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

//Return choosen item to a new list
UseItem *useItem_find(UseItem *p_list, UsableItem item)
{
    UseItem *ret = NULL;
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->item == &item)
            {
                ret = useItem_new();
                ret = useItem_append(ret, item);
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return ret;
}

//Return all choosen items to a new list
UseItem *useItem_find_all(UseItem *p_list, UsableItem item)
{
    UseItem *ret = NULL;
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (&p_temp->item == &item)
            {
                if (ret == NULL)
                {
                    ret = useItem_new();
                }
                ret = useItem_append(ret, item);
            }
            p_temp = p_temp->p_next;
        }
    }
    return ret;
}

//region saving/loading
//Write the whole list in a file
void writeToFile_item(UseItem *p_list){
    FILE *fptr;
    fptr=fopen("./list_item.txt","w+");

    UsableItem* item = malloc(sizeof(UsableItem));
    if (p_list != NULL)
    {
        struct node_item *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            item = &p_temp->item;
            fwrite(item,sizeof(UsableItem),1,fptr);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }
    fclose(fptr);
}

//Read a list of structure to display it
UseItem* readFromFile_item(){
    UseItem *p_list = useItem_new();
    UsableItem* item = malloc(sizeof(UsableItem));
    FILE *fptr;

    fptr=fopen("./list_item.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(item,sizeof(UsableItem),1,fptr) == 1) {
            useItem_append(p_list, *usableItem_ctor(item->name,item->price,item->timeEffect,item->bonusHP,item->bonusATT,item->bonusDEFRel,item->bonusDEFAbs,item->bonusESQ));
        }
        printf("\n");
    }

    fclose(fptr);

    return p_list;
}
//endregion
