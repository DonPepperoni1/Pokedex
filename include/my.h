#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <stddef.h>

//CRUD
char *date(void);
void CreatePokedexEntry(void);
void ReadCSV(void);
void DisplayPokedex(void);
void UpdatePokedex(void);
void DeletePokedexEntry(void);
void SavePokedex(void);
void sigint_handler(int);
void QuitGame(void);

//MAIN
void initialisation(void);
void choix_zone(void);
void action(void);

//POKEMON_DEPART
void carapuce(void);
void bulbizarre(void);
void salameche(void);

//ZONES
void foret(void);
void lac(void);
void grotte(void);
void herbes(void);
void centrale(void);

//int insert_node_at_the_end(*head* linked_list, char *, char *, char *, int);

#endif /*MY_H_*/
