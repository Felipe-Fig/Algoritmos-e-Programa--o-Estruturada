1) Segundo Schildt (1997), a estrutura condicional de seleção de casos, “switch-case”, “testa sucessivamente o valor de uma expressão contra uma lista de constantes inteiras ou de caractere”. Quando os valores são avaliados o comando é executado. É preciso estar atento para algumas particularidades para o comando switch / case: caso nenhum dos valores seja encontrado, o comando default será executado e os comandos são executados até o ponto que o comando break for localizado. Na figura a seguir, o fluxograma representa a estrutura condicional de seleção de casos:

Figura 5 - Fluxograma de estrutura condicional de seleção de casos

![figura 1](link)

Assinale a alternativa que contém a sintaxe em C que representa o fluxograma da figura anterior.

**Gabarito: ```C
switch (variável)
{
case constante1:
<comandos>
break;
case constante2:
<comandos>
break;
default: <comandos>
}
```
**
---

2) Existem casos em que é necessário estabelecer verificação de condições sucessivas, em que uma determinada ação poderá ser executada se um conjunto anterior de instruções ou condições for satisfeito. Sendo a ação executada, ela poderá ainda estabelecer novas condições. Isto significa utilizar uma condição dentro de outra condição. 

Fonte:Disponível em<http://estruturacondicional.blogspot.com/2008/07/estrutura-condicional-encadeada.html>Acesso.11.Jul.2018 (Modificado)

Este tipo de estrutura poderá possuir diversos níveis de condição, sendo chamadas de:

**Gabarito: aninhamentos ou encadeamentos.**

---

3) O laço do-while executa, pelo menos uma vez, o que está dentro dele e só ao final da execução é que ele faz o teste, usando o velho e conhecido laço while. Ou seja, tem-se a garantia que o laço vai ser executado uma vez, sem precisar inicializar variável ou pedir dados ao usuário antes do while. Vale lembra que do, em inglês e nesse contexto, do significa "faça" e while significa "enquanto".

Fonte:Disponível em <https://www.cprogressivo.net/2013/02/O-que-e-e-como-usar-o-laco-DO-WHILE-em-linguagem-C.html> Acesso.16.Jul.2018.

Esse laço do-while quer dizer:

**Gabarito: "faça isso" -> código -> "enquanto essa condição for verdadeira, repita".**

---

Na repetição com variáveis de controle, ou seja, usando o laço “for”, o comando iterativo “for” que em português significa “para”, segundo Mizrahi (2008), é geralmente usado para repetir uma informação por um número fixo de vezes, isto é, pode-se determinar quantas vezes acontecerá a repetição. Para facilitar ainda mais, veja a seguinte representação:

for(x = 10,y = 0; x >= 0, y <= 10; x--,y++)

Conforme esta representação, associe as colunas corretamente:

| Trecho do programa | Reprsentação |
| ------------------ | ------------- |
| I. (x = 10, y = 0; | A. O laço se repetirá enquanto x for maior ou igual a zero e enquanto y for menor ou igual a 10.|
| II.  x >= 0, y <=10; | B. O “x” tem o seu valor iniciado em “10” e “y” iniciado em “0”. |
| III.   x--,y++) | C. x será decrementado de 1 e y será incrementado de 1. |

**Gabarito: I-B,  II-A , III-C.**

---