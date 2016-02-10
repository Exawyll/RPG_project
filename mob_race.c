#include <stdio.h>
#include <stdlib.h>

#include "mob_race.h"

MobRace* MobRace_ctor(char* name, int R_bonusHP, int R_bonusATT, int R_bonusDEFRel, int R_bonusDEFAbs, int R_bonusESQ){
    MobRace* p = malloc(sizeof(MobRace));
    p->name = name;
    p->R_bonusHP = R_bonusHP;
    p->R_bonusATT = R_bonusATT;
    p->R_bonusDEFRel = R_bonusDEFRel;
    p->R_bonusDEFAbs = R_bonusDEFAbs;
    p->R_bonusESQ = R_bonusESQ;
    return p;
}

//Allow to display correct info of list items
void printf_struct_race(MobRace* mobRace)
{
    printf("%s %d %d %d %d %d\n", mobRace->name, mobRace->R_bonusHP, mobRace->R_bonusATT, mobRace->R_bonusDEFRel, mobRace->R_bonusDEFAbs, mobRace->R_bonusESQ);
}

/*int* display_list_ids(Race *p_list)
{
}*/

//Create a new list
Race *race_new(void)
{
    Race *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

//Add element at the end of the list
Race *race_append(Race *p_list, MobRace mobRace)
{
    if (p_list != NULL) /* On vérifie si notre liste a été allouée */
    {
        struct node_race *p_new = malloc(sizeof *p_new); /* Création d'un nouveau node_race */
        if (p_new != NULL) /* On vérifie si le malloc n'a pas échoué */
        {
            p_new->mobRace = mobRace; /* On 'enregistre' notre donnée */
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
Race *race_prepend(Race *p_list, MobRace mobRace)
{
    if (p_list != NULL)
    {
        struct node_race *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->mobRace = mobRace;
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
Race *race_insert(Race *p_list, MobRace mobRace, int position)
{
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list = race_append(p_list, mobRace);
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list = race_prepend(p_list, mobRace);
                }
                else
                {
                    struct node_race *p_new = malloc(sizeof *p_new);
                    if (p_new != NULL)
                    {
                        p_new->mobRace = mobRace;
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
void race_delete(Race **p_list)
{
    if (*p_list != NULL)
    {
        struct node_race *p_temp = (*p_list)->p_head;
        while (p_temp != NULL)
        {
            struct node_race *p_del = p_temp;
            p_temp = p_temp->p_next;
            free(p_del);
        }
        free(*p_list), *p_list = NULL;
    }
}

//This display the list
void race_display(Race *p_list)
{
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            printf_struct_race(&p_temp->mobRace);
            fflush(stdout);
            p_temp = p_temp->p_next;
        }
    }
    printf("\n");
}

//Remove the first item regarding the mobRace parameter
Race *race_remove(Race *p_list, MobRace mobRace)
{
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->mobRace == &mobRace)
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

//Remove all items regarding the mobRace parameter
Race *race_remove_all(Race *p_list, int mobRace)
{
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (&p_temp->mobRace == &mobRace)
            {
                struct node_race *p_del = p_temp;
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
Race *race_remove_id(Race *p_list, int position)
{
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
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
size_t race_length(Race *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

//Return choosen item to a new list
Race *race_find(Race *p_list, MobRace mobRace)
{
    Race *ret = NULL;
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->mobRace == &mobRace)
            {
                ret = race_new();
                ret = race_append(ret, mobRace);
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
Race *race_find_all(Race *p_list, MobRace mobRace)
{
    Race *ret = NULL;
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (&p_temp->mobRace == &mobRace)
            {
                if (ret == NULL)
                {
                    ret = race_new();
                }
                ret = race_append(ret, mobRace);
            }
            p_temp = p_temp->p_next;
        }
    }
    return ret;
}

//region saving/loading
//Write the whole list in a file
void writeToFile_race(Race *p_list){
    FILE *fptr;
    fptr=fopen("./list_race.txt","w+");

    MobRace* mobRace = malloc(sizeof(MobRace));
    if (p_list != NULL)
    {
        struct node_race *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            mobRace = &p_temp->mobRace;
            fwrite(mobRace,sizeof(MobRace),1,fptr);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }
    fclose(fptr);
}

//Read a list of structure to display it
Race* readFromFile_race(){
    Race *p_list = race_new();
    MobRace* mobRace = malloc(sizeof(MobRace));
    FILE *fptr;

    fptr=fopen("./list_race.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(mobRace,sizeof(MobRace),1,fptr) == 1) {
            race_append(p_list, *MobRace_ctor(mobRace->name, mobRace->R_bonusHP, mobRace->R_bonusATT, mobRace->R_bonusDEFRel, mobRace->R_bonusDEFAbs, mobRace->R_bonusESQ));
        }
        printf("\n");
    }

    fclose(fptr);

    return p_list;
}
//endregion

//Create different races
void createMobRace(){
    Race* raceList = race_new();

    MobRace *gobelin = MobRace_ctor("Gobelin", 0, 1, 10, 1, 0);
    MobRace *human = MobRace_ctor("Human", 10, 2, 10, 2, 2);
    MobRace *elf = MobRace_ctor("Elf", 5, 1, 20, 1, 3);
    MobRace *orc = MobRace_ctor("Orc", 12, 3, 5, 4, 0);

    race_append(raceList, *gobelin);
    race_append(raceList, *human);
    race_append(raceList, *elf);
    race_append(raceList, *orc);

    race_display(raceList);

    writeToFile_race(raceList);
    Race* newList = readFromFile_race();

    race_display(newList);

}
