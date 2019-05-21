#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define TAM 200

void principal();
void histo(char[]);
void caracteres(int tam);

int main()
{
    principal();
    return 0;
}

void principal()
{
    char palabra[TAM];

    printf("Ingresa la palabra\n");
    gets(palabra);
    histo(palabra);
}

void histo(char palabra[])
{
    int tam = strlen(palabra);
    int a[256];
    int i;
    char car;
    for (i = 0; i < 256; i++)
    {
        a[i] = 0;
    }
    for (i = 0; i < tam; i++)
    {
        car = palabra[i];
        a[car]++;
    }
    for (i = 0; i < 255; i++)
    {
        if (a[i] != 0)
        {
            if (i == 32)
            {
                printf("Space: ");
                caracteres(a[i]);
            }
            else
            {
                printf("%c: ", i);
                caracteres(a[i]);
            }
        }
    }
}

void caracteres(int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("*");
    }
    printf("\n");
}