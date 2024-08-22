#include <stdio.h>
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
        int N;
        //Es igual a 1 porque 0! = 1
        long long factorial = 1;
        //Ingreso del numero
        printf("Ingresa un numero para calcular su factorial: ");
        scanf("%d",&N);
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
        int N;
        //Ingreso del numero
        printf("Ingresa un numero para calcular su serie de Fibonacci: ");
        scanf("%d",&N);
        //Inicia la medicion del tiempo
        double tiempo_inicio = omp_get_wtime();
        //Termina la medicion del tiempo
        double tiempo_fin = omp_get_wtime();
        //Imprime la serie de Fibonacci y el tiempo de ejecucion
        printf("La serie de Fibonacci de de %d es %d\n", N, fibonacci);
        printf("Tiempo de ejecucion: %f segundos", tiempo_fin - tiempo_inicio);
            }
        }
    }
