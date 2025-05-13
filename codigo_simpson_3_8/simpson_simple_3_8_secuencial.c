#include <stdio.h> 
#include <math.h>
#include <time.h>

double f(double x){ // funcion a resolver e^(-x*x)
    return exp(-x * x);
}

double simpson_series_simple(double a, double b){

    double h = (b-a)/3; // definimos los sub intervalos

    double form_part_one = (3*h)/8;  // Primera parte de la formula

    double form_part_two = f(a) + 3 * f(a + h) + 3 * f(a + 2*h) + f(b); // segunda parte de la formula

    return form_part_one*form_part_two;
}

int main(int argc, char const *argv[]) {

    // medimos el tiempo
    double start_time = clock();

    double resultado = simpson_series_simple(-1,1);

    double end_time = clock();

    double time = (double)(end_time - start_time)/ CLOCKS_PER_SEC;

    // output
    printf("Resultado integral de forma secuencial: %f",resultado);
    printf("\nTiempo secuencial: %.20f",time);

    return 0;
}
