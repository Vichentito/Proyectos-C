#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leerEmpleados(FILE *empleadosFile, char **empleados, int tam);
void leerNota(FILE *nota);
void crearNotas(char **empleados, FILE *nota, int tam);
int contarEmpleados(FILE *empleadosFile);
void llenarNotas(char **empleados, FILE *nota, int tam);

int main()
{
	FILE *empleadosFile;
	FILE *nota;
	char **empleados;
	int noEmpleados;
	printf("El programa tomara el mensaje dentro del archivo nota.txt y\n");
	printf("lo copiará, personalizandolo para cada uno de los empleados\n");
	printf("que se encuentren dentro del archivo empleados.txt\n");
	printf("Para que la personalizacion se lleve a cabo se debera colocar\n");
	printf("un guión medio (-) donde se desee que se coloque el nombre del empleado\n");
	printf("Los archivos empleados.txt y nota.txt deben de ser ya existentes al inicio del programa.\n");
	noEmpleados = contarEmpleados(empleadosFile);
	empleados = (char **)malloc(noEmpleados * sizeof(char *));
	for (int i = 0; i < noEmpleados; i++)
	{
		empleados[i] = (char *)malloc(50 * sizeof(char));
	}
	//printf("numero de empleados: %d\n", noEmpleados);
	leerEmpleados(empleadosFile, empleados, noEmpleados);
	//leerNota(nota);
	crearNotas(empleados, nota, noEmpleados);
	llenarNotas(empleados, nota, noEmpleados);
	printf("Notas personalizadas finalizadas\n");
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
			nombre = strtok(fgets(nombres, 100, empleadosFile), "\n");
			strcpy(empleados[i], nombre);
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

void crearNotas(char **empleados, FILE *nota, int noEmpleados)
{
	int tam = noEmpleados, i = 0;
	char caracter, charname;
	nota = fopen("nota.txt", "r");
	for (i = 0; i < tam; i++)
	{
		char tempname[65];
		strcpy(tempname, empleados[i]);
		FILE *notaFinal = fopen(strcat(tempname, ".txt"), "wt");
		fclose(notaFinal);
	}
}

void llenarNotas(char **empleados, FILE *nota, int tam)
{

	int i;
	char caracter;

	for (i = 0; i < tam; i++)
	{
		char tempname[65];
		strcpy(tempname, empleados[i]);
		FILE *notaToEmpl = fopen(strcat(tempname, ".txt"), "a");
		nota = fopen("nota.txt", "rt");
		if (nota == NULL)
		{
			printf("\nError de apertura del archivo. \n\n");
		}
		else
		{
			if (notaToEmpl == NULL)
			{
				printf("\nError de apertura del archivo. \n\n");
			}
			else
			{
				while (!feof(nota))
				{
					caracter = fgetc(nota);
					if (caracter != EOF)
					{
						if (caracter == '-')
						{
							for (int j = 0; j < strlen(empleados[i]); j++)
							{
								char tempchar = empleados[i][j];
								fputc(tempchar, notaToEmpl);	
							}
						}else
						{
							fputc(caracter, notaToEmpl);
						}
					}
				}
				fclose(notaToEmpl);
			}
			fclose(nota);
		}
	}
}