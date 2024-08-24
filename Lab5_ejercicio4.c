#include <stdio.h>
#include <omp.h>
//Funcion principal
int main(){
    //Creacion de variable compartida y privada
    int N = 10;
    int varComp = 0;
    int varPriv = 0;
    //Inicia la medicion del tiempo
    double tiempo_inicio = omp_get_wtime();

    #pragma omp parallel for shared(varComp) private(varPriv)
    //Ciclo paralelo con una variable compartida y una privada
    for(int i = 0; i < N; i++ ){
        varComp += 1;
        varPriv += 1;
    }
    //Termina la medicion del tiempo
    double tiempo_fin = omp_get_wtime();
    //Impresion de resultados y tiempo de ejecucion
    printf("Hilo numero %d, la variable compartida es %d, y la variable privada es %d, y el tiempo de ejecucion es %f\n",omp_get_thread_num(),varComp,varPriv,tiempo_fin-tiempo_inicio);
}