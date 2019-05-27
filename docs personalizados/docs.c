#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leerEmpleados(FILE *empleadosFile, char **empleados, int tam);
void leerNota(FILE *nota);
void crearNotas(char **empleados, FILE *nota, int tam);
int contarEmpleados(FILE *empleadosFile);

int main()
{
	FILE *empleadosFile;
	FILE *nota;
	char **empleados;
	int noEmpleados;
	noEmpleados = contarEmpleados(empleadosFile);
	empleados = (char **)malloc(noEmpleados * sizeof(char *));
	for (int i = 0; i < noEmpleados; i++)
    {
        empleados[i] = (char *)malloc(50 * sizeof(char));
    }
	printf("numero de empleados: %d\n", noEmpleados);
	leerEmpleados(empleadosFile, empleados, noEmpleados);
	printf("\n");
	leerNota(nota);
	printf("\n");
	crearNotas(empleados, nota, noEmpleados);
	return 0;
}

int contarEmpleados(FILE *empleadosFile)
{
	char caracter;
	int contador = 0;
	empleadosFile = fopen("empleados.txt", "r");

	if (empleadosFile == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
	}
	else
	{
		while (!feof(empleadosFile))
		{
			caracter = fgetc(empleadosFile);
			if (caracter == '\n' || caracter == '\0' || caracter == EOF)
			{
				contador++;
			}
		}
	}
	fclose(empleadosFile);
	return contador;
}

void leerEmpleados(FILE *empleadosFile, char **empleados, int tam)
{

	char nombres[100];
	char *nombre;
	int i = 0;
	empleadosFile = fopen("empleados.txt", "r");
	if (empleadosFile == NULL)
	{
		printf("\nError de apertura del archivo. \n\n");
	}
	else
	{
		while (!feof(empleadosFile))
		{
			nombre = fgets(nombres, 100, empleadosFile);
			strcpy(empleados[i], strcat(nombre, ".txt"));
			puts(nombres);
			i++;
		}
	}
	fclose(empleadosFile);
}

void leerNota(FILE *nota)
{
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

void crearNotas(char **empleados, FILE *nota, int noEmpleados){
	int tam = noEmpleados, i = 0;
	nota = fopen("nota.txt", "r");
	for ( i=0 ; i < tam; i++)
	{
		FILE *notaFinal = fopen(empleados[i], "wt");
	}
	
}