#include<stdio.h>
#include<stdlib.h>

float calcular_peso();

float calcular_peso()
{
    float altura;
    float base;
    float comprimento;
    float peso1;
    float volume;
    printf("Digite o valor da base:");
    scanf("%f", &base);
    
    printf("Digite o valor da altura:");
    scanf("%f", &altura);
    
    printf("Digite o valor do comprimento:");
    scanf("%f", &comprimento);
    
    volume = base*altura*comprimento;
    peso1 = volume*25;
    
    return peso1;
}

int main()
{
    float peso;
    peso = calcular_peso();
    if (peso <= 500)
    {
        printf("Deverá ser usado o guindaste G1 pois o peso é de %.2f", peso);
    }
    else if (peso <= 1500)
    {
        printf("Deverá ser usado o guindaste G3 pois o peso é de %.2f", peso);
    }
    else
    {
        printf("Deverá ser usado o guindaste G2 pois o peso é de %.2f", peso);
    }
}