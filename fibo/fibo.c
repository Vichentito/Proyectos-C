#include <stdio.h>

int fibo(int n);

int main()
{
    int n, f;
    while (1)
    {
        printf("fibo de: \n");
        scanf("%d", &n);
        f = fibo(n);
        printf("El fibbonacci de %d es: %d \n", n, f);
    }
}

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}