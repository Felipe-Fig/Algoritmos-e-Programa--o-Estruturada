#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main ()
{
    int matriz[31][31];
    int i, j;
    int ordem = 0, quadrado_da_ordem = 0, linha = 0, coluna = 0, soma = 0;

    printf ("Qual será a ordem do Quadrado Mágico? Precisa ser Impar!\n");
    scanf ("%d", &ordem);

    //Verificação se ordem C) ímpar e > 0.
    if (ordem % 2 == 0 || ordem <= 0)
    {
      printf ("Precisávamos de um número positivo e ímpar!\n");
      return 0;
    }

    quadrado_da_ordem = ordem * ordem;
    printf ("Quantidade de números no Quadrado Mágico: %d\n",quadrado_da_ordem);

    //calculando a posição inicial (para o nº: 1)
    //Quando a ordem é diferente de 1, será sempre na penúltima coluna e na última linha
    if (ordem == 1)
    {
      linha = 0;
      coluna = 0;
    }
    else
    {
       linha = ((ordem+1)/2) -1;
       coluna = ordem - 1;
    }
    //loop de loop para zerar a matriz
    for (i=0; i<ordem; i++)
    {
        for (j=0; j<ordem; j++)
        {
            matriz[i][j] = 0;
        }
    }
    //Preenchendo a matriz com os valores do quadrado Mágico
    for (i = 1; i <= quadrado_da_ordem; i++)
    {
        matriz[linha][coluna] = i;
        // seguir em frente nas colunas ou retornar à 0 caso esteja na última
        if (coluna == ordem - 1)
        {
            coluna = 0;
        }
        else
        {
            coluna++;
        }
        // andar linha pra trás ou voltar da primeira para a última
        if (linha == 0)
        {
            linha = ordem - 1;
        }
        else
        {
            linha--;
        }
    
        /* Se a próxima posição já está ocupada
        e é diferente de 0, devemos ocupar a posição
        do lado esquerdo da última posição preenchida.
        Caso contrário devemos preencher a posição acima
        e à direita da última posição preenchida. */
        if (matriz[linha][coluna] != 0)
        {
            if (coluna == 0)
            {
                coluna = ordem - 2;
            }
            else
            {
                coluna = coluna - 2;
            }
            if (linha == ordem - 1)
            {
                linha = 0;
            }
            else
            {
                linha++;
            }
        }
    }
    printf("\nO quadrado mágico de %d X %d é:\n", ordem, ordem);
    // Loop para imprimir matriz
    for (i=0; i < ordem; i++)
    {
        for (j=0; j<ordem; j++)
        {
            printf("%03d ", matriz[i][j]);
        }
        printf("\n");
    }
    /* Loop para calcular a soma de linhas, colunas
    e da diagonal principal do quadrado mágico*/
    for(i=0; i<ordem; i++)
    {
        soma = soma + matriz[i][i];
    }
    printf("A soma de cada linha, de cada coluna ou da diagona principal é: %d", soma);
    return 0;
}