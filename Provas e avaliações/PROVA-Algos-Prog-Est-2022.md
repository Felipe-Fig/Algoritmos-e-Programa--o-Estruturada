# Ainda não corrigida. Apenas 12/16 acertos.

### **Questão 1**

Vetores são variáveis compostas unidimensionais, sendo assim, poem armazenar diversos valores ao
mesmo tempo. Funções podem receber como parâmetro um vetor de qualquer tipo, portanto é possível
utilizar tal estrutura de dados juntamente com funções recursivas.
Considerando o programa abaixo que utiliza um vetor em uma função recursiva, escolha a opção que
representa o que será impresso a linha 18.

```C
int funcao(int x[], int n)
{
    int resultado = 0;
    if(n >= 0)
    {
        resultado = funcao(x,n-1);
        if(x[n] == 100) 
        {
            return resultado;
        }
        else 
        {
            return resultado = resultado + x[n];
        }
    }
    else return resultado;
}

void main()
{
    int numeros[5], resultado = 0;
    numeros[0] = 10;
    numeros[1] = 30;
    numeros[2] = 100;
    numeros[3] = 5;
    numeros[4] = 50;
    resultado = funcao(numeros,5);
    printf("\n Resultado = %d",resultado);
}
```

**Gabarito: Resultado = 95**

>Primeiramente, eu rodei esse mesmo código no compilador e o resultado apresentado foi **32861**. Vou deixar o [link](https://onlinegdb.com/M5Skm9_tF) para conferência.

>Ele quer o resultado da chamada `funcao(numeros,5)`. Portanto teremos como `x=numeros` e `n=5`. A leitura da explicação de baixo pra cima pode auxiliar o entendimento.

>Na primeira iteração: `n = 5` é >= a 0 portanto `resultado = funcao(x, n-1)`. Nesse momento ele já vai direto pra segunda iteração e nem faz o segundo `if`. O retorno da segunda iteração foi 95. 
>Na segunda iteração: `n = 4` é >= a 0, portanto segue para a próxima iteração. O retorno da terceira iteração foi `resultado = 45`. Como não atende ao segundo `if` o retorno final será 45 + 50, portanto `resultado = 95`.
>Na terceira iteração: `n= 3` é >= a 0, portanto seguimos para a próxima iteração. O retorno da quarta iteração foi `resultado = 40`. Mas como não atende ao segundo `if` o retorno final será `resultado = 40 + 5 = 45`.
>Na quarta iteração: `n = 2` e segue pra próxima iteração. O retorno da quinta iteração foi `resultado = 40` e nesse caso `x[2] = 100` portanto retorna para a iteração anterios apenas `resultado = 40`.
>Na quinta iteração `n = 1` e segue para a próxima iteração. O retorno da sexta iteração foi `10`, seguimos para o segundo `if`. `x[1] == 100 é falso` portanto retornamos o resultado (10) + x[1] = 30, ou seja `resultado = 40`.
>Na sexta iteração: `n = 0` e segue para a próxima iteração. O retorno da sétima iteração é `0`, portanto seguimos com o segundo `if`. Neste caso `x[n] = 10`, não atendendo ao parâmetro do segundo `if`, por isso o retorno será o `else` `0 + 10`.
>Na sétima iteração: `n = -1` e não atende à condição do primeiro `if` e portanto retorna `resultado = 0`

---

### **Questão 2**

Os elementos inseridos em uma pilha possuem uma sequência de inserção, sendo que o primeiro elemento
que entra na pilha só pode ser removido por último, após todos os outros elementos serem removidos.
Assim, os elementos da pilha só podem ser retirados na ordem inversa da ordem em quem foram
inseridos.
O método de funcionamento de uma pilha, no qual só poem ser retirados os elementos na ordem inversa
da ordem em que foram inseridos, também é conhecido como:

**Gabarito: FILO**

>First in last out

---

### **Questão 3**

Sobre as estruturas de dados, analise as asserções a seguir.

I- Um vetor não é uma estrutura flexível de dados, em razão do tamanho máximo que precisa ser definido.

Portanto

II- Para solucionar esse tipo de problema, é necessário utilizar uma estrutura de dados que possua tipo de armazenamento dinâmico de dados, um bom exemplo disso são as listas ligadas.

Analisando-se as asserções apresentadas, conclui-se que:

**Gabarito: Ambas são verdadeiras e a II justifica a I**

---

### **Questão 4**

Vetores são estruturas de dados estáticas, ou seja, não são redimensionadas em tempo de execução. Uma vez criadas com tamanho N, esse tamanho se mantém fixo. Para criar uma função que retorna um vetor é preciso recorrer ao uso de ponteiros.

Avalie o código a seguir e escolha a opção correta.
```C 
#include <stdio.h>

int* retornarVetor()
{
    static int v[10];
    int a;
    for (a = O; a < 10; ++a)
    {
        v[a] = 2*a;
    }
    return v;
}

int main()
{
    int *p;
    p = retornarVetor();
    printf("Valor = %d", *(p + 2));
    return 0;
}
```

**Gabarito: Valor =4**

---

### **Questão 5**

Analise o código do programa a seguir que utiliza uma função para calcular a soma entre dois números.
```C
#include<stdio.h>
int somar () {
return 2 + 3;
int main) {
int
resultado = 0;
A
resultado
= somar () ;
printf ("O resultado da funcao e
=
d", resultado);
return 0;
}
```

Agora, analise as afirmativas sobre o código apresentado;
I- A função irá retornar um valor inteiro (int).
II- O valor que será apresentado decorrente da linha 8 será: 0;
III- A função somar está errada, pois toda função necessita de parâmetros.

Agora, assinale a alternativa que apresenta a resposta CORRETA:

**Gabarito: Apenas a afirmativa I está correta.**

---

### **Questão 6**

Sobre as funções recursivas, analise as afirmativas a seguir:

I - A função recursiva chama a si própria até que um ponto de parada seja estabelecido;

II- As variáveis criadas em cada instância da função na memória são independentes, ou seja, mesmo as variáveis tendo nomes iguais, cada uma tem seu próprio endereço de memória e a alteração do valor em uma não afetara na outra.

III- A sintaxe para implementação de uma função recursiva, nada difere das funções gerais, ou seja, deverá ter um tipo de retorno, o nome da função, os parênteses e os parâmetros quando necessário.

Agora, assinale a alternativa que apresenta a resposta CORRETA:

**Gabarito: As afirmativas I, II e III estão corretas.**

---

### **Questão 7**

Dado um certo problema para ser resolvido por meio de um programa, a solução pode ser implementada em blocos de funcionalidades, técnica essa conhecida como dividir para conquistar, A aplicação dessa técnica em uma linguagem de programação pode ser feita por meio de funções.

A respeito de funções, análise as afirmações a seguir:

I. Função tem como objetivo resolver parte de um problema maior. Um função sempre deve retornar um
valor para quem a chamou.

II. Uma função sempre precisa receber parâmetros, caso isso não ocorra, o compilador irá relatar um erro.

III. Uma função pode ser invocada quantas vezes for necessário em um programa.

Escolha a alternativa que representa a resposta correta.

**Gabarito: Apenas a III está correta.**

---

### **Questão 8**

As variáveis são locais reservados na memória para armazenamento dos dados, cada uma possui um nome próprio para sua identificação. Existe um tipo variável para cada representação da informação, não podendo assim, um determinado tipo de variável, ser usada em situações controversas.

De acordo com o texto acima, responda a alternativa correta:

**Gabarito: Variável do tipo inteiro armazena os números inteiros (negativos ou positivos) e as variáveis do tipo real permite armazenar somente valores de pontos flutuantes.**

---

### **Questão 9**

Analise as afirmativas a seguir e marque V para verdadeiro e F para falso:

() Uma matriz aceita diversos tipos de variáveis;

() Não é obrigatório que todas as posições sejam ocupadas de um vetor ou de uma matriz.

() O `for` busca repetir uma informação por um número fixo de vezes.

Agora, assinale a alternativa que apresenta a sequência CORRETA:

**Gabarito: F-V-F**

>Apesar disso, encontrei na internet como resposta **F-V-V**, gabarito do qual eu discordo pois o `for` não repete por um número fixo de vezes e sim enquanto uma condição não é satisfeita. São coisas diferentes.

---

### **Questão 10**

Segundo a programação com teste no início, Soffner (2013, p. 64) coloca que um programa "não executará
nenhuma repetição (e as ações que ali dentro estiverem programadas) sem antes testar uma condição".
Para realizar a repetição com teste no início, você usará o comando iterativo "while", que significa em
portuguès"enquanto".
Levando em consideração que precisamos estat atentos para que não ocorra um loop infinito, analise as
afirmações abaixo e responda a alternativa correta:
I. Contador - é utilizada para controlar as repetições, quando esta é determinada.
'Il. Incremento e decremento - trabalha o número do contador, somente quando for positivo.
Ill. Acumulador - irá somar as entradas de dados de cada iteração da repetição, gerando um somatório a
/ser utilizado quando da saída da repetição.
IV. Condição de parada - utilizada para determinar o momento de parar quando não se tem um valor exato
desta repetição.

**Gabarito: I, III e IV estão corretas**

>II está errada pois o material não especifica se o incremento não pode ser negativo, ele pode ser. O gabarto do link abaixo está divergente até do material fornecido, o qual está de acordo com o gabarito que eu coloquei acima.

>Gabarito [divergente](https://brainly.com.br/tarefa/19018175)

---

### **Questão 11**

Sobre a recursão, analise as asserções a seguir:
I- Um algoritmo recursivo resolve um problema dividindo-o em subproblemas mais simples, cujo a solução
é a aplicação dele mesmo.
Por essa razão,
II- o algoritmo recursivo não possui uma versão iterativa.

Analisando-se as asserções apresentadas, conclui-se que:

**Gabarito: A I é verdadeira e a II é falsa.**

---

### **Questão 12**

O comando while executa a rotina de um programa enquanto uma sintaxe do programa for correta. Neste
caso, podemos afirmar que:
1 - O programa não executará nenhuma repetição (e as ações que ali dentro estiverem programadas) sem
antes testar uma condição,
Il - Em alguns casos, quando utilizamos teste no início, pode ocorrer o famoso loop infinito.
Ill - Geralmente usamos o comando while quando não sabemos quantas vezes o laço da condição deve ser
repetido.
Assinale a alternativa correta de acordo com as afirmações acima:

**Gabarito: As três estão corretas.**

---

### **Questão 13**

Quando você precisar adicionar um "1" à variável, você fará uso do "+*" (incremento), e quando quiser
tirar um "I" da variável, você utiliza "- -" (decremento), essas operações são caracterizadas unárias, porém,
o posicionamento dos "++" nas variáveis poem sofrer alterações nos seus valores quando representados.
Analise o programa abaixo e responda a alternativa que corresponde ao valor para p e q.
int main() d
int p.q;
p-1; q-1;
printf("Valor de p = %din"
, p);
printf("Valor de q = %d \n", q);
printf("In Criando o Incremento: p+ *\n"):
p++:
printf("Criando um Decremento: q--In");
a--
printf(' In O novo valor para p = %din", p);
printf(* O novo valor para q - %d\n",q);
return O;
}

**Gabarito: O novo valor para `p` é 2 e para `q` é 0.**

---

### **Questão 14**

Vetor é uma das estruturas que existe para o armazenamento de dados, Sua utilização é vasta devido à
facilidade em ler e escrever dados e à velocidade com que as operações são realizadas, pois cada valor no
vetor é armazenado sequencialmente a memória.
Considere as afirmações sobre os vetores e escolha a opção correta.
1 - O vetor é uma estrutura de dados dinâmica, ou seja, seu tamanho pode ser redimensionado em tempo
de execução.
I| - Como o vetor é uma estrutura unidimensional, para acessar seus dados é preciso somente um índice.
Ill - Uma das características dos vetores é que eles poem armazenar dados de qualquer tipo.

**Gabarito: Somente II e III estão corretas.**

---

### **Questão 15**

A linguagem C de programação utiliza especificadores de formato para identificar o tipo de valor guardado
nas variáveis e constantes. Eles devem ser usados tanto para leitura de um valor, como para a impressão.
Quando um programa é executado, o compilador usa esses elementos para fazer as devidas referências e
conexões, por isso o uso correto é fundamental para os resultados.
Considerando o código apresentado, analise as asserções e escolha a opção correta.
```C 
#include<stdio.h>
void main()
{
    int idade = 0;
    float salario = 0;
    char a_letra = 'a';
    char A_letra = 'A';
}
```
Anexo - Consulte a imagem em melhor resolução no final do cadernos de questões.
I- O comando `scanf("%f", idade);` guardará o valor digitado na variável idade.
AIl - O comando `printf("%d", a_letra); imprimirá a letra 'a' na tela.
Ill- O comando `printf("%c" A_letra);` imprimirá a letra 'A' na tela.

**Gabarito: Somente a III está correta.**

---

### **Questão 16**

A recursividade é uma técnica de programação na qual uma função chama a si própria tornando o código mais impo e elegante, o que facilita a manutenção e reutilização de trechos de códigos e funções. Toda chamada recursiva deve retornar um valor à função que "fez o chamado". Analise as asserções a seguir e a relação proposta entre elas.

I - Funções recursivas sempre poem ser utilizadas para substituir estruturas de repetição.

PORQUE

II - Toda função recursiva é composta pelo caso base e pelas chamadas recursivas funcionando como um laço de repetição.

**Gabarito: Ambas são verdadeiras mas a II não justifica a I.**

>
---