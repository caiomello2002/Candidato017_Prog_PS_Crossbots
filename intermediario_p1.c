// Candidato 017
// Problema intermediario 1

#include <stdio.h>
#include <math.h>

float angle_ABC (float Ax,float Ay,float Bx,float By,float Cx,float Cy){

    float a_radians, a_degrees;

    a_radians = acos((Bx*Bx+By*By-Ax*Bx+Ax*Cx-Bx*Cx-Ay*By+Ay*Cy-By*Cy)/(sqrt((Bx-Ax)*(Bx-Ax)+(By-Ay)*(By-Ay))*sqrt((Cx-Bx)*(Cx-Bx)+(Cy-By)*(Cy-By))));
    a_degrees = (180.0/M_PI)*a_radians;

    return (a_degrees);
}


int main(){

    float Ax, Ay, Bx, By, Cx, Cy, angle;

    printf("Digite as coordenadas de 3 pontos:\n\n");
    printf("Ponto A:\n x: ");
    scanf("%f", &Ax);
    printf(" y: ");
    scanf("%f", &Ay);
    printf("Ponto B:\n x: ");
    scanf("%f", &Bx);
    printf(" y: ");
    scanf("%f", &By);
    printf("Ponto C:\n x: ");
    scanf("%f", &Cx);
    printf(" y: ");
    scanf("%f", &Cy);


    angle = angle_ABC (Ax, Ay, Bx, By, Cx, Cy);

    printf("\nO angulo ABC eh %.2f graus!\n", angle);

return 0;
}
