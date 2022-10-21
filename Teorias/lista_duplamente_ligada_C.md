# Lista duplamente ligada em C

## Table of contents
1. [Introdução](#introdução)
2. [Adicionar elementos à lista duplamente ligada](#adicionar-elementos-à-lista-duplamente-ligada)
3. [Remover elementos da lista duplamente ligada](#remover-elementos-da-lista-duplamente-ligada)
4. [Ordenar a lista duplamente ligada](#ordenar-a-lista-duplamente-ligada)

## Introdução

A lista duplamente ligada funciona como uma [lista ligada](lista_ligada_C.md) porém ele possui um ponteiro a mais. Portanto a lista duplamente ligada possui 2 ponteiros no total, sendo um deles ligado ao próximo item da lista e outro ponteiro que aponta para o item anterior da lista.

O primeiro node aponta pra trás p/ `NULL` assim como o último aponta pra frente p/ `NULL`.

>Segundo Tenenbaum, Langsam e Augenstein (2007), um nó em uma lista duplamente ligada consiste na criação de três campos:
• Um campo-elemento para a informação/dado.
• Um ponteiro direcionando para o **próximo elemento**.
• Um ponteiro direcionando para o **elemento anterior**.
Na criação de uma lista duplamente ligada, é preciso criar – além do tipo de dado que será utilizado em sua implementação e o ponteiro que informa qual o próximo elemento – o ponteiro direcionando para o elemento anterior da lista, como o modelo de implementação a seguir:
```C
struct Lista 
{
    int info;
    struct lista* ant;
    struct lista* prox;
};
typedef struct lista Lista;
```
[Caso você ainda tenha alguma dúvida em Typedef, clique aqui.](https://github.com/Felipe-Fig/Algoritmos-e-Programacao-Estruturada/blob/master/lista_ligada_C.md#uso-do-typedef)

>Como na lista ligada simples, também precisamos inicializar a lista duplamente ligada para a utilizarmos após a sua declaração. Uma das possíveis formas de inicialização é criar a função retornando a lista como nula:
```C
/* Função para retornar uma lista vazia */
Lista* inicializar (void)
{
    return NULL;
}
```

### Vantagens
- A lista pode ser acessada tanto de trás pra frente quanto de frente pra trás
- A deleção é mais eficiente
- A inserção de um node é mais rápida

### Desvantagens
- Há a necessidade de mais espaço para guardar o ponteiro anterior
- Todas as operações terão que tratar de ambos os ponteiros

## Adicionar elementos à lista duplamente ligada

>Podemos adicionar um novo elemento à lista duplamente ligada. Se a lista estiver vazia, este elemento terá como elementos anterior e próximo o valor `NULL`. No caso de a lista estar com elementos inseridos, ao adicionar um novo elemento, o elemento antigo passa a ser o próximo elemento da lista e o anterior passa a receber o valor `NULL`.

>O trecho de código a seguir representa a inserção de um novo elemento no início da lista:
```C
Lista* inserir (Lista* l, int i) 
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    novo->ant = NULL;
    
    //Verifica se lista não está vazia e faz a troca de *l.ant* do node *l* que foi passado para a função. A partir desse ponto o node fornecido como head de uma lista passará a ser o segundo node visto que *l.ant* apontará para *novo* ou o endereço do novo node que está sendo criado.
    if (l != NULL)
        l->ant = novo;
    return novo;
}

int main() 
{
    Lista* listaFinal;
    listaFinal = inicializar();
    listaFinal = inserir(listaFinal, 20);
}
```

>A adição de um novo elemento pode ser realizada tanto no início da lista como no seu final, ou em uma posição específica. É bom salientar que em uma lista duplamente ligada é necessário sabermos o ponteiro para o elemento anterior e para o próximo elemento, quando for implementado um código de adição de elementos no meio da lista.

O meu material não contemplava as outras operações de adição em listas duplamente ligadas. Deixo aqui um [link](https://www.geeksforgeeks.org/doubly-linked-list/) que pode ajudar caso seja necessário. Talvez futuramente eu faça a tradução. 

## Remover elementos da lista duplamente ligada

>Segundo Celes, Cerqueira e Rangel (2004), a função de remoção em uma lista permite remover um elemento da lista duplamente ligada apenas conhecendo o ponteiro para este elemento. Para facilitar a localização de um elemento na lista, podemos utilizar a função de busca e, em seguida, ajustar o encadeamento da lista, liberando, por fim, o elemento da alocação de memória.

Um trecho de uma função de busca pode ser implementado por:
```C
Lista* busca(Lista* l, int v)
{
    Lista* p;
    for (p = l; p != NULL; p = p->prox) 
    {
        if (p->info == v)
            return p;
    }
    return NULL;
}
```
>Assim, encontrado o elemento que se deseja remover, basta apontar o anterior para o próximo e o próximo para o anterior, permitindo que o elemento no meio da lista possa ser removido do encadeamento.
Conforme Celes, Cerqueira e Rangel (2004), se o elemento que desejamos remover estiver no início ou no final da lista, o apontamento para o anterior ao início será nulo, assim como se for o último, o apontamento para o próximo também será nulo.

Podemos implementar o trecho de código de remoção como segue:
```C
Lista* retira (Lista* l, int v) 
{
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL && p->info != v) 
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
        return l;

    if (ant == NULL)
    {
        l = p->prox;
    }
    else
    {
        p->ant -> prox = p->prox;
    }

    if (p->prox != NULL)
        p->prox -> ant = p->ant;

    return l;
}
```
Olhando apenas esse código eu ainda acho que fica um pouco complicado de entender, por isso vou tentar ser mais prolixo deliberadamente para facilitar o entendimento. Veja: 

Um node ao ser deletado de uma lista duplamente ligada pode estar em uma das seguintes situações:
- Ele pode ser o primeiro node ou *head*
- Ele pode estar no meio da lista ligada
- Ele pode ser o último node da lista
Portanto é importante colocar todas estas situações no código e ainda respeitar o que foi falado acima de trocar os ponteiros para remover esse node da lista.


## Ordenar a lista duplamente ligada