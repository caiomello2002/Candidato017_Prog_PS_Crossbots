#include <stdio.h>

// Recebe a temperatura em Fahrenheit e a retorna em Celsius
float converte_temperatura (float f){

    float c;

    c = (f - 32)*5/9;

    return c;
}

int main(){

    float temp_f;

    printf ("Temperatura em Fahrenheit: ");
    scanf ("%f", &temp_f);

    printf ("\nTemperatura em Celsius: %.2f\n", converte_temperatura(temp_f));

return 0;
}
