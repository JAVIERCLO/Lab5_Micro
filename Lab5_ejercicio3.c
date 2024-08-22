#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

    //Funcion para calcular la serie de Fibonacci
    int fibonacci (int N){
        if (N == 0){
            return 0;
        }
        else if (N == 1){
            return 1;
        }
        else{
            return fibonacci(N - 1) + fibonacci(N - 2);
        }
    }
    //Funcion principal
    int main(){

    //Inicio de paralelizacion
    #pragma omp sections
    {
    //Seccion 1: Calcular el factorial de un numero
        #pragma omp section
            {
                //Numero a calcular
                int N = 100000;
                //Es igual a 1 porque 0! = 1
                unsigned long long factorial = 1;
                //Inicia la medicion del tiempo
                double tiempo_inicio = omp_get_wtime();
                //Ciclo for para calcular el factorial
                for(int i = 1; i <= N; i++){
                        factorial *=i;
                    }
                // Termina la medicion del tiempo
                double tiempo_fin = omp_get_wtime();
                //Imprime el factorial y el tiempo de ejecucion
                printf("El factorial de %d es %d\n", N, factorial);
                printf("Tiempo de ejecucion: %f segundos\n", tiempo_fin - tiempo_inicio);
            }
        //Seccion 2: Calcular una serie de Fibonacci
        #pragma omp section
            {
                //Numero a calcular
                int N = 1000000;
                //Inicia la medicion del tiempo
                double tiempo_inicio = omp_get_wtime();
                //Termina la medicion del tiempo
                
                double tiempo_fin = omp_get_wtime();
                //Imprime la serie de Fibonacci y el tiempo de ejecucion
                printf("La serie de Fibonacci de de %d es %d\n", N, fibonacci);
                printf("Tiempo de ejecucion: %f segundos\n", tiempo_fin - tiempo_inicio);
            }
        // Seccion 3: Encontrar el maximo de un arreglo
        #pragma omp section
            {
                // Longitud del arreglo
                int L = 1000000;
                printf("Calculando el maximo de un arreglo de %d elementos:\n", L);
                // Inicia la medicion del tiempo
                double tiempo_inicio = omp_get_wtime();
                // Arreglo utilizando malloc
                int *array = (int *)malloc(L * sizeof(int));
                //Llenar el arreglo con valores aleatorios
                for (size_t i = 0; i < L; i++){
                    array[i] = rand();
                }
                // Asignar un valor maximo inicial
                int max = array[0];
                // Ciclo para comparar los valores del arreglo hasta encontrar el maximo
                for (int i = 1; i < L; i++){
                    if (array[i] > max){
                        max = array[i];
                    }
                }
                // Termina la medicion del tiempo
                double tiempo_fin = omp_get_wtime();
                // Imprime el maximo del arreglo y el tiempo de ejecucion
                printf("El maximo del arreglo es: %d y el tiempo de ejecucion es: %f segundos\n", max, tiempo_fin - tiempo_inicio);
                // Liberar memoria
                free(array);
            }
        }
    }
