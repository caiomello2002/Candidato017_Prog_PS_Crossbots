// Candidato 017
// Problema intermediario 2

#include <stdio.h>
#include <stdlib.h>

/* Recebe um vetor (lista[]) e o endereco de seu tamanho (n) e retorna o vetor sem numeros repetidos
   e atualiza seu tamanho (n) no codigo fonte*/
int *tira_repeticoes (int lista[], int *n){

    int i, j, k = 0, aux, n_final = 0, *lista_final;

    // Analisa qual sera o tamanho da lista sem repeticoes
    for (i = 0; i < *n; i++){
        aux = 0;
        for (j = i-1; j >= 0; j = j - 1){
            if (lista[i] == lista[j]){
                aux++;
            }
        }
        if (aux == 0){
            n_final++;
        }
    }

    lista_final = (int *) malloc(n_final*sizeof(int));

    // Armazena a lista sem repeticoes em lista_final
    for (i = 0; i < *n; i++){
        aux = 0;
        for (j = i-1; j >= 0; j = j - 1){
            if (lista[i] == lista[j]){
                aux++;
            }
        }
        if (aux == 0){
            lista_final[k] = lista[i];
            k++;
        }
    }

    *n = n_final; /* Faz com que o numero de elementos da lista inicial
                     seja atualizado para seu novo numero de elementos */

    return (lista_final);
}

int main(){

    int i, n, *lista;

    printf("Quantos numeros ha em sua lista? ");
    scanf("%d", &n);

    lista = (int *)malloc(n*sizeof(int));

    printf ("Digite-os um abaixo do outro:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &lista[i]);
    }

    lista = tira_repeticoes(lista, &n);

    printf ("\nlist = [%d", lista[0]);
    for (i = 1; i < n; i++){
        printf(", %d", lista[i]);
    }
    printf("]\n");

return 0;
}
