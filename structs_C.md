# Structs em C, teoria e códigos.
## Unidade 4 Seção 1 - Algoritmos e Programação Estruturada
---
## Listas ligadas e operações

1. [Adição de elementos à lista](#adição-de-elementos-à-lista)
2. [Adição de elementos no **início** da lista](#adição-de-elementos-no-início-da-lista)
3. [Adição de elementos no **meio** da lista](#adição-de-elementos-no-meio-da-lista)
4. [Adição de elementos no **fim** da lista](#adição-de-elementos-no-fim-da-lista)
5. [Remover elementos da lista](#remover-elementos-da-lista)
6. [Percorrer a lista ligada](#percorrer-a-lista-ligada)
1. [Uso do Typedef](#uso-do-typedef)
---
### Adição de elementos à lista

>Exemplificando a seguir, nossa lista é criada sem valor algum, ou seja, ela é criada vazia. Segundo Celes, Cerqueira e Rangel (2004), **para inserirmos um elemento na lista ligada é necessário alocarmos o espaço na memória**, de forma dinâmica, para armazenar o elemento e ligá-lo à lista existente.

>Podemos inserir um elemento em uma lista em três situações diferentes. Ao inserirmos uma informação na lista ligada, é imprescindível que seja **atualizado o valor do ponteiro desta lista**, assim, a lista ligada deve apontar ao novo elemento da lista, segundo Celes, Cerqueira e Rangel (2004).

Esse código abaixo não faz nada. Ele apenas printa um `newline`. O importante é avaliar as estruturas antes de `main()` que se referem à criação da `struct lista` e da criação da função `Lista()`, a qual é responsável por inserir itens na struct.

```C
#include <stdio.h>
#include <stdlib.h>

struct lista 
{
    int info;
    struct lista*prox;
};
typedef struct lista Lista;

Lista*inserir(Lista*l, int i) 
{
    Lista*novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

int main()
{
    printf("\n");    
}
```
Olhando especificamente para a função:
```C
Lista*inserir(Lista*l, int i) 
{
    Lista*novo = (Lista*)malloc(sizeof(Lista));
    //Lista*novo = malloc(sizeof(Lista)); também compila.
    novo->info = i;
    //novo.info = i;
    novo->prox = l;
    //novo.prox = l;
    return novo;
}
```
### Adição de elementos no início da lista

Vemos o seguinte... Temos uma função de nome `Lista*inserir()` e ela recebe duas variáveis. Uma variável de nome *l* e que é do tipo `Lista*` e outra variável *i* que é um inteiro.

Pra *struct* `Lista` é criado um objeto chamado `novo` e para ele foi alocado o espaço na memória (usando `malloc`) do tamanho da própria *struct*.

Para esse objeto chamado `novo` eu atribuí os valores de *i* para a variável `info` e *l* para a variável `prox`. Esse "prox" é uma referência para o próximo objeto contido na lista. 

Portanto, se o próximo objeto é sempre a lista que existia antes, a adição do novo objeto é feita antes dessa lista, no primeiro item, de forma que a lista antiga fique mais pra frente ao ser procurada ou acessada.

### Adição de elementos no meio da lista

Segue a função a ser usada quando for adicionar um número inteiro *v* no meio da lista, posição *pos*:
```C
Lista* inserirPosicao(Lista* l, int pos, int v)
{
    int cont = 1;
    Lista *p = l;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    while (cont != pos)
    //vai aumentando *cont* até ele chegar no valor de *pos* ou seja, a posição que queremos inserir o item. 
    {
        p = p -> prox;
        //p é o ponteiro que remete à lista. Portanto p.prox será o caminho para o próximo valor conforme a struct inicial.
        cont++;
    }
    novo -> info = v;
    //novo.info = v;
    novo -> prox = p -> prox;
    //novo.prox = p.prox
    p -> prox = novo;
    return l;
}
```
### Adição de elementos no fim da lista

É usada a seguinte função:

```C
Lista* inserirFim(Lista* l, int v)
{
    Lista *p = l;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    while (p -> prox != NULL)
    //vai aumentando p.prox até ele remeter ao NULL ou seja, quando ele for o último item da struct.
    {
        p = p -> prox;
        //p é o ponteiro que remete à lista. Portanto p.prox será o caminho para o próximo valor conforme a struct inicial.
        cont++;
    }
    novo -> info = v;
    novo -> prox = p -> prox;
    p -> prox = novo;
    return l;
}
```
### Remover elementos da lista

>Com uma lista ligada criada, podemos implementar o uso de funções para a remoção de elementos da lista. Segundo Celes, Cerqueira e Rangel (2004), a função para remover um elemento é mais trabalhosa e complexa e precisa de informações como parâmetros de remoção, o valor do elemento e a lista. Assim, a função atualiza o valor da lista sem o elemento removido. Caso o primeiro elemento da lista seja o que deve ser retirado, atualizaremos o valor da lista com o ponteiro para o segundo elemento, liberando o espaço alocado do elemento retirado.

>Se o elemento a ser retirado da lista pela função estiver no meio desta, o elemento anterior deve apontar para o elemento seguinte do qual será removido e, após isso, vamos liberar a alocação do elemento removido.

>Podemos utilizar um único trecho de código em uma função para realizar as operações de remoção da lista, sendo do início ou de outra posição desta lista. Criamos a função e já declaramos um ponteiro inicializado em NULL (`Lista*anterior`) para ser o ponteiro que vai receber o elemento anterior ao que será excluído e, logo depois, criamos outro ponteiro para receber a lista (`Lista*p`) passada por parâmetro:
```C
Lista* remove (Lista* l, int v) 
{
    Lista*anterior = NULL;
    Lista*p = l;
    //Neste momento, implementamos o comando de repetição WHILE para procurar o elemento a ser excluído e guardar a posição do anterior no ponteiro criado anteriormente:
    while (p != NULL && p->info != v) 
    {
        //o *anterior* "anda" um passo pra frente e se torna *p*
        anterior = p;
        //*p* anda um passo pra frente, caracterizado pelo *p.prox*
        p = p->prox;
    }
    //A função retorna à própria lista para a função principal, caso o elemento a ser excluído não seja encontrado na lista ligada:
    if (p == NULL)
        return l;
    //Sendo encontrado o elemento na lista, o comando de condição IF verifica se é o primeiro elemento ou não da lista. Se o valor armazenado no ponteiro for NULO, significa que é o primeiro elemento da lista; caso tenha outro valor, o elemento está em outra posição da lista. Essa função também remove o último valor da lista, já que ele armazena o ponteiro do elemento anterior:
    if (anterior == NULL) 
    {
        l = p->prox;
    } 
    else 
    {
        anterior->prox = p->prox;
    }
    //E utilizamos o RETURN da lista para retornar à função principal:
    return l;
}
```

### Percorrer a lista ligada



### Uso do Typedef
O `typedef` foi usado ao final da criação da *struct* pois ele dá um novo nome à uma estrutura já existente. Ele nunca cria uma nova estrutura.
Quando não se usa o `typedef` pra renomear uma *struct*, toda vez que ela for chamada no programa, necessariamente terá que se escrever `struct` antes do nome. Veja:
```C
#include<stdio.h>

struct Point{
  int x;
  int y;
};
int main() {
    struct Point p1; //uso da palavra "struct" antes do nome da própria struct.
    p1.x = 1;
    p1.y = 3;
    printf("%d \n", p1.x);
    printf("%d \n", p1.y);
    return 0;
}
```
A sintaxe a ser usada é a seguinte:

**typedef <tipo_da_estrutura> <nome_da_estrutura> <novo_nome>**

Veja o seguinte exemplo:
```C
#include<stdio.h>

struct Point{
  int x;
  int y;
};
typedef struct Point Point;
int main() {
    Point p1; //não precisei usar "struct" antes
    p1.x = 1;
    p1.y = 3;
    printf("%d \n", p1.x);
    printf("%d \n", p1.y);
    return 0;
}
```
OU
```C
#include<stdio.h>

typedef struct Point{ // uso do typedef antes do nome em vez de no final.
  int x;
  int y;
} Point;
int main() {
    Point p1; //não precisei usar "struct"
    p1.x = 1;
    p1.y = 3;
    printf("%d \n", p1.x);
    printf("%d \n", p1.y);
    return 0;
}
```
