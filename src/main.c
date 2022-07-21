#include "my.h"

/*
int main(int ac, char **av) 
{
    printf("ott");
}*/

void initialisation(void){
    int i = 0;
    //Initialisation de la partie
    printf("Bonjour et bienvenue dans votre nouvelle aventure ! \n");
    printf("Choisissez votre pokemon pour commencer : \n");
    printf("1- Bulbizarre \n");
    printf("2- Carapuce \n");
    printf("3- Salamèche \n");

    scanf("%d", &i);

    void (*array_fptr[3])(void);
    array_fptr[0] = &bulbizarre;
    array_fptr[1] = &carapuce;
    array_fptr[2] = &salameche;

    array_fptr[i-1]();
    
    printf("Tout au long de l'aventure, vous devrez choisir la direction que \n");
    printf("vous souhaitez emprunter. Commençons !\n\n");
}

void choix_zone(void){
    int choix = 0;
    printf("Dans quel zone voulez-vous avancer pour rencontrer des pokémons ?\n");
    printf("1 - La Forêt \n");
    printf("2 - Le Lac \n");
    printf("3 - La Grotte \n");
    printf("4 - La Hautes Herbes \n");
    printf("5 - La Centrale électrique \n");

    scanf ("%d", &choix);

    void (*array_zone[5])(void);
    array_zone[0] = &foret;
    array_zone[1] = &lac;
    array_zone[2] = &grotte;
    array_zone[3] = &herbes;
    array_zone[4] = &centrale;

    array_zone[choix-1]();
}

void action(void){
    int action = 0;
    printf ("\nQue voulez-vous faire ?\n");
    printf("1 - J'ai vu un Pokémon!\n");
    printf("2 - J'aimerais modifier une entrée\n");
    printf("3 - J'aimerais supprimer une entrée du Pokédex\n");
    printf("4 - J'aimerais voir le pokedex\n");
    printf("5 - SAUVEGARDER - Sauvegarder le Pokédex\n");
    printf("6 - QUITTER - Quitter le Pokédex (!! sans sauvegarder !!)\n\n");

    scanf ("%d", &action);

    void (*array_action[6])(void);
    array_action[0] = &CreatePokedexEntry;
    array_action[1] = &UpdatePokedex;
    array_action[2] = &DeletePokedexEntry;
    array_action[3] = &DisplayPokedex;
    array_action[4] = &SavePokedex;
    array_action[5] = &QuitGame;

    array_action[action-1]();
}

//////////////////
// FONCTION MAIN//
//////////////////

int main(void)
{
    signal(SIGINT, &sigint_handler);
    initialisation();
    choix_zone();
    ReadCSV();
    while(1){
        action();
    }
    return 0;
}