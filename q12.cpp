// Windows
#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h>  

// Especifica que uma ou mais variáveis privadas para cada thread são objeto de uma operação de redução no final da região paralela.

int main(int argc, char *argv[]){
	int num = 1;
    printf("Valor da variavel privada inicical: %d \n", num);
    
    // Após cada thread chegar no final da região paralela, 
    // será realizada a multiplicação entre a variável 'num' de cada uma e vai sobrescrever a variável num com o novo valor.
    #pragma omp parallel reduction(*:num) num_threads(2)
    {
        int id = omp_get_thread_num();
        for (int i = 1; i < 2; i++){
            num = num + i;    
            printf("Valor da variavel privada dentro da thread %d: %d \n", id, num);
        }
    }
    // Novo valor
    printf("Valor da variavel privada final: %d \n", num);
    return 0;
}
