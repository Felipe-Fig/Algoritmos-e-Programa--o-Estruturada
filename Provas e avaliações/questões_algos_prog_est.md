# Questões genéricas sobre Algoritmos e Programação Estruturada

## Comentários e gabaritos feitos por mim, aceito opiniões diversas.

### **Questão**

Podemos inserir um elemento em uma lista em três situações diferentes. Ao inserirmos uma informação na lista ligada, é imprescindível que seja atualizado o valor do ponteiro dessa lista, assim a lista ligada deverá apontar ao novo elemento da lista, segundo Celes, Cerqueira e Rangel (2004).

Dado o trecho de código a seguir:
```C
Lista* inserir (Lista* l, int i) 
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo -> info = i;
    novo -> prox = l;
    return novo;
}
```
Assinale a alternativa que define a funcionalidade do trecho de código informado:

a. Inserir um elemento no meio da lista.<br>
b. Remover um elemento do início da lista.<br>
c. Apagar toda a lista para recomeçar.<br>
d. Inserir um elemento no final da lista.<br>
e. Inserir um elemento no início da lista

**Gabarito: e. Inserir um elemento no início da lista.**

---

### **Questão**

Segundo Celes, Cerqueira e Rangel (2004), com a estrutura de dados das listas ligadas não há como percorrer os elementos de forma inversa na lista, iniciando pelo fim até o início. E, apesar de ser possível, a retirada de um elemento da lista com encadeamento simples é mais trabalhosa de ser realizada, pois é necessário percorrer toda a lista para encontrar o elemento anterior, pois dado o ponteiro para determinado elemento, temos acesso ao seu próximo elemento e não ao anterior.

Com base no texto, podemos afirmar que a alternativa correta quanto às listas duplamente ligadas é:

a. Uma lista duplamente ligada requer obrigatoriamente a utilização de duas estruturas do tipo lista.
b. Uma lista duplamente ligada possui em um nó somente um ponteiro para o próximo elemento e um ponteiro para o elemento anterior.
c. Uma lista duplamente ligada não permite a impressão da lista de forma inversa, devido aos ponteiros que não mantêm a informação do elemento anterior.
d. Uma lista duplamente ligada possui, em um nó, o campo para informação, um ponteiro para o próximo elemento e um ponteiro para o elemento anterior.
e. Uma lista duplamente ligada, por manter informações do elemento anterior, não utiliza do recurso de alocação dinâmica de memória.

**Gabarito: d. Uma lista duplamente ligada possui, em um nó, o campo para informação, um ponteiro para o próximo elemento e um ponteiro para o elemento anterior.**

---

### **Questão**

Em uma lista duplamente ligada é possível realizar a ordenação de seus elementos de forma crescente ou de forma decrescente, criando uma simples comparação entre os elementos e realizando sua troca em caso de aceitarem a condição de maior ou menor.

Considerando a estrutura de dados de ordenação em ordem crescente, o trecho de código que melhor define a ordenação na lista duplamente ligada é:

a. 
```C
for (p = l; p != NULL; p = p -> prox) 
{
    for (aux = p -> prox; aux != NULL; aux = aux -> prox) 
    {
        if ((p -> info) < (aux -> info)) 
        {
            temp = p -> info;
            p -> info = aux -> info;
            aux -> info = temp;
        }
    }
}
```

b. 
```C
for (p = l; p != NULL; p = p -> prox) 
{
    for (aux = p -> prox; aux != NULL; aux = aux -> prox) 
    {
        if ((p -> info) > (aux -> info)) 
        {
            p -> info = aux -> info;
            aux -> info = p -> info;
        }
    }
}
```

c. 
```C
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
```

d. 
```C
for (p = l; p != NULL; p = p -> prox) 
{
    for (aux = p -> prox; aux != NULL; aux = aux -> prox) 
    {
        if ((p -> info) < (aux -> info)) 
        {
            p -> info = aux -> info;
            aux -> info = p -> info;
        }
    }
}
```

e. 
```C
for (p = l; p != NULL; p = p -> prox) 
{
    for (aux = p -> prox; aux != NULL; p = p -> prox) 
    {
        if ((p -> info) > (aux -> info)) 
        {
            temp = p -> info;
            p -> info = aux -> info;
            aux -> info = temp;
        }
    }
}
```

**Gabarito: **

---

