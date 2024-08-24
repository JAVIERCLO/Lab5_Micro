//Ejericicio 5A version paralela
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 131072

long count_key(long Nlen, long *a, long key) {
    long count = 0;
//Inicio de paralelizacion
    #pragma omp parallel
    {
        long local_count = 0;
        //Ciclo for paralelo
        #pragma omp for
        for (int i = 0; i < Nlen; i++) {
            if (a[i] == key) {
                local_count++;
            }
        }
        // Sumar el resultado local de cada hilo a count
        #pragma omp atomic
        count += local_count;
    }
    return count;
}
//Funcion principal
int main() {
    long a[N], key = 42, nkey = 0;
    //Inicia la medicion del tiempo
    double tiempo_inicio = omp_get_wtime();
    // Inicializar el vector con valores aleatorios
    for (long i = 0; i < N; i++) a[i] = rand() % N;
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;
    //Termina la medicion del tiempo
    double tiempo_fin = omp_get_wtime();
    // Llamada a la función paralela
    nkey = count_key(N, a, key);
    //Impresion de resultados y tiempo de ejecucion
    printf("Numero de veces que 'key' aparece paralelamente: %ld y el tiempo de ejecucion es: %f\n", nkey,tiempo_fin-tiempo_inicio);
    return 0;
}


