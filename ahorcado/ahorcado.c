#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#define TAM 100

void principal();
void impCaso();
int elegirPal(char pal[TAM], char txt[TAM]);
int comprobar(char pal[TAM], char c, int tam);
void dibujar(int err, char pal[TAM]);

int main()
{
    principal();
    return 0;
}

void principal()
{
    char pal[TAM],txt[TAM];
    int longitud;
    printf("\n\t=======================================");
    printf("\n\t           JUEGO DEL AHORCADO");
    printf("\n\t=======================================");
    printf("\n\tInstrucciones: Se te dara una palabra y tienes 5");
    printf("\n\tintentos para acertarla. En cada intento podrs elegir una letra.");
    printf("\n\tBUENA SUERTE!!!");
    printf("\n\n");
    printf("\nPulsa una tecla para empezar...");
    getch();
    system("cls");
    elegirPal(pal,txt);
    dibujar(0, pal);
}

int comprobar(char pal[TAM], char c, int tam)
{
    int i;
    for (i = 0; i <= tam; i++)
    {
        if (pal[i] == c)
        {
            return i;
        }
        else
        {
            return 0;
        }
    }
}

int elegirPal(char pal[TAM],char txt[TAM])
{
    char datos[12][9] = {
        "anteojo", "avioneta", "zapallo", "martir",
        "espejo", "anzuelo", "heciano", "tripode",
        "insecto", "agujero", "carnada", "cabeza"};
    int r, len;
    srand(time(NULL));
    r = rand() % 12;
    len = strlen(datos[r]);
    txt[0] = datos[r][0];
    txt[len - 1] = datos[r][len - 1];
    return len;
}

void dibujar(int err, char pal[TAM])
{
    system("cls");
    switch (err)
    {
    case 0:
        printf("\t  _ _ \n");
        printf("\t |    \n");
        printf("\t |    \n");
        printf("\t |    \n");
        printf("\t_|_   \n");
        break;
    case 1:
        printf("\t  _ _ _\n");
        printf("\t |   | \n");
        printf("\t |     \n");
        printf("\t |     \n");
        printf("\t_|_    \n");
        break;
    case 2:
        printf("\t  _ _ _\n");
        printf("\t |   | \n");
        printf("\t |   o \n");
        printf("\t |     \n");
        printf("\t_|_    \n");
        break;
    case 3:
        printf("\t  _ _ _\n");
        printf("\t |   | \n");
        printf("\t |   o \n");
        printf("\t |   | \n");
        printf("\t_|_    \n");
        break;
    case 4:
        printf("\t  _ _ _\n");
        printf("\t |   | \n");
        printf("\t |   o \n");
        printf("\t |   | \n");
        printf("\t_|_ /  \n");
        break;
    case 5:
        printf("\t  _ _ _ \n");
        printf("\t |   |  \n");
        printf("\t |   o  \n");
        printf("\t |   |  \n");
        printf("\t_|_ / \\ \n");
        break;
    }
}
