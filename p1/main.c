/*
 Instituto Politécnico Nacional
 Escuela Superior de Cómputo
 Algoritmia y prog. Estructurada
 Grupo: 1CV1
 Profesor: Benjamín Luna Benoso
 Semestre: 2019-2
 Práctica No. 1
 @@@@@Programa que calcula el area de un triangulo y convierte la hora de formato 24 hrs a 12 hrs@@@@@ 
 Vicente
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float area(float,float,float);
float semiP(float,float,float);
void hora();
void principal();
void calcTri();

int main() {
	principal();
	return 0;
}
/*
Funcion que calcula el semiperimetro del triangulo 
semiperímetro p=(a+b+c)/2 siendo a,b y c los tres lados del triángulo
*/
float semiP(float a, float b, float c){
	float p; 
	p = (a+b+c)/2;
	return p;
}
/*
Funcion que calcula el area del triangulo
con la formula Área= (p(p-a)(p-b)(p-c))^(1/2)
*/
float area(float a, float b, float c){
	float area;
	float perimetro = semiP(a,b,c);
	area = sqrt(perimetro * (perimetro - a) * (perimetro - b) * (perimetro - c));
	return area;
}

void hora(){
	int hrs,min,newh;
	printf("Ingresa la hora con el fomato HH:MM \n");
	scanf("%d:%d", &hrs, &min);

	if(hrs>24 || min>60 || hrs<0 || min<0){
		printf("Valores incorrectos");
	}else{
		if (hrs < 12) {
			printf("La hora %d:%d es igual a la hora %d:%d AM", hrs,min,hrs,min);
		}else{
			newh = hrs - 12;
			if(min<10){
				printf("La hora %d:%d es igual a la hora %d:0%d PM", hrs,min,newh,min);
			}else{
				printf("La hora %d:%d es igual a la hora %d:%d PM", hrs,min,newh,min);
			}
		}
	}
}

void calcTri(){
	float a,b,c,res;
	printf("Ingrese los lados del triangulo(separados por comas): \n");
	scanf("%f,%f,%f",&a,&b,&c);
	res = area(a,b,c);
	printf("El area del triangulo de lados (%f,%f,%f) es: \n%f",a,b,c,res);
}

void principal(){
	int i;
	printf("\n--------------------------------------------------------------\n");
	printf("Este programa calcula el area de un triangulo\n");
	printf("tambien convierte la hora de formato 24 horas a 12 horas\n");
	printf("Elija la opcion deseada: \n1.-Area de un triangulo.\n2.-Conversion de formato horario.\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			calcTri();
		break;
		case 2:
			hora();
		break;
		default:
			printf("Opcion no existente.");
	}
}