#include <stdio.h>
#include <omp.h>
    //Funcion principal
int main() {
    //Variable para numero de iteraciones.
    int N;
    // Variable para acumular la suma
    long long suma = 0;
    //Ingreso de valor para N
    printf("Ingresa el numero de iteraciones, recomiendo usar un numero muy grande: ");
    scanf("%d", &N);
    // Inicia la medición del tiempo
    double tiempo_inicio = omp_get_wtime();

    // Ciclo paralelo para calcular la suma de los primeros N números naturales
    #pragma omp parallel for reduction(+:suma)
    for (int i = 1; i <= N; i++) {
        #pragma omp atomic
        suma += i;
    }
    // Termina la medición del tiempo
    double tiempo_fin = omp_get_wtime();
    // Imprime la suma y el tiempo de ejecución
    printf("La suma de los primeros %d numeros naturales es: %d\n", N, suma);
    printf("Tiempo de ejecucion: %f segundos\n", tiempo_fin - tiempo_inicio);

    return 0;
}