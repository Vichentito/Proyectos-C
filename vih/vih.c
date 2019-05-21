
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int celulas[3][3];
    char estados[] = {'V', 'A', 'B', 'M'};
    int ra = 4;
    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            celulas[i][j] = 0;
        }
    }
    int w;
    while (ra > 0)
    {
        w = celulas[rand() % 4][rand() % 4];
        printf("1.- %d \n", w);
        ra--;
    }
    printf("\n\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (celulas[i][j] == 0)
            {
                printf("| %c |", estados[0]);
            }
            else if (celulas[i][j] == 1)
            {
                printf("| %c |", estados[1]);
            }
            else if (celulas[i][j] == 2)
            {
                printf("| %c |", estados[2]);
            }
            else if (celulas[i][j] == 3)
            {
                printf("| %c |", estados[3]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
    
    return 0;
}
