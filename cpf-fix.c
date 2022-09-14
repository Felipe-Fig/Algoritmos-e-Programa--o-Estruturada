//Algoritmo para corrigir input "errado" de CPF
// Retira os pontos e traços

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char cpf_in[15];
    char cpf_out[12];
    int n = 0;

    printf("Digite o CPF:\n");
    scanf("%s", cpf_in);
    //printf("Teste formato CPF: %s", cpf_in);

    //Verificar se é tudo número ou se tem caracteres
    for (int i = 0; i <= strlen(cpf_in); i++)
    {
        if (cpf_in[i] == '.' || cpf_in[i] == '-')
        {
            continue;
        }
        else
        {
            cpf_out[n] = cpf_in[i];
            n++;
        }
    }
    printf("O CPF organizado é: %s", cpf_out);
}

