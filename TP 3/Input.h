#ifndef INPUT_H_
#define INPUT_H_
#include "LinkedList.h"

int mainMenu(void);
int SortMenu(LinkedList*);

int getInt(char *mensaje);
int ValideGetInt(int* numero, char *mensaje);
int ValidateRange(char *, int, int, int);

void getString(char* mensaje, char* cadena);
int getStringLetters(char* cadena);
int getStringNumbers(char* cadena);
void GetValidString (char* mensaje, char* cadena);
void GetValidStringNumbers (char* mensaje, char* cadena);

#endif
