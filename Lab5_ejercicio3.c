#include <stdio.h>
#include <omp.h>

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
        // Termina la medición del tiempo
        double tiempo_fin = omp_get_wtime();
        //Imprime el factorial y el tiempo de ejecucion
        printf("El factorial de %d es %d\n", N, factorial);
        printf("Tiempo de ejecucion: %f segundos", tiempo_fin - tiempo_inicio);
        }
    //Seccion 2
    #pragma omp section
        {
        
        }
    }
}