#include "my.h"

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

//Definition de la structure
struct pokedex
{
    char Nom[50];
    char Type[50];
    char Zone[20];
    char DateDec[15];
    char DateCapt[15];
    int number;

    struct pokedex *next;
    struct pokedex *prev;
    struct pokedex *current;
} *head;

#endif /* __LINKED_LIST__*/

// DEFINE
#define CSV_FILE_TO_READ "pokemons.csv"

//fonction date pour retourner la date du jour
char *date(void)
{
  int day, mois, an;
  time_t now;
  char *date = malloc(sizeof(char) * 50);

  // Renvoie l'heure actuelle
  time(&now);
  // Convertir au format heure locale
  struct tm *local = localtime(&now);
  day = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
  // Afficher la date courante
  sprintf(date, "%02d/%02d/%d\n", day, mois, an);
  printf("%s\n", date);
  return date;
}

void CreatePokedexEntry(void) 
{
    char *name = malloc(sizeof(char) * 50);
    char *type = malloc(sizeof(char) * 50);
    char *zone = malloc(sizeof(char) * 50);
    char *date_dec = malloc(sizeof(char) * 50);
    char *date_capt = malloc(sizeof(char) * 50);
    char *yesno = malloc(sizeof(char) * 50);
    struct pokedex *pokemons = malloc(sizeof(struct pokedex));

    printf("Quel Pokémon avez vous vu ?\n\n");
    scanf("%s", name);
    strcpy(pokemons->Nom, name);

    printf("Quel est le type du Pokémon ?\n");
    scanf ("%s", type);
    strcpy(pokemons->Type, type);

    printf("Quelle est la zone de rencontre avec le Pokémon ?\n");
    scanf ("%s", zone);
    strcpy(pokemons->Zone, zone);

    printf("Quand avez-vous découvert ce pokémon ? \n");
    scanf("%s", date_dec);
    strcpy(pokemons->DateDec, date_dec);
    while(1){
        printf("Avez-vous capturé ce pokémon ?\n");
        printf("1 - OUI\n");
        printf("2 - NON\n");
        scanf ("%s", yesno);
        if (strcmp(yesno,"1") == 0){
            printf("Quand avez-vous capturé ce pokémon ? \n");
            scanf("%s", date_capt);
            strcpy(pokemons->DateCapt, date_capt);
            printf("\nFélicitations, vous avez capturé un %s de type %s dans %s\n\n", pokemons->Nom,pokemons->Type,pokemons->Zone);
            pokemons->next = head;
            head = pokemons;
            break;
        }
        else if (strcmp(yesno,"2") == 0){
            printf("c'est dommage !\n");
            break;
        }
        else
            printf("La valeur rentrée n'est pas correcte\n");
    }
    return;
}

void ReadCSV(void)  // affiche le contenu de la liste chaînée
{
    FILE *fPointer;
    fPointer = fopen(CSV_FILE_TO_READ,"r");

    if (fPointer == NULL)
    {
        printf("\nCould not open file %s",CSV_FILE_TO_READ);
        return;
    }
    // lis le fichier et créé la liste chaînée
    char parsedLine[150];
    while(fgets(parsedLine, 150, fPointer) != NULL)
    {
        struct pokedex *pokemons = malloc(sizeof(struct pokedex));

        char *getNom = strtok(parsedLine, ";");
        strcpy(pokemons->Nom, getNom);

        char *getType = strtok(NULL, ";");
        strcpy(pokemons->Type, getType);

        char *getZone = strtok(NULL, ";");
        strcpy(pokemons->Zone, getZone);

        char *getDateDec = strtok(NULL, ";");
        strcpy(pokemons->Zone, getDateDec);

        char *getDateCapt = strtok(NULL, ";");
        strcpy(pokemons->Zone, getDateCapt);

        pokemons->next = head;
        head = pokemons;
    }
    fclose(fPointer);
}

void DisplayPokedex(void)
{
    struct pokedex *temp;
    temp=head;
    printf("Nom Type Zone Date_Découverte Date_Capture\n");
    while(temp!=NULL)
    {
        printf("%s %s %s %s %s\n",temp->Nom,temp->Type,temp->Zone,temp->DateDec,temp->DateCapt);
        temp = temp->next;
    }
}

void UpdatePokedex(void) 
{
    char *name = malloc(sizeof(char) * 50);
    char *updateentry = malloc(sizeof(char) * 50);
    char *tomodify = malloc(sizeof(char) * 50);
    struct pokedex *temp;
    temp=head;

    if(temp == NULL) {
        printf("\nLe pokédex est vide, veuillez renseigner un pokémon\n");
    }

    else {
        printf("Rentrez le nom du pokémon que vous voulez changer : \n");
        scanf("%s", tomodify);
        while(temp!=NULL) {
            if (strcmp(tomodify, temp->Nom) == 0) {
                printf("\nRentrez le nouveau nom du Pokémon : \n");
                scanf("%s", updateentry);
                strcpy(temp->Nom, updateentry);
                printf("\nChangé en %s \n\n", temp->Nom);
            }

            else {
                temp = temp->next;
            }
        }
    }
    free(name);
    free(updateentry);
    free(tomodify);
}

void DeletePokedexEntry(void) 
{
    char *todelete = malloc(sizeof(char) * 50);
    struct pokedex *temp;
    temp=head;
    struct pokedex *prev;
    prev=temp;

    if(temp == NULL) {
        printf("\nLe pokédex est vide, veuillez renseigner un pokémon\n");
    }
    else {
        printf("\nRentrez le nom du pokémon que vous voulez supprimer : \n");
        scanf("%s", todelete);
    }
    if (strcmp(todelete, temp->Nom) == 0) {
        head = temp->next;
        return;
    }
    while(temp!=NULL) {
        if (strcmp(todelete, temp->Nom) == 0) {
            prev->next = temp->next;
            free(temp);
            return;
        }

        else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void SavePokedex(void){
    FILE *fPointer;
    fPointer = fopen(CSV_FILE_TO_READ,"w");
    struct pokedex *temp;
    temp=head;

    if (fPointer == NULL)
    {
        printf("\nCould not open file %s",CSV_FILE_TO_READ);
        return;
    }
    while(temp!=NULL){
        fprintf(fPointer, "%s;", temp->Nom);
        fprintf(fPointer, "%s;", temp->Type);
        fprintf(fPointer, "%s\n", temp->Zone);
        temp = temp->next;
    }
    fclose(fPointer);
}

void sigint_handler(int sig)
{
    signal(sig, SIG_IGN);
    signal(SIGINT, sigint_handler);
    char *ctrlc = malloc(sizeof(char) * 50);    
    while(1){
        printf("\nQue voulez vous faire ?\n");
        printf("1 - Quitter sans sauvegarder \n");
        printf("2 - Sauvegarder puis quitter\n");
        printf("3 - Ne pas quitter\n");
        scanf ("%s", ctrlc);
        if (strcmp(ctrlc,"1") == 0){
            exit(1);
        }
        else if (strcmp(ctrlc,"2") == 0){
            SavePokedex();
            exit(1);
        }
        else if (strcmp(ctrlc, "3") == 0){
            printf("on continue !\n");
            return;
        }
        else {
            printf("La valeur rentrée n'est pas correcte\n");
            return;
        } 
    }
    free(ctrlc);
}

void QuitGame(void)
{
    char *quit = malloc(sizeof(char) * 50);
    while(1){
        printf("Etes-vous sûr de vouloir quitter ?\n");
        printf("1 - OUI\n");
        printf("2 - NON\n");
        scanf ("%s", quit);
        if (strcmp(quit,"1") == 0){
            exit(1);
        }
        else if (strcmp(quit,"2") == 0){
            printf("on continue !\n");
            return;
        }
        else {
            printf("La valeur rentrée n'est pas correcte\n");
            return;
        }
    }
    free(quit);
}
