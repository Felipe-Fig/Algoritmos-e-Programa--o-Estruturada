//Algo para calcular média
//Quantos inputs o usuário quiser

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main ()
{
    // variáveis
    float nota;
    float soma;
    float media;
    int quantidade_notas;
    int x;

    quantidade_notas = 0;
    soma = 0;
    // do-while loop
    do
    {
        printf("Cálculo de média!\n");
        printf("Digite 1 para inserir uma nota ou 2 para sair do programa\n");
        scanf("%i", &x);
        
        switch (x)
        {
            case 1:
                printf("Digite sua nota:\n");
                scanf("%f", &nota);
                quantidade_notas++;
                soma = soma + nota;
                media = soma/quantidade_notas;
                printf("Sua média até o momento é de %.2f\n", media);
                break;
            case 2:
                printf("Obrigado!\n");
        }
    
    } while (x == 1);
        return 0;
}