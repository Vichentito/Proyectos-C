#include <stdio.h>
#include <stdlib.h>

int primo(int,int);

int main() {
    printf("%d", primo(6,2));
	return 0;
}

int primo(int n, int p){
    if(p == n){
        return 1;
    }else if(n%p == 0){
        return 0;
    }else{
        return primo(n,p+1);
    }
}