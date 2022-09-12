// programa que calcula todos os números da seq de Collatz
#include <stdio.h>

int main()
{
    //declaração da variável n que será analisada
    int n, i;
    //input do usuário
    printf("Digite um número qualquer, que seja positivo e maior que 1\n");
    scanf("%i", &n);
    //loop
    i = 0;
    while (n>1)
    {
    // condicional
        if (n%2 == 0)
        {
            n = n/2;
        }
        else
        {
            n = (n*3) + 1;
        }
        i++;
        printf("%i\n", n);
    }
}