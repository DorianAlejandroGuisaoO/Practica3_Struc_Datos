#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>  


// Definimos nuestra función: e^[-x^2]
double f(double x) {
    return exp(-x * x);
}

// Paralelizamos el código secuencial para el método de Simpson 1/3 simple.
double simpson_paralelo(double a, double b, int n) {
    // Calculamos el ancho de cada subintervalo.
    double h = (b - a) / n;

    // Inicializamos las sumas de los subintervalos pares e impares.
    double sum_pares = 0.0, sum_impares = 0.0;
    
    // Paralelizamos el cálculo de todos los términos de los subintervalos pares.
    #pragma omp parallel for reduction(+:sum_pares)
    for (int i = 2; i <= n - 2; i += 2) {
        sum_pares += f(a + i * h);
    }

    // Paralelizamos el cálculo de todos los términos de los subintervalos impares.
    #pragma omp parallel for reduction(+:sum_impares)
    for (int i = 1; i <= n - 1; i += 2) {
        sum_impares += f(a + i * h);
    }

    // Aplicamos la fórmula de Simpson 1/3 y calculamos el valor aproximado de I.
    double resultado_I = h / 3 * (f(a) + 4 * sum_impares + 2 * sum_pares + f(b));
    return resultado_I;
}

// Función para obtener el tiempo en segundos usando gettimeofday
double get_time() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec / 1000000.0;  // Retorna el tiempo en segundos con precisión de microsegundos
}

// Función principal. 
int main() {
    // Definimos los límites inferior (a) y superior (b).
    double a = -1.0, b = 1.0;
    int n = 2000000000; // Definimos 'n' subintervalos.

    // Establecemos el número de hilos a usar para el cálculo en paralelo.     
    omp_set_num_threads(12); 

    // Medimos el tiempo de ejecución con paralelización
    double start2 = get_time();
    double resul_paralelo = simpson_paralelo(a, b, n);
    double end2 = get_time();
    double tiempo_paralelo = end2 - start2;

    // Imprimimos los resultados.
    printf("Número de subintervalos (n) = %lld\n", n); 
    printf("Resultado paralelo:   %f\n", resul_paralelo);
    printf("Tiempo paralelo:   %f segundos\n", tiempo_paralelo);

}




