# AAP 01 - Algoritmos e Programação Estruturada
## Engenharia de Software
### UNOPAR

1) Pseudocódigos é considerado uma ferramenta que pode auxiliar a programação, ela pode ser escrita em palavras similares ao inglês ou português para facilitar a interpretação e desenvolvimento de um programa. Neste contexto, analise o seguinte algoritmo escrito em pseudocódigo.

```
var
real: v1, v2, v3, v4, N1, x;
Início
escreva (“Digite Nota 1:”);
leia v1;
escreva (“Digite Nota 2:”);
leia v2;
escreva (“Digite Nota 3:”);
leia v3;
escreva (“Digite Nota 4:”);
leia v4;
N1 = v1 + v2 + v3 + v4;
x = N1 / 4;
escreva(“Resultado = ”, x);
Fim.
```
Agora, assinale a alternativa correta.

**Gabarito: Este algoritmo armazena as notas em variáveis para depois realizar um calculo onde o restado final é armazenado em X e por fim é exibido.**

---

2) A lógica de programação pode ser definida como uma técnica de encadear pensamentos para atingir determinado objetivo. Ela faz-se necessária para desenvolver programas e sistemas, pois permite definir a sequência lógica para a solução de um problema.

```
var
   real: x, y, z;                       (1)
Início                                  (2)
   escreva (“Digite um Numero:”);
   leia x;                              (3)
   escreva (“Digite outro Numero:”);
   leia y;
   z = x + z + 1;                       (4)
   escreva(“Resultado = ”, z);
Fim.                                    (5)
```

Considerando o algoritmo apresentado, julgue as afirmações que seguem e marque (V) para verdadeiro ou (F) para falso.
(   ) A parte 1 do pseudocódigo indica a declaração das variáveis que são compatíveis com qualquer tipo de dados.
(   ) A parte 3 do pseudocódigo corresponde a entrada de dados do algoritmo.
(   ) A parte 4 do pseudocódigo corresponde tanto à parte de processamento quanto a parte de saída de dados do algoritmo..

Agora, assinale a alternativa que contém sequência correta.

**Gabarito: F-V-V**

---

3) Variáveis com estruturas compostas do tipo vetor ou matriz, só são capazes de  armazenar valores de um mesmo tipo, porem, além das estruturas homogêneas as linguagens de programação oferecem um tipo de variável composta heterogênea chamada de estruturas (structs) ou ainda de registros.

Na linguagem C, a criação de uma estrutura deve ser feita antes da função main() e deve possuir a seguinte sintaxe:

**Gabarito: struct <nome>{ <tipo> <nome_da_variavel1>; <tipo> <nome_da_variavel2>; ... };**

---

4) Conforme Deitel e Deitel (2011) podemos utilizar a estrutura de um vetor para armazenar variáveis do mesmo tipo de dado. Um vetor é uma estrutura de dados homogênea e que deve ser declarado com a quantidade de elementos que a estrutura deverá armazenar.

Fonte: DEITEL, Paul; DEITEL, Harvey. C Como Programar. 6. ed. São Paulo: Pearson, 2011.

Observe o programa a seguir que faz a leitura de três notas utilizando um vetor.

```C
#include <stdio.h>
int main ()
{
float nota[3],media=0;
printf("Digite a Primeira Nota");
scanf("%f",&nota[0]);
printf("Digite a Segunda Nota");
scanf("%f",&nota[1])
printf("Digite a Terceira Nota");
scanf("%f",&nota[2]);
// cálculo da média                 //linha 11
// impressão da média das notas     //linha 12
return 0;
}
```

Considerando  o programa apresentado, julgue as afirmativas a seguir  e marque  (V) para Verdadeiras ou (F) para  Falsas:
(  ) Na linha 11, para calcular a média devemos inserir o seguinte código:    media = (nota[0] + nota[1] + nota[2]) / 3;
(  ) Na linha 11, para calcular a média devemos inserir o seguinte código:    media = (nota[0] + nota[1] + nota[2] / 3);
(  ) Na linha 12, para imprimir a média devemos inserir o seguinte código:   printf ("A media das notas informadas  %.d\n", medias);
(  ) Na linha 12, para imprimir a média devemos inserir o seguinte código:  printf ("A media das notas informadas  %.2f\n", media);

Assinale a alternativa que apresenta a sequência correta.

**Gabarito: V-F-F-V**