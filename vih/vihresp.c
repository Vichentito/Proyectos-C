
#include <stdio.h>
#include <stdlib.h>

void grilla();
void evolucion();

int filas, columnas;
char vida[60][60];

int main()
{
    int celulas = 0, estado = 0;
    int a, b, c, f, fcel, ccel, ciclos = 1;
    char tecla = 48;
    for (a = 0; a <= 59; a++)
    {
        for (b = 0; b <= 59; b++)
        {
            vida[a][b] = ' '; // Inicializo la matriz con celulas muertas
        }
    }
    printf("     JUEGO DE LA VIDA\n");
    while (filas < 5 || filas > 10 || columnas < 5 || columnas > 10)
    {
        printf("\nIngrese la cantidad de filas y columnas bajo el formato: FILAS COLUMNAS: "); // Capturo el tamaño de la grilla
        scanf("%i %i", &filas, &columnas);
        if (filas < 5 || filas > 10 || columnas < 5 || columnas > 10)
            printf("Error, recuerde que el tamaño minimo es 5x5 y el maximo es 10x10\n");
    }

    grilla();                                           // Pinto la grilla
    while (celulas < 3 || celulas > (filas * columnas)) // Capturo la cantidad de celulas
    {
        printf("Ingrese la cantidad de celulas vivas: ");
        scanf("%i", &celulas);
        if (celulas < 3 || celulas > (filas * columnas))
            printf("\nError, recuerde que la cantidad minima son 3 y el maximo es %i\n\n", filas * columnas);
    }
    printf("\nIngrese la pocision de las celulas vivas bajo el formato: FIL COL\n\n");
    for (a = 1; a <= celulas; a++)
    {
        printf("Ingrese la pocision de la celula #%i: ", a);
        scanf("%i %i", &fcel, &ccel); // Capturo la pocision de cada celula
        f = 2;
        for (b = 1; b < fcel; b++)
            f++;
        c = 2;
        for (b = 1; b < ccel; b++)
            c++;
        if (fcel < 1 || fcel > filas || ccel < 1 || ccel > columnas)
        {
            printf("\nError, recuerde que la pocision minima es 1 1 y la pocision maxima es %i %i\n\n", filas, columnas);
            a--;
        }
        else if (vida[(fcel + f) * 2][(ccel + c) * 2] == '0') // Pregunto si en la pocision escogida ya existia una celula
        {
            printf("\nError, En la pocision %i %i ya existe una celula\n\n", fcel, ccel);
            a--;
        }
        else
            vida[(fcel + f) * 2][(ccel + c) * 2] = '0'; // Guardo la celula viva
    }
    for (a = 1; a <= ciclos; a++) // Proceso evolutivo
    {
        grilla();           // Pinto grilla
        while (estado == 0) // Pregunto si ya se capturaron la cantidad de ciclos
        {
            grilla();                                                            // Pinto grilla y celulas
            printf("Ingrese la cantidad de ciclos que el juego evolucionara: "); // Capturo la cantidad de ciclos a evolucionar
            scanf("%i", &ciclos);
            if (ciclos < 1)
            {
                printf("\nError, Debe haber al menos un ciclo evolutivo\n\n");
                system("pause");
            }
            else
                a = estado = 1; // Refresco la pantalla
        }
        evolucion();        // Evolucionan las celulas
        grilla();           // Pinto celulas
        while (a == ciclos) // Pregunto si ya se ejecutaron la cantidad de ciclos deseados
        {
            getchar();
            printf("Desea visualizar mayor cantidad de ciclos evolutivos? (s\\n): ");
            scanf("%c", &tecla);
            switch (tecla)
            {
            case 's':
                estado = 0;
                a--;
                break;
            case 'n':
                a++;
                break;
            default:
                printf("\nError, Solo se deben ingresar los caracteres 's' o 'n'\n\n");
            }
        }
        if (a <= ciclos)
            system("pause"); // Finalizo un ciclo evolutivo
    }
    return 0;
}

void grilla()
{
    int a, b, fil = 0, col = 0;
    system("cls");
    printf("     JUEGO DE LA VIDA\n\n");
    for (a = 1; a <= filas + 1; a++)
    {
        fil += 4;
        for (b = 4; b <= (columnas * 4) + 4; b++) // Armo las Columnas
            vida[fil][b] = '-';
    }
    for (a = 1; a <= columnas + 1; a++)
    {
        col += 4;
        for (b = 5; b < (filas * 4) + 4; b++) // Armoo las Filas
            vida[b][col] = '|';
    }
    printf("\n");
    printf("     ");
    for (a = 1; a <= filas; a++) // Pinto los Números de las Columnas
        printf("%i   ", a);
    printf("\n");
    fil = 6;
    col = 2;
    for (a = 4; a <= (filas * 4) + 4; a++)
    {
        if (fil == a)
        {
            printf("%2i ", (a / 2) - col); // Pinto los Numeros de las Filas
            fil += 4;
            col++;
        }
        else
            printf("   ");
        for (b = 4; b <= (columnas * 4) + 4; b++)
        {
            printf("%c", vida[a][b]); // Pinto celulas Vivas y Muertas
        }
        printf("\n");
    }
    printf("\n");
}

void evolucion()
{
    int a, b, c, d, contador;
    char copia[60][60];
    for (a = 0; a <= 59; a++)
    {
        for (b = 0; b <= 59; b++)
        {
            copia[a][b] = vida[a][b]; // Hago una copia de la grilla
        }
    }
    for (a = 6; a <= (filas * 4) + 2; a += 4)
    {
        for (b = 6; b <= (columnas * 4) + 2; b += 4)
        {
            contador = -1; // Contador esta en -1 pensando en que se contara a si mismo una ves si esta viva
            for (c = a - 4; c <= a + 4; c += 4)
            {
                for (d = b - 4; d <= b + 4; d += 4)
                {
                    if (vida[c][d] == '0') // Reviso si hay celulas vivas alrededor
                        contador++;
                }
            }
            if ((contador < 2 || contador == 4) && vida[a][b] == '0')
                copia[a][b] = ' '; // Si hay 0,1 o 4 celulas vivas alrededor muere
            else if (contador == 2 && vida[a][b] == ' ')
                copia[a][b] = '0'; // Si hay 3 celulas vivas alrededor resucita
        }
    }
    for (a = 0; a <= 59; a++)
    {
        for (b = 0; b <= 59; b++)
        {
            vida[a][b] = copia[a][b]; // Guardo los cambios en vida
        }
    }
}
