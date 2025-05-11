#include <stdio.h>
#include <math.h> // Para poder definir nuestra función

// Definimos nuestra función: e^[-x^2]
double f(double x) {
    return exp(-x * x);
}

// Función para aplicar la fórmula del método de Simpson 1/3 simple
double simpson_simple(double a, double b) {

    int n = 2; // Como se dijo anteriormente aqui 'n' es siempre 2.
    double h = (b - a) / n; // Calculamos el ancho del subintervalos central.
    double a_sum_h = a + h;

    // Aplicamos la fórmula de Simpson 1/3 simple para calcular en valor de aprox de I. 
    double resul_I = (1.0 / 3.0) * h * (f(a) + 4 * f(a_sum_h) + f(b));  
    return resul_I;
}


// Función principal
int main() {
    double a = -1.0, b = 1.0; // Definimos los limites de integración

    // Calculamos el valor aprox de I con el método de Simpson Simple.
    double r_simp_simple = simpson_simple(a, b);
    
    // Imprimimos el resultado de I. 
    printf("Resultado Simpson simple = %.15f\n", r_simp_simple); 
    return 0;
}