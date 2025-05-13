#include <stdio.h> 
#include <math.h>
#include <time.h>

double f(double x){ // funcion a resolver e^(-x*x)
    return exp(-x * x);
}

double simpson_series_multiple(double a, double b, int n){

    if((n % 3) != 0){ // verificamos que n si sea multiplo 3
        return 0;
    }else{ // si cumple resolvemos la integral

        double sum1 = 0.0, sum2 = 0.0,sum3 = 0.0, sum4 = 0.0; // definimos la variable donde se guardara la suma de cada funcion

        double h = (b-a)/n;  

        // hacemos cada sumatoria por separado 
        for(int j = 1; j<=n/3; j++){ // primer termino
            sum1 += f(a + (3*j - 3)*h);
        }

        for(int j = 1; j<=n/3; j++){ // segundo termino
            sum2 += f(a + (3*j - 2)*h);
        }

        for(int j = 1; j<=n/3; j++){ // tercer termino
            sum3 += f(a + (3*j - 1)*h);
        }

        for(int j = 1; j<=n/3; j++){ // cuarto termino
            sum4 += f(a + (3*j)*h);
        }

        double integral = (3*h/8)*(sum1 + 3*sum2 + 3*sum3 + sum4);

        return integral;

    }
}

int main(int argc, char const *argv[])
{
    // medimos el tiempo
    double start_time = clock();

    double resultado = simpson_series_multiple(-1,1,300000000);

    double end_time = clock();

    double time = (double)(end_time - start_time)/ CLOCKS_PER_SEC;
    // output
    printf("Integral por metodo de simpson 3/8 multiple: %.10f",resultado);
    printf("\nTiempo secuencial: %.10f",time);
    return 0;
}
