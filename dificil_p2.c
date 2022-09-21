// Candidato 017
// Problema dificil 2

#include <stdio.h>
#include <stdlib.h>

// Tipo criado para que seja mais simples lidar com a matriz de caracteres
typedef struct {

    char s[10];

} caracteres;

// Verifica se determinada casa esta dentro ou fora do tabuleiro
int condicoes (int i, int j, int n){

    if (i < 0 || i >= n || j < 0 || j >= n) return 1;
    return 0;

}

/* Recebe a matriz e seu tamanho e retorna, de acordo exclusivamente com o peao,
  "B" se o rei branco esta em cheque, "P" se o rei preto esta em cheque ou "N" se nenhum esta */
char verifica_peao (caracteres *matriz, int n){

    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (matriz[i].s[j] == 'p'){
                if (matriz[i+1].s[j-1] == 'K' && condicoes(i+1,j-1,n) == 0) return 'B';
                else if (matriz[i+1].s[j+1] == 'K' && condicoes(i+1,j+1,n) == 0) return 'B';
            }
            else if (matriz[i].s[j] == 'P'){
                if (matriz[i-1].s[j-1] == 'k' && condicoes(i-1,j-1,n) == 0) return 'P';
                else if (matriz[i-1].s[j+1] == 'k' && condicoes(i-1,j+1,n) == 0) return 'P';
            }
        }
    }
    return 'N';
}

/* Recebe a matriz e seu tamanho e retorna, de acordo exclusivamente com o cavalo,
  "B" se o rei branco esta em cheque, "P" se o rei preto esta em cheque ou "N" se nenhum esta */
char verifica_cavalo (caracteres *matriz, int n){

    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (matriz[i].s[j] == 'n'){
                if (matriz[i-1].s[j-2] == 'K' && condicoes(i-1,j-2,n) == 0) return 'B';
                else if (matriz[i-2].s[j-1] == 'K' && condicoes(i-2,j-1,n) == 0) return 'B';
                else if (matriz[i-2].s[j+1] == 'K' && condicoes(i-2,j+1,n) == 0) return 'B';
                else if (matriz[i-1].s[j+2] == 'K' && condicoes(i-1,j+2,n) == 0) return 'B';
                else if (matriz[i+1].s[j+2] == 'K' && condicoes(i+1,j+2,n) == 0) return 'B';
                else if (matriz[i+2].s[j+1] == 'K' && condicoes(i+2,j+1,n) == 0) return 'B';
                else if (matriz[i+2].s[j-1] == 'K' && condicoes(i+2,j-1,n) == 0) return 'B';
                else if (matriz[i+1].s[j-2] == 'K' && condicoes(i+1,j-2,n) == 0) return 'B';
            }
            else if (matriz[i].s[j] == 'N'){
                if (matriz[i-1].s[j-2] == 'k' && condicoes(i-1,j-2,n) == 0) return 'P';
                else if (matriz[i-2].s[j-1] == 'k' && condicoes(i-2,j-1,n) == 0) return 'P';
                else if (matriz[i-2].s[j+1] == 'k' && condicoes(i-2,j+1,n) == 0) return 'P';
                else if (matriz[i-1].s[j+2] == 'k' && condicoes(i-1,j+2,n) == 0) return 'P';
                else if (matriz[i+1].s[j+2] == 'k' && condicoes(i+1,j+2,n) == 0) return 'P';
                else if (matriz[i+2].s[j+1] == 'k' && condicoes(i+2,j+1,n) == 0) return 'P';
                else if (matriz[i+2].s[j-1] == 'k' && condicoes(i+2,j-1,n) == 0) return 'P';
                else if (matriz[i+1].s[j-2] == 'k' && condicoes(i+1,j-2,n) == 0) return 'P';
            }
        }
    }
    return 'N';
}

/* Recebe a matriz e seu tamanho e retorna, de acordo exclusivamente com a torre,
  "B" se o rei branco esta em cheque, "P" se o rei preto esta em cheque ou "N" se nenhum esta */
char verifica_torre (caracteres *matriz, int n){

    int i, j, k;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (matriz[i].s[j] == 'r'){
                for (k = j+1; k < n; k++){
                    if (matriz[i].s[k] == 'K') return 'B';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = j-1; k >= 0; k--){
                    if (matriz[i].s[k] == 'K') return 'B';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = i+1; k < n; k++){
                    if (matriz[k].s[j] == 'K') return 'B';
                    else if (matriz[k].s[j] != '.') break;
                }
                for (k = i-1; k >= 0; k--){
                    if (matriz[k].s[j] == 'K') return 'B';
                    else if (matriz[k].s[j] != '.') break;
                }
            }
            else if (matriz[i]. s[j] == 'R'){
                for (k = j+1; k < n; k++){
                    if (matriz[i].s[k] == 'k') return 'P';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = j-1; k >= 0; k--){
                    if (matriz[i].s[k] == 'k') return 'P';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = i+1; k < n; k++){
                    if (matriz[k].s[j] == 'k') return 'P';
                    else if (matriz[k].s[j] != '.') break;
                }
                for (k = i-1; k >= 0; k--){
                    if (matriz[k].s[j] == 'k') return 'P';
                    else if (matriz[k].s[j] != '.') break;
                }
            }
        }
    }
    return 'N';
}

/* Recebe a matriz e seu tamanho e retorna, de acordo exclusivamente com o bispo,
  "B" se o rei branco esta em cheque, "P" se o rei preto esta em cheque ou "N" se nenhum esta */
char verifica_bispo (caracteres *matriz, int n){

    int i, j, k, l;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (matriz[i].s[j] == 'b'){
                l = i + 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
                l = i + 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
            }
            else if (matriz[i].s[j] == 'B'){
                l = i + 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
                l = i + 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
            }
        }
    }
    return 'N';
}

/* Recebe a matriz e seu tamanho e retorna, de acordo exclusivamente com a rainha,
  "B" se o rei branco esta em cheque, "P" se o rei preto esta em cheque ou "N" se nenhum esta */
char verifica_rainha (caracteres *matriz, int n){

    int i, j, k, l;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (matriz[i].s[j] == 'q'){
                l = i + 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
                l = i + 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'K' && condicoes(l, k, n) == 0) return 'B';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
                for (k = j+1; k < n; k++){
                    if (matriz[i].s[k] == 'K') return 'B';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = j-1; k >= 0; k--){
                    if (matriz[i].s[k] == 'K') return 'B';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = i+1; k < n; k++){
                    if (matriz[k].s[j] == 'K') return 'B';
                    else if (matriz[k].s[j] != '.') break;
                }
                for (k = i-1; k >= 0; k--){
                    if (matriz[k].s[j] == 'K') return 'B';
                    else if (matriz[k].s[j] != '.') break;
                }
            }
            else if (matriz[i].s[j] == 'Q'){
                l = i + 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j+1; k < n; k++){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
                l = i + 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l++;
                }
                l = i - 1;
                for (k = j-1; k < n; k--){
                    if (matriz[l].s[k] == 'k' && condicoes(l, k, n) == 0) return 'P';
                    else if (matriz[l].s[k] != '.') break;
                    l--;
                }
                 for (k = j+1; k < n; k++){
                    if (matriz[i].s[k] == 'k') return 'P';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = j-1; k >= 0; k--){
                    if (matriz[i].s[k] == 'k') return 'P';
                    else if (matriz[i].s[k] != '.') break;
                }
                for (k = i+1; k < n; k++){
                    if (matriz[k].s[j] == 'k') return 'P';
                    else if (matriz[k].s[j] != '.') break;
                }
                for (k = i-1; k >= 0; k--){
                    if (matriz[k].s[j] == 'k') return 'P';
                    else if (matriz[k].s[j] != '.') break;
                }
            }
        }
    }
    return 'N';
}

// Recebe a matriz e seu tamanho e retorna 1 se todos os elementos dela forem iguais a “.” e 0 se não
int verifica_tabuleiro(caracteres *matriz, int n){

    int i, j, aux = 0;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (matriz[i].s[j] != '.'){
                aux++;
            }
        }
    }

    if (aux == 0){
        return 1;
    }

    return 0;
}

int main(){

    int  n = 8, i, j, jogo = 0;
    caracteres tabuleiro[n];

    while (1){

        jogo++;

        for (i = 0; i < n; i++){
                fflush(stdin);
                scanf("%s", &tabuleiro[i].s);
        }

        if (verifica_tabuleiro(tabuleiro, n) == 1) break;

        if (verifica_peao(tabuleiro, n) == 'P' || verifica_cavalo(tabuleiro, n) == 'P' || verifica_torre(tabuleiro, n) == 'P' || verifica_bispo(tabuleiro, n) == 'P' || verifica_rainha(tabuleiro, n) == 'P'){
            printf ("Jogo #%d: rei preto esta em cheque.\n", jogo);
        }
        else if (verifica_peao(tabuleiro, n) == 'B' || verifica_cavalo(tabuleiro, n) == 'B' || verifica_torre(tabuleiro, n) == 'B' || verifica_bispo(tabuleiro, n) == 'B' || verifica_rainha(tabuleiro, n) == 'B'){
            printf ("Jogo #%d: rei branco esta em cheque.\n", jogo);
        }
        else {
            printf ("Jogo #%d: nenhum rei esta em cheque.\n", jogo);
        }

    }

return 0;
}