#include<stdio.h>
float capital;
int tempo;
char modalidade;
float juros; 

float rendimentos(float capital, int tempo)
{
    if (modalidade =='a' || modalidade =='A')
    {
        juros = capital*tempo*0.02;
    }
    else
    {
        juros = capital*tempo*0.008;
    }
    return juros;
}

int main()
{
    printf("Em qual modalidade irá investir? A = 2%% ou B = 0,8%%");
    scanf("%c", &modalidade);
    //armazena valor, usei float pq user pode colocar número quebrado
    printf("Qual valor será investido? \n");
    scanf("%f", &capital);
    //tempo tem que ser inteiro
    printf("Por quanto tempo (anos) será investido esse valor?\n");
    scanf("%d", &tempo);
    //colocando resultado numa variável local
    float lucro;
    lucro = rendimentos(capital, tempo);
    float montante = capital + lucro;
    //print final
    printf("Portanto seu lucro será de: %.2f", lucro);
    printf("O montante final será %.2f por ter investido %.2lf por %i ano(s)", montante, capital, tempo);
}