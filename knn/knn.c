#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CARGADOS 5

struct cer
{
    char clase;
    float distancia;
};
typedef struct nodo
{
    int numero;
    char clase;
    float coord[3];
    struct cer cercanos[100];
} Nodo;

void principal();
void ingresarNodo(Nodo *nodos, int tam);
void cargarNodos(Nodo *nodos, int tam);
void imprimirNodos(Nodo *nodos, int tam);
void ingresarNodos(Nodo *nodos, int tam);
float calcDist(Nodo nodoF, Nodo nodoI);
void guardarDist(Nodo *nodos, int tam);
void calcularClase(Nodo *nodo, int tam);

int main()
{
    principal();
    return 0;
}

void principal()
{
    Nodo *nodos;
    int tam;
    printf("Cuantos nodos va a ingresar(Existentes: 5)\n");
    scanf("%d", &tam);
    fflush(stdin);
    tam += CARGADOS;
    nodos = (Nodo *)malloc(tam * sizeof(Nodo));
    cargarNodos(nodos, tam);
    ingresarNodos(nodos, tam);
    guardarDist(nodos, tam);
    imprimirNodos(nodos, tam);
}

void calcularClase(Nodo *nodo, int tam)
{
    float menor;
    int i;

    if (nodo->clase == '\0')
    {
        for (i = 0; i < tam; i++)
        {
            if (i != (nodo->numero - 1))
            {
                if (i == 0)
                {
                    menor = nodo->cercanos[i].distancia;
                }
                else if (nodo->cercanos[i].distancia <= menor)
                {
                    menor = nodo->cercanos[i].distancia;
                }
            }
        }
        for (i = 0; i < tam; i++)
        {
            if (nodo->cercanos[i].distancia == menor)
            {
                nodo->clase = nodo->cercanos[i].clase;
            }
        }
    }
}

void guardarDist(Nodo *nodos, int tam)
{
    int i, j;
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if (j != i)
            {
                //printf("NodoActual (%d,%d))%c,%f\n",i,j,nodos[j].clase,calcDist(nodos[j],nodos[i]));
                nodos[i].cercanos[j].clase = nodos[j].clase;
                nodos[i].cercanos[j].distancia = calcDist(nodos[j], nodos[i]);
            }
        }
        if (nodos[i].clase == '\0')
        {
            calcularClase(&nodos[i], tam);
        }
        printf("%c",nodos[i].clase);
    }
}

float calcDist(Nodo nodoF, Nodo nodoI)
{
    float suma, dist;
    suma = dist = 0;
    for (int i = 0; i < 3; i++)
    {
        suma += pow(nodoF.coord[i] - nodoI.coord[i], 2);
    }
    dist = sqrt(suma);
    return dist;
}

void ingresarNodos(Nodo *nodos, int tam)
{
    int i;
    for (i = CARGADOS; i < tam; i++)
    {
        nodos[i].numero = i + 1;
        printf("Coordenadas:\n");
        printf("X: ");
        scanf("%f", &nodos[i].coord[0]);
        fflush(stdin);
        printf("\nY: ");
        scanf("%f", &nodos[i].coord[1]);
        fflush(stdin);
        printf("\nZ: ");
        scanf("%f", &nodos[i].coord[2]);
        fflush(stdin);
    }
}

void imprimirNodos(Nodo *nodos, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("-------------------------------\n");
        printf("|Numero: %d   |  Clase: %c      |\n", nodos[i].numero, nodos[i].clase);
        printf("|Coordenadas:");
        printf("|(%.2f,%.2f,%.2f)|\n", nodos[i].coord[0], nodos[i].coord[1], nodos[i].coord[2]);
        for (int j = 0; j < tam; j++)
        {
            if (j != i)
            {
                printf("|Clase: %c|", nodos[i].cercanos[j].clase);
                printf("Distancia: %.2f|", nodos[i].cercanos[j].distancia);
            }
        }
        printf("\n-------------------------------\n");
    }
}

void cargarNodos(Nodo *nodos, int tam)
{
    nodos[0].numero = 1;
    nodos[0].clase = 'A';
    nodos[0].coord[0] = 2.34;
    nodos[0].coord[1] = 3.23;
    nodos[0].coord[2] = 6.43;
    nodos[1].numero = 2;
    nodos[1].clase = 'A';
    nodos[1].coord[0] = 3.44;
    nodos[1].coord[1] = 0.23;
    nodos[1].coord[2] = 5.93;
    nodos[2].numero = 3;
    nodos[2].clase = 'B';
    nodos[2].coord[0] = 1.44;
    nodos[2].coord[1] = 0.03;
    nodos[2].coord[2] = 1.03;
    nodos[3].numero = 4;
    nodos[3].clase = 'B';
    nodos[3].coord[0] = 0.44;
    nodos[3].coord[1] = 2.03;
    nodos[3].coord[2] = 1.93;
    nodos[4].numero = 5;
    nodos[4].clase = 'C';
    nodos[4].coord[0] = 6.44;
    nodos[4].coord[1] = 4.23;
    nodos[4].coord[2] = 5.93;
}