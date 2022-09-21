// Candidato 017
// Problema simples 1

#include <stdio.h>

#define n 10

int main() {
    int vetor[n], x, y, i, soma;

    printf("Entrada:\n");
    scanf("lista = [%d", &vetor[0]);
    for (i = 1; i < n; i++){
    scanf(", %d", &vetor[i]);
    }
    scanf("]");

    printf("Digite x: ");
    scanf("%d", &x);
    printf("Digite y: ");
    scanf("%d", &y);
    soma = vetor[x] + vetor[y];
    printf("\nSoma = %d\n", soma);

return 0;
}
