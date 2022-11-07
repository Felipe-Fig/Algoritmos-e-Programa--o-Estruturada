	
1)

Uma lista ligada ou lista encadeada é uma forma de estruturar dados para o seu armazenamento, ou seja, é determinar a forma de inseri-los ou remove-los, sendo necessário organizá-los em células e inserir um ponteiro que aponte para o primeiro elemento e outro que aponte para o seu fim.

 

Assim, toda vez que queremos manipular uma estrutura de dados em uma memória, ou em uma unidade de armazenamento qualquer, podemos fazer isso de ao menos três formas diferentes conforme a seguir:

a) reservar os espaços em memória na forma estática, ou seja, alocar uma determinada quantidade de memória previamente definida, mesmo sem considerar a quantidade que seria realmente necessária;

b) reservar os espaços em memória através de variáveis locais. O espaço estará disponível somente enquanto a função que o declarou estiver executando o programa.

c) alocação de espaço em memória dinamicamente, ou seja, o Sistema Operacional aloca blocos de espaços que estão disponíveis (livres) ou para atender uma determinada demanda. 

 

Com base nas informações disponíveis e em Listas Encadeadas (ou Listas Ligadas), avalie a seguinte afirmativa preenchendo suas lacunas:

 

"Os elementos armazenados numa lista não ocupam um espaço de memória ___________, fazendo com que o acesso aos elementos da lista seja ___________. Enquanto que a utilização de vetores é considerada primária para a representação de conjuntos de dados, a utilização de listas ligadas é uma maneira mais ______________, para a organização e disponibilização dos dados, isto porque em listas ligadas, cada um de seus elementos___________________."

Agora assinale a alternativa que preenche corretamente as lacunas do texto.

Alternativas:

    a)

     distribuído / aleatório / flexível / indica o máximo de elementos.
    b) contíguo / sequencial / flexível / indica qual é o seu próximo.
    c)

     aleatório / contíguo / simplória / indica o mínimo de elementos.
    d)

     contíguo / aleatório / íntegra / indica qual é o seu próximo.
    e)

     distribuído / sequencial / limitada / indica o máximo de elementos.

**Gabarito: b) contíguo / sequencial / flexível / indica qual é o seu próximo.**

---

2)

O uso do vetor, ao ser declarado, reserva um espaço na memória contíguo para armazenar seus elementos e assim é possível acessar qualquer dos seus elementos a partir do primeiro elemento, por meio de um ponteiro (CELES, 2004).

Com base no funcionamento das Estruturas de Dados, avalie as seguintes asserções e a relação proposta entre elas:

I – Além do primeiro elemento é necessário que se conheça o último elemento, que é o que controla o acesso do vetor.

PORQUE

II – Vetores permitem que os elementos sejam acessados de forma aleatória.

Assinale a alternativa correta.

Alternativas:

    a) As asserções I e II são verdadeiras, mas a II não é uma justificativa da I.
    b) As asserções I e II são verdadeiras e a II é uma justificativa da I.
    c) A asserção I é verdadeira e II é falsa.
    d) A asserção I é falsa e II é verdadeira.
    e) As asserções I e II são falsas.

**Gabarito: e) As asserções I e II são falsas.**

>Discordo do gabarito pois (em tese) eu consigo acessar um elemento qualquer do vetor que eu queira. Não encontrei explicação.

---

3)

Existem ótimos exemplos de utilização de Pilhas em nosso cotidiano, nos brinquedos usados em sala de aula ou até mesmo numa simples pilha de livros, onde é possível se determinar qual o algoritmo (critério) utilizado para empilhá-los: tamanho, grossura, cor, tema, etc.. Muitos professores usam estas artimanhas a fim de que os alunos possam desenvolver o raciocínio lógico.

Pensando nisso, um programador desenvolveu o código abaixo, para que os professores possam informar a quantidade de discos e o sistema informasse a quantidade total de movimentos que serão realizados. Com esse algoritmo, eles poderiam criar gincanas e desafios entre os alunos para resolverem a ferramenta lógica que eles usam em sala de aula, com um número maior de discos.

Abaixo apresenta-se o código desenvolvido pelo programador mencionado.
```C
#include <stdio.h>
#include <stdlib.h>
int contador = 0;
void algoritmo(int n, char a, char b, char c)

{
  if (n == 1)

   {
     printf("Move o disco %d de %c para %c\n", n, a, b);
     contador++;
   } else

      {
        algoritmo(n - 1, a, c, b);
         printf("Move o disco %d de %c para %c\n", n, a, b);
        algoritmo(n - 1, c, b, a);
        contador++;
      }
}


int main(void)
{
   int numDiscos;
   printf("Informe o numero de discos: ");
   scanf("%d", &numDiscos);
  algoritmo(numDiscos, 'A', 'B', 'C');
   printf("\n\nA quantidade de movimentos foi: %d", contador);
   return 0;
}
```
Sobre o algoritmo apresentado acima, analise as seguintes afirmações:

I - O Algoritmo trata-se da solução da Torre de Hanói.

II - Para o desenvolvimento deste algoritmo foi necessário o uso da recursividade assim como o uso de Pilhas.

III - Foi necessário, um contador para realizar a contagem da quantidade de movimento.

IV - O algoritmo limita o numero de pilhas informadas em 10 unidades.

Agora, assinale a alternativa correta.

Alternativas:

    a) Apenas as afirmativas I, III e IV estão corretas.
    b) Apenas as alternativas I, II e III são corretas.
    c) Apenas as afirmativas I e III estão corretas.
    d) Apenas as afirmativas I, II e IV estão corretas.
    e) Apenas as afirmativas II, III e IV estão corretas.

**Gabarito: b) Apenas as alternativas I, II e III são corretas.**

---

4)

As Filas não apresentam uma solução completa, sendo que, mesmo chegando ao final do vetor poderemos ter a Fila cheia mesmo não estando cheia, uma vez que elementos podem ter sido removidos e para isso, podemos utilizar as Filas Circulares como solução para esta situação.

Tendo como referência Filas Circulares, avalie as seguintes afirmativas:

I - Uma Fila Circular utiliza menos instruções a serem executadas, podendo ser mais adequada e eficiente na utilização de programação.

II -  Em relação ao driver-thru (serviço de vendas alimentos fast food, que permite ao cliente comprar o produto sem sair do carro), seu processo todo se encaixa no modelo de Fila Circular.

III -  Em uma Fila Circular, o conceito de circularidade se baseia quando o último elemento da fila está na última posição do vetor, e é adjacente à primeira

IV -  Em uma Fila Circular são os ponteiros, e não os elementos da fila que se movem em direção ao início do vetor.

Agora assinale a alternativa correta.

Alternativas:

    a) Apenas a afirmativa IV está correta.
    b) Apenas as afirmativas II e III estão corretas.
    c) Apenas as afirmativas I e II estão corretas.
    d) Apenas as afirmativas I, III e IV estão corretas.
    e) As afirmativas I, II, III e IV estão corretas.

**Gabarito: b) Apenas as afirmativas II e III estão corretas.**

>Eu marcaria: e) As afirmativas I, II, III e IV estão corretas.
>A alternativa I se encontra da mesma forma como aqui na questão na página 235 do meu material, logo abaixo do tópico *filas circulares*. A IV idem, constando na página 236 logo acima da figura 4.34.
---