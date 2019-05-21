#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int mcd(int a, int b);
void principal();
void calcularmcd();
int calcularNP(int a);
void imprimirNP();

int main() {
	principal();
	system("pause");
	return 0;
}
int mcd(int a, int b){
	if (a % b == 0){
		return b;	
	}else {
		return mcd(b,(a%b));
	}
}


int calcularNP(int a){
	int suma = 0;
	int i=1;
	for(i; i<a; i++){
		if(a % i == 0){
			suma += i;
		}
	}
	if(suma == a){
		return 1;
	}else{
		return 0;
	}
}

void calcularmcd(){
	int a,b,res;
	printf("ingresa los dos numeros separados por comas\n");
	scanf("%d,%d",&a,&b);
	if(a<b){
		res = mcd(b,a);
	}else{
		res= mcd(a,b);
	}
	printf("El MCD de %d, %d es: %d",a,b,res);
}

void imprimirNP(){
	int n,max=0;
	int i=1;
	int res;
	printf("Ingrese el numero de numeros perfectos que desea calcular\n");
	scanf("%d",&n);
	printf("Los primeros %d numeros perfectos son:\n",n);
	while(max!=n){
		res = calcularNP(i);
		if(res == 1){
			printf("El %d es perfecto\n",i);
			max++;
		}
		i++;
	}
}

void principal(){
	int i;
	printf("Elige la opcion deseada: \n");
	printf("1.-MCD de dos numeros\n2.-Los primeros n numeros perfectos.\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			calcularmcd();
			break;
		case 2:
			imprimirNP();
			break;
		default:
			printf("Opcion no existente");
	}
	
}

