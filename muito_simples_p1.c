#include <stdio.h>
#include <math.h>

// Recebe as coordenadas de dois pontos e retorna a distancia entre elas
float distancia(float ax, float ay, float bx, float by){

    float dist;

    dist = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));

    return dist;
}

int main (){

    float Ax, Ay, Bx, By;

    printf ("Digite as coordenadas:\n");
    printf ("Ax: ");
    scanf ("%f", &Ax);
    printf ("Ay: ");
    scanf ("%f", &Ay);
    printf ("Bx: ");
    scanf ("%f", &Bx);
    printf ("By: ");
    scanf ("%f", &By);

    printf("\nDistancia = %.4f\n", distancia(Ax, Ay, Bx, By));

return 0;
}
