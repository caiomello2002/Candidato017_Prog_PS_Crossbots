// Candididato 017
// Problema simples 3

#include <stdio.h>
#include <stdlib.h>

/*Recebe um vetor (vtr[]) e seu tamanho (n) e o retorna somente com os numeros primos
  e atualiza seu tamanho (n) no codigo fonte*/
int *encontra_primo (int vtr[], int *n){

    int i, j, k = 0, aux, n_final = 0, *vtr_final;

    // Analisa qual sera o tamanho da lista somente com os numeros primos
    for (i = 0; i < *n; i++){
        aux = 0;
        for (j = 1; j <= vtr[i]; j++){
            if (vtr[i]%j == 0){
                aux++;
            }
        }
        if (aux == 2){
            n_final++;
        }
    }

    vtr_final = (int *) malloc(n_final*sizeof(int));

    // Armazena a lista somente com os numeros primos em vtr_final
    for (i = 0; i < *n; i++){
        aux = 0;
        for (j = 1; j <= vtr[i]; j++){
            if (vtr[i]%j == 0){
                aux++;
            }
        }
        if (aux == 2){
            vtr_final[k] = vtr[i];
            k++;
        }
    }

    *n = n_final;/* Faz com que o numero de elementos da lista inicial
                     seja atualizado para seu novo numero de elementos */

    return (vtr_final);

}

int main () {

    int *lista, i, n;

    printf("Tamanho da lista: ");
    scanf("%d", &n);

    lista = (int *)malloc(sizeof(int)*n);

    printf("Digite os numeros um abaixo do outro:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &lista[i]);
    }

    lista = encontra_primo(lista, &n);

    printf ("\nLista somente com os numeros primos:\n[%d", lista[0]);
    for (i = 1; i < n; i++){
        printf(", %d", lista[i]);
    }
    printf("]\n");


return 0;
}