// Windows
#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h>  

// Especifica que cada thread deve ter a própria instância da variável.

int main(int argc, char *argv[]){
	int num = 0;
    printf("Valor da variavel privada inicical: %d \n", num);
    
    // Cada thread vai criar um cópia da variável num, sem alterar a variável original. Ela precisa ser inicializa dentro do código paralelo
    #pragma omp parallel private(num) num_threads(2)
    {
        int id = omp_get_thread_num();
        for (int i = 0; i < 10; i++){
            num = i;    
            printf("Valor da variavel privada dentro da thread %d: %d \n", id, num);
        }
    }
    // Continua com o valor original
    printf("Valor da variavel privada final: %d \n", num);
    return 0;
}
