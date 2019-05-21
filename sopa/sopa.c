#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MIN 6

void cambioLetras(char **A, int tam);
void inicializar(char **A, int tam);
void imprimir(char **A, int tam);
int getOrient();
int space(int pos, int tam);
int colocar(char **A, int tam, char *pal);
void llenarPalabras(char **A, int tam);

int main()
{
    char **A;
    int tam;
    srand(time(NULL));
    printf("Ingresa el tamaño (tamaño minimo 6x6)\n");
    scanf("%d", &tam);

    A = (char **)malloc(tam * sizeof(char *));
    for (int i = 0; i < tam; i++)
    {
        A[i] = (char *)malloc(tam * sizeof(char));
    }
    inicializar(A, tam);
    imprimir(A, tam);
    llenarPalabras(A,tam);
    printf("Palabras\n");
    imprimir(A, tam);
    cambioLetras(A,tam);
    printf("Sopa\n");
    imprimir(A,tam);
    return 0;
}

void llenarPalabras(char **A, int tam){
    char palabras[5][6] = {"hola", "gato", "perro", "agua", "raiz"};
    int band = 0;
    for (int i = 0; i < 5; i++)
    {
        while (band != 1)
        {
            band = colocar(A, tam, palabras[i]);
            //printf("band=%d\n", band);
        }
        band=0;
    }
}

int colocar(char **A, int tam, char *pal)
{
    int x, y;
    int tampal = strlen(pal);
    int orient = getOrient();
    int j;
    if (orient == 0)
    {
        x = rand() % tam;
        y = rand() % tam;
        int sp = space(x, tam);
        if (sp >= tampal)
        {
            j = 0;
            for (int i = x; i < tam; i++)
            {
                if (A[y][i] != '-')
                {
                    A[y][i] = A[y][i];
                    return 0;
                }
                else if (j < tampal)
                {
                    A[y][i] = pal[j];
                    j++;
                }
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        x = rand() % tam;
        y = rand() % tam;
        int sp = space(x, tam);
        if (sp >= tampal)
        {
            j = 0;
            for (int i = x; i < tam; i++)
            {
                if (A[i][y] != '-')
                {
                    A[i][y] = A[i][y];
                    return 0;
                }
                else if (j < tampal)
                {
                    A[i][y] = pal[j];
                    j++;
                }
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int space(int pos, int tam)
{
    return (tam - pos);
}

int getOrient()
{
    int b = rand() % 2;
    return b;
}

void imprimir(char **A, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf("| %c |", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void inicializar(char **A, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            strcpy(&A[i][j], "-");
        }
    }
}

void cambioLetras(char **A, int tam)
{
    char letra;
    char *pletra = &letra;
    char letras[26];
    int i = 0, r;
    for (letra = 'a'; letra <= 'z'; letra++)
    {
        letras[i] = *pletra;
        i++;
    } /*
    for (int i = 0; i < 26; i++)
    {
        printf("%c", letras[i]);
    }*/
    for (int i = 0; i < tam; i++)
    {
        for (int y = 0; y < tam; y++)
        {
            if (A[i][y] == '-')
            {
                r = rand() % 26;
                A[i][y] = letras[r];
            }
        }
    }
}