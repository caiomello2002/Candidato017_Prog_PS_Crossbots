// Candidato 017
// Problema dificil 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tipo feito para armazenar os casos teste
typedef struct {

    char str[1010];

} strings;

// Recebe a string e o endereco do numero de diamantes, conta o numero de diamantes e o altera no codigo fonte
void verifica_diamantes (char str[], int *n){

    int i, j, tam = strlen(str), aux = 0;

    for (i = 0; i < tam; i++){
        if (str[i] == '<'){
            for (j = i+1; j < tam; j++){
                if (str[j] == '<'){
                    break;
                }
                else if (str[j] == '>'){
                    *n = *n + 1;
                    aux++;
                    str[i] = '.';
                    str[j] = '.';
                    break;
                }
            }
        }
    }

    if (aux != 0){
        verifica_diamantes(str, n);
    }

}

int main () {

    int i, N, n_diamantes = 0;
    strings *casos_teste;

    scanf("%d", &N);

    casos_teste = (strings*)malloc(N*sizeof(strings));

    for (i = 0; i < N; i++){
        scanf("%s", casos_teste[i].str);
    }

    for (i = 0; i < N; i++){
        verifica_diamantes(casos_teste[i].str, &n_diamantes);
        printf("%d\n", n_diamantes);
        n_diamantes = 0;
    }


return 0;
}
