#include <stdio.h>  
#include <math.h>
#include <omp.h>

double f(double x){ // funcion a resolver e^(-x*x)
    return exp(-x * x);
}


double simpson_series_simple_paralelizado(double a, double b){

    double h = (b-a)/3; // definimos los sub intervalos
    double form_part_one = (3*h)/8;  // Primera parte de la formula
    
    double fx1,fx2,fx3,fx4; // separamos cada funcion para poder paralelizar

    # pragma omp parallel sections // hacemos que cada hilo resuelva una funcion
    { 

        #pragma omp section 
        fx1 = f(a);

        #pragma omp section
        fx2 = f(a + h);

        #pragma omp section
        fx3 = f(a + (2*h));

        #pragma omp section
        fx4 = f(b);
    }

    return form_part_one*(fx1 + 3*fx2 + 3*fx3 + fx4); // formula completa
    }


int main(int argc, char const *argv[]) {
    omp_set_num_threads(16); // definimos el numero de hilos 

    // tomamos el tiempo 
    double start_time = omp_get_wtime();  // tiempo de inicio

    double resultado = simpson_series_simple_paralelizado(-1,1);

    double end_time = omp_get_wtime();  // tiempo final

    printf("Resultado integral con paralelizacion: %f",resultado);
    printf("\nTiempo con paralelizacion: %.20f",end_time-start_time);


   

    return 0;
}
