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
7. [Verificar se um elemento consta na lista ligada](#verificar-se-um-elemento-consta-na-lista-ligada)
8. [Uso do Typedef](#uso-do-typedef)
---
As listas ligadas são estruturas lineares como *arrays*. Porém a diferença está no fato de que os elementos da lista ligada não estão em uma parte contígua da memória, portanto para que haja uma ligação entre todos os seus objetos ou elementos, cada um deles possuirá <dados + o endereço do ponteiro> que indica o próximo elemento/objeto/node.

Um detalhe é que não é possível fazer acesso randômico à uma lista ligada. Caso seja necessário, todos os elementos deverão ser acessados sequencialmente, desde o primeiro até o último, seja lá qual for a inteção do programador/usuário.

Vou colocar a seguir um código que eu peguei no [Geeks for Geeks](https://www.geeksforgeeks.org/what-is-linked-list/) (e traduzi) pra facilitar o entendimento da criação de listas ligadas. Esse exemplo será de uma lista ligada com 3 nodes especificamente. Lembrando que cada node possui além dos dados, um endereço (ponteiro) para o próximo node.

```C
// Programa em C criado para entender a implementação de listas ligadas
#include <stdio.h>
#include <stdlib.h>

// A criação de listas ligadas em C é feito com *structs*. Nesse caso específico o único dado que essa struct possui é *data* que trata-se de um inteiro.
struct Node {
	int data;
	struct Node* next;
};

int main()
{

	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// alocação de 3 blocos na pilha. Um se chama *head*, o outro *second* e o outro *third*. Seus ponteiros apontam pra *NULL*

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	/* Acima é feita a alocação dinâmica de memória para os três blocos ou *nodes*.
	Abaixo você vê uma representação dos ponteiros para cada um desses blocos/nodes.
    
	  head		  second		    third
		|			 |			      |
		|			 |			      |
	+---+-----+	 +----+----+	 +----+----+
	 | # | # |	  | # | # |	      | # | # |
	+---+-----+	 +----+----+	 +----+----+

    O # representa um dado randômico/qualquer. Nesse momento é representado um dado qualquer pois ainda não foi passado nenhum valor para compor esses blocos. */

	head->data = 1; // dá o valor *1* para o componente *data* do bloco/node *head*, o primeiro que criamos.
	head->next = second; // para o objeto *next* do node *head* eu atribuo o endereço do *second* ou o segundo node que criamos.

	/* Dados foram adicionados para a variável *data* do primeiro bloco criado *head*. Com o valor *head.next = second* temos que o primeiro bloco aponta para o segundo, portanto podemos dizer que eles estão ligados.

	   head		   second		     third
		|			  |			       |
		|			  |			       |
	+---+---+	 +----+----+	 +-----+----+
	| 1 | o-----> | # | # |	       | # | # |
	+---+---+	 +----+----+	 +-----+----+
    */

	// adicionamos dados na variável *data* do segundo node (second)
	second->data = 2;

	// Linkamos o *second* (segundo node) com o terceiro
	second->next = third;

	/* data has been assigned to the data part of the second
	block (block pointed by second). And next
	pointer of the second block points to the third
	block. So all three blocks are linked.

	   head		  second		 third
		|			 |			   |
		|			 |			   |
	+---+---+	 +---+---+	  +----+----+
	| 1 | o----->| 2 | o-----> | # | # |
	+---+---+	 +---+---+	  +----+----+	 */

	third->data = 3; // adicionamos dados (valor 3) à variável *data* do terceiro (third) node.
	third->next = NULL;

	/* O ponteiro do último node aponta pra NULL pra mostrar que ele é o último da sequência.

	Agora a lista ligada está pronta.

		  head
			|
			|
		+---+---+	 +---+---+	 +----+------+
		| 1 | o----->| 2 | o-----> | 3 | NULL |
		+---+---+	 +---+---+	 +----+------+


	Note que apenas *head* é suficiente para representar toda a lista ligada. Com ele nós podemos andar por toda a lista, usando apenas os ponteiros presentes na mesma. */

	return 0;
}
```

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

>Talvez você precise saber quais os elementos que fazem parte da sua lista, em determinado momento do seu sistema. Para tal, é necessário percorrer toda a lista ligada para verificar esses elementos. A lista ligada pode ser impressa com todos os seus elementos, e podemos utilizar o trecho de código a seguir. Por ser uma função que vai percorrer toda a lista e de impressão em tela, podemos declará-la como VOID, uma função que não vai retornar valor para a função principal:

```C
void imprimir (Lista* l) 
{
    Lista* p;
    printf("Elementos:\n");
    //Neste trecho, uma condição de repetição FOR percorre a lista e imprime todos os elementos encontrados na lista:
    for (p = l; p != NULL; p = p->prox)
    {
        printf(" %d -> ", p->info);
    }
}
```

Existe também outro código retirado do [Geeks for Geeks](https://www.geeksforgeeks.org/what-is-linked-list/) que mostra o mesmo processo porém ligeiramente diferente. Segue:

```C
// Programa em C que printa os itens de uma lista ligada.

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node* next;
};

// Essa função *printList()* printa os nodes de uma lista ligada partindo do node *n* dado pra ela.
void printList(struct Node* n)
{
	while (n != NULL) 
    {
		printf(" %d ", n->data);
		n = n->next;
	}
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// aloca 3 nodes no bloco

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1; 
	head->next = second; 

	second->data = 2; 
	second->next = third;

	third->data = 3;
	third->next = NULL;

	// Chamamento da função
	printList(head);

	return 0;
}
```

Nesse acso o **output** será: `1 2 3`

### Verificar se um elemento consta na lista ligada

>Outra função muito útil é verificar se determinado elemento consta na lista ou não, segundo Celes, Cerqueira e Rangel (2004). Essa função pode ser criada para receber a informação de qual elemento se deseja buscar e, caso encontre o valor, a função retorna o ponteiro do nó da lista em que representa o elemento ou sua posição na lista, ou, como no nosso exemplo, informa se o elemento foi encontrado ou não. Podemos utilizar o trecho de código a seguir para implementar a função de busca:

```C
Lista* buscar(Lista* l, int v)
{
    Lista* p;
    //Criamos uma condição de repetição para procurar na lista o elemento solicitado, passado por parâmetro e até terminar a lista, comparando se o elemento é o que está consultado. Sendo verdadeiro, retorna o ponteiro; caso contrário, retorna NULL:
    for (p = l; p != NULL; p = p->prox) 
    {
        if (p->info == v)
            return p;
    }
    return NULL;
}
``` 
>Já para a implementação na função principal, podemos utilizar o seguinte trecho de código para chamar a função e escrever se foi encontrado ou não o elemento. Se o retorno for `NULL`, será escrito `Elemento não encontrado`; caso encontre, será escrito `Elemento encontrado`.

```C
if (busca(listaFinal, v) == NULL) 
{
    printf("\n Elemento não encontrado");
} 
else 
{
    printf("\n Elemento encontrado");
}
```

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
