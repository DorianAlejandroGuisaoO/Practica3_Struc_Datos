#include <stdio.h>
#include <math.h>
#include <sys/time.h>  

// Definimos nuestra función: e^[-x^2]
double f(double x) {
    return exp(-x * x);
}

// Código secuencial para el método de Simpson 1/3.
double simpson_secuen(double a, double b, int n) {
    // Calculamos el ancho de cada subintervalo.
    double h = (b - a) / n;

    // Inicializamos las sumas de los subintervalos pares e impares.
    double sum_pares = 0.0, sum_impares = 0.0;
    
    // Calculamos la suma de todos los términos de los subintervalos pares.
     for (int i = 2; i <= n - 2; i += 2) {
        sum_pares += f(a + i * h);
    }

    // Calculamos la suma de todos los términos de los subintervalos impares.
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

    // Medimos el tiempo de ejecución secuencialmente
    double start1 = get_time();
    double resul_secuen = simpson_secuen(a, b, n);
    double end1 = get_time();
    double tiempo_secuencial = end1 - start1;

    // Imprimimos los resultados. 
    printf("Número de subintervalos (n) = %lld\n", n);
    printf("Resultado secuencial: %f\n", resul_secuen);
    printf("Tiempo secuencial: %f segundos\n", tiempo_secuencial);

}