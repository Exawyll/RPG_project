/*- GameUtil.c : contient l'ensemble des fonctions utilitaires (redondante ou non) du programme
			- doRand(int start, int end)
			- https://openclassrooms.com/courses/les-listes-doublement-chainees-en-langage-c
			- ...*/

//Return a random number between MAX and MIN
/*int doRand(int MIN, int MAX){
    srand(time(NULL));
    return (rand() % (MAX - MIN + 1)) + MIN;
}

//Roll the dices to attack
int rollDice_attack(){
    int sumAttack = 0;
    int dice6 = doRand(1, 6);
    int dice4a = doRand(1, 4);
    int dice4b = doRand(1, 4);
    sumAttack = dice6 + dice4a + dice4b;
    return sumAttack;
}

//Roll the dice to dodge
int rollDice_dodge(){
    return doRand(1, 8);
}*/

