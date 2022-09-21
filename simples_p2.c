// Candidato 017
// Problema simples 2

#include <stdio.h>

// Recebe um numero inteiro e verifica se eh perfeito (return = 1) ou nao (return = 0)
int verifica_perfeito (int n) {

    int i, aux = 0;

    for (i = 1; i < n; i++){
        if (n%i == 0){
            aux = aux + i;
        }
    }

    if (aux == n){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int num;

    printf("Digite o numero: ");
    scanf("%d", &num);

    if (verifica_perfeito(num) == 1){
        printf("\nO numero eh perfeito\n");
    }
    else{
        printf("\nO numero nao eh perfeito\n");
    }

    return 0;
}
