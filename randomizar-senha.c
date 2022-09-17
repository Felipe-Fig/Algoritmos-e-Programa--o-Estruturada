#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int contar();
int randomizar();

int contar()
{
    char frase[50] = "";
    printf("Digite uma frase ou palavra qualquer:");
    scanf("%s",frase);
    int i = 0;
    int counter1 = 0;
    int x;
    x = strlen(frase);
    for (i=0; i < x; i++)
    {
        if (frase[i] == 'a' || frase[i] == 'e')
        {
            counter1++;
        }
    }
    return counter1;
}

int randomizar(int c)
{
    int senha1;
    srand(c);
    senha1 = rand();
    return senha1;
}

int main()
{
    int senha;
    int counter;
    counter = contar();
    senha = randomizar(counter);
    printf("Sua senha será: %i", senha);
}
