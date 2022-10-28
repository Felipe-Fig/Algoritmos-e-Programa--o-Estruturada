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

Vamos visualizar essa situação. Aqui eu trago três nodes, cada um com seu nome, dados e ponteiros:

| HEAD | MEIO | END |
| ---- | ---- | --- |
|int dados|int dados|int dados|
|*p frente|*p frente|*p frente|
|*p trás|*p trás|*p trás|

Fazer a remoção de um node significará atuar nos dois nodes adjacentes para alterar seus ponteiros.
O programa que usaremos recebe como parâmetro o node que queremos retirar, portanto precisamos usar essa informação pra chegar aos nodes adjacentes e então fazer as alterações.

- Suponha que o node a ser removido é o *HEAD*:

Atuaremos nos nodes adjacentes a ele, sendo pra trás `NULL` e pra frente o node `MEIO`.  Ou seja, teremos que conectar o ponteiro `*p trás` do node `MEIO` com o `NULL`.

Porém, o usuário ou programa só fornece o node a ser retirado, nesse caso `HEAD`. Com isso, teremos que usar uma forma mais difícil de entender para acessar os dados dos nodes adjacentes, mas garanto que você entenderá.

`HEAD->*p frente = MEIO`

Por esse pseudocódigo acima entenda que: no node *HEAD* temos o ponteiro **p frente* e esse ponteiro aponta para o node *MEIO*.

`HEAD->*p trás-> NULL`

Aqui o node *HEAD* em seu ponteiro **p trás* aponta para *NULL* visto que ele é o primeiro da lista. Portanto, precisamos passar a informação de que `MEIO->*p trás = NULL` sem mencionar o node *MEIO*.

Para isso usamos a seguinte equivalência:<br> `HEAD->*p trás = HEAD->*p frente->*p trás`.

O quê fizemos aqui foi falar que o ponteiro **p trás* do node *MEIO* (NULL) passará a ser o [`HEAD->*p-> frente` que é o node *MEIO*] [`->*p trás` que é seu ponteiro para trás.] Veja que `HEAD->*p frente->*p trás` é o mesmo que `MEIO->*p trás`.

Se antes o `MEIO->*p trás` apontava para o endereço do node *HEAD*, agora ele passará a apontar para *NULL*.

Toda operação de remoção, independente do node retirado passa por esse reciocínio. Com isso vou trazer um pseudocódigo que facilitará entender a utilização para todos os casos. Após isso é só implementar.

```
se HEAD == node_a_remover então
    HEAD == node_a_remover->*p frente

    // se o node HEAD for o node a ser removido, então o novo HEAD da lista duplamente ligada será o node que está guardado no ponteiro *p frente do HEAD, ou seja, no nosso exemplo, MEIO.

se node_a_remover->*p frente != NULL então
    node_a_remover->*p frente->*p trás = node_a_remover->*p trás

    // caso o node_a_remover->*p frente seja = NULL significa que ele é o último da lista. Se ele for != então tem algum ou alguns nodes na frente dele. Então, se node_a_remover->*p frente != NULL o <node_a_remover->*p frente->*p trás que é igual ao ponteiro *p trás node seguinte> será alterado para o ponteiro *p trás do node_a_remover.

se node_a_remover->*p trás != NULL então
    node_a_remover->*p trás->*p frente = node_a_remover->*p frente

    // usando a mesma analogia do caso acima, se existe algum node antes do node_a_remover então deve ser feita a alteração do ponteiro *p frente do node antes do que será removido para o endereço do ponteiro *p frente do node_a_remover. Lembre-se que o node anterior ao node_a_remover é <node_a_remover->*p trás>.
```

O [Geeks for Geeks](https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/) traz esse código, o qual eu ainda traduzirei para facilitar o entendimento:

```C
#include <stdio.h>
#include <stdlib.h>

/* a node of the doubly linked list */
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del --> pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del)
{
	/* base case */
	if (*head_ref == NULL || del == NULL)
		return;

	/* If node to be deleted is head node */
	if (*head_ref == del)
		*head_ref = del->next;

	/* Change next only if node to be deleted is NOT the last node */
	if (del->next != NULL)
		del->next->prev = del->prev;

	/* Change prev only if node to be deleted is NOT the first node */
	if (del->prev != NULL)
		del->prev->next = del->next;

	/* Finally, free the memory occupied by del*/
	free(del);
	return;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* since we are adding at the beginning,
	prev is always NULL */
	new_node->prev = NULL;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list
This function is same as printList() of singly linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Let us create the doubly linked list 10<->8<->4<->2 */
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	printf("\n Original Linked list ");
	printList(head);

	/* delete nodes from the doubly linked list */
	deleteNode(&head, head); /*delete first node*/
	deleteNode(&head, head->next); /*delete middle node*/
	deleteNode(&head, head->next); /*delete last node*/

	/* Modified linked list will be NULL<-8->NULL */
	printf("\n Modified Linked list ");
	printList(head);

	getchar();
}
```

## Ordenar a lista duplamente ligada

Em uma lista duplamente ligada, é possível realizar a ordenação de seus elementos de forma crescente ou decrescente, criando uma simples comparação entre os elementos e realizando a sua troca, em caso de aceitarem a condição de maior ou menor. Podemos utilizar o trecho de código a seguir para realizar a ordenação:

```C
void Ordena(Lista* l)
{
    Lista* p;
    Lista* aux;
    int temp;
    for (p = l; p != NULL; p = p -> prox) 
    {
        for (aux = p -> prox; aux != NULL; aux = aux -> prox)
        {
            if ((p -> info) > (aux -> info)) 
            {
                temp = p -> info;
                p -> info = aux -> info;
                aux -> info = temp;
            }
        }
    }
}
```

Para chamar a função de ordenação, passamos somente na função principal Main o parâmetro a seguir:

`printf(“\n Lista Ordenada”);`
`Ordena(listaFinal);`

Neste exemplo, podemos observar que o sistema realiza a chamada da função e executa as rotinas, mas é possível, dentro da função principal Main, criar rotinas nas quais o usuário pode informar os elementos para serem inseridos, removidos ou para realizar a busca de um elemento.

Reflita: Sabemos que as listas duplamente ligadas permitem as mesmas funções que as listas ligadas simples, no entanto, podemos saber qual o elemento anterior e o próximo elemento devido aos ponteiros existentes. De que forma poderíamos imprimir a lista em ordem inversa em uma lista duplamente ligada?

### Questão e resposta apresentados pelo material: 

Você tem a função de atender à demanda de um cliente de um comércio de autopeças que possui duas unidades, uma matriz e uma filial, e deseja gerar um relatório para informação de estoque mínimo em seu sistema. O cliente solicitou que o relatório seja gerado em tempo real, apresentando um gráfico atualizado todas as vezes que um produto entrar ou sair desta listagem, por meio da venda ou compra de produtos. Este cliente também deseja pesquisar se um produto consta na listagem ou não.

Como desafio, você precisa implementar no relatório em que está trabalhando a adição ou remoção de produtos na listagem de produtos.
Como podemos adicionar ou remover produtos nesta lista? Pesquise sobre algoritmos de adição e remoção de dados em uma lista ligada.

Como é possível adicionar a função de busca por algum produto específico na listagem? Você vai precisar pesquisar e compreender o funcionamento do algoritmo para percorrer uma lista e verificar se determinado valor se encontra nela.

Para a resolução desta situação-problema, é necessário compreender os conceitos sobre as operações em listas ligadas e pesquisar outras técnicas para a criação das funções, para executar a adição e a remoção de elementos, assim como percorrer a lista e realizar uma contagem dos elementos e a criação da busca de elementos em uma lista ligada.
Para iniciar, implementamos a lista como:

```C
#include <stdio.h>
#include <stdlib.h>

// perceba que não se trata de uma lista duplamente ligada nesse caso pois há apenas uma referência de ponteiro.
struct listaProd 
{
    int codigo;
    char produto[30];
    struct listaProd* prox;
};
typedef struct listaProd Produtos;

// função usada para inicializar a lista (struct)
Produtos* inicializar (void)
{
    return NULL;
}

// função que INSERE novos produtos na lista. Nesse caso é passado para a função uma lista "l" que é do tipo da struct ou lista "Produtos", por isso do ponteiro.
Produtos* inserir (Produtos* l, int i, char* nprod) 
{
    Produtos* novo = (Produtos*)malloc(sizeof(Produtos));
    novo -> codigo = i;
    novo -> produto = nprod;
    // repare que o produto é adicionado ao início da lista fornecida. Quando você fornece uma  lista "l", esse produto "novo" é adicionado em seu início, o que pode ser confirmado ao avaliar que o ponteiro "novo.prox" aponta para o primeiro endereço de "l".
    novo -> prox = l;
    return novo;
}

// função usada para REMOVER produtos da lista. Para esse função é fornecida uma lista "l" da qual o item será removido e um inteiro "v" que indica o índice "produtos.código" da lista em questão, ou seja, o número do produto a ser removido.
Produtos* retira (Produtos* l, int v) 
{

    Produtos* ant = NULL;

    Produtos* p = l;

    // código que vai iterar ao longo da lista enquanto "p" não for NULL, sendo que "p" começa sendo o valor "l" ou a lista passada para ter um ítem retirado E o código dessa lista (p.codigo) seja diferente do parâmetro passado pelo usuário "v", pois "v" é o código do item a ser removido.
    while (p != NULL && p -> codigo != v) 
    {
        ant = p;
        p = p -> prox;
        // enquanto esse loop for verdadeiro o anterior (que começa como NULL) passa a ter o valor de "p" e o que era "p" passará a ser "p.prox", caracterizando o percorrer da lista.
    }

    // caso seja fornecida uma lista "l" vazia, "p" será igual a "l" e se for == NULL, retorna a mesma lista fornecida.
    if (p == NULL )
        return l;
    
    // não entendi especificamente o quê essa parte da função faz visto que no início da função "Produtos* ant = NULL" então (em tese) todos os casos deveriam passar direto por essa condição abaixo...
    if (ant == NULL) 
    {
        l = p -> prox;
    } 
    else 
    {
        ant -> prox = p -> prox;
    }

    return l;
}

Produtos* busca(Produtos* l, int v)
{
    Produtos* p;
    for (p = l; p != NULL; p = p -> prox) 
    {
        if (p -> codigo == v)
            return p;
    }
    return NULL;
}

int main() 
{
    int cont, codprod;
    char nprod[30];

    Produtos* listaProdutos;
    listaProdutos = inicializar(); /* inicializa lista como vazia */

    for (cont = 0; cont < 3; cont++)
    {
        printf("\n Informe o codigo do Produto: ");
        scanf("%d",&codprod);
        printf("\n Informe o nome do Produto: \n");
        scanf("%d",&nprod);
        listaProdutos = inserir(listaProdutos, codprod, nprod);
    }

    printf("Lista Produtos:\n");
    imprimir(listaProdutos);
    printf("\n Informe o codigo do produto para pesquisa: ");
    scanf("%d", &codpro);

    if (busca(listaProdutos, codprod) == NULL) 
    {
        printf("\n\n- Produto não encontrado \n");
    } 
    else 
    {
        printf("\n\n- Produto encontrado \n");
    }
    printf("\n"); 
    system(“PAUSE”);
}
```