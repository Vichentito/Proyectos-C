#include <stdio.h>
#include <stdlib.h>

void leerEmpleados();
void leerNota();

int main()
{
	leerEmpleados();
	printf("\n");
	leerNota();
	return 0;
}

void leerEmpleados()
{
	FILE *empleados;
	char caracter;
	empleados = fopen("empleados.txt", "r");

	if (empleados == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
	}
	else
	{
		printf("\nEl contenido del archivo de empleados es \n");
		while ((caracter = fgetc(empleados)) != EOF)
		{
			printf("%c", caracter);
		}
	}
	fclose(empleados);
}

void leerNota()
{
	FILE *nota;
	char caracter;
	nota = fopen("nota.txt", "r");

	if (nota == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
	}
	else
	{
		printf("\nEl contenido del archivo de nota es \n");
		while ((caracter = fgetc(nota)) != EOF)
		{
			printf("%c", caracter);
		}
	}
	fclose(nota);
}