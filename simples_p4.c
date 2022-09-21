// Candididato 017
// Problema simples 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Recebe um caracter e uma string e retorna quantas vezes o caracter aparece na string
int encontra_letra (char a, char str[]) {

    int i, n = 0;

    for (i = 0; i < strlen(str); i++){
        if (str[i] == a){
            n++;
        }
    }

    return n;
}

int main() {

    char frase[100], letra;

    printf("Digite a letra a ser encontrada: ");
    scanf("%c", &letra);
    setbuf(stdin, NULL);
    printf("Digite a frase: ");
    scanf("%[^\n]s", &frase);

    printf("\nNumero de vezes que a letra esta presente: %d\n", encontra_letra(letra, frase));

    return 0;
}
