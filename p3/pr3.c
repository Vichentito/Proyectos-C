#include <stdio.h>
#include <ctype.h>


int main(){
    int i = 0,j;
    while(i*i<10){
        j=i;
        while(j*j<100){
            printf("%d \n",i+j);
            j+=2;
        }
        i++;
    }
    printf("\n*****\n");
    
    return 0;
}


