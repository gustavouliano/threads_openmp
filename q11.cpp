// Windows
#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h>  

// Especifica que cada thread deve ter sua própria instância de uma variável e que a variável deve ser 
// inicializada com o valor da variável, pois ela existe antes do constructo paralelo.

int main(int argc, char *argv[]){
	int num = 0;
    printf("Valor da variavel privada inicical: %d \n", num);

    // Vai ser criada uma cópia da variável para cada thread com o valor inicializado.
    #pragma omp parallel firstprivate(num) num_threads(2)
    {
        int id = omp_get_thread_num();
        for (int i = 0; i < 10; i++){
            num = num + i;
            printf("Valor da variavel privada dentro da thread %d: %d \n", id, num);
        }
    }
    // Continua com o valor original
    printf("Valor da variavel privada final: %d \n", num);
    return 0;
}
