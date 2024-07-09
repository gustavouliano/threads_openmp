// Windows
#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h>  

// Especifica que uma ou mais variáveis devem ser compartilhadas entre as threads.

int main(int argc, char *argv[]){
	int num = 0;
    printf("Valor da variavel compartilhada inicical: %d \n", num);
    
    // As threads poderão alterar a variável compartilhada.
    #pragma omp parallel shared(num) num_threads(2)
    {
        int id = omp_get_thread_num();
        for (int i = 0; i < 10; i++){
            num = i;    
            printf("Valor da variavel compartilhada dentro da thread %d: %d \n", id, num);
        }
    }
    // Valor final da variável alterada pelas threadas
    printf("Valor da variavel compartilhada final: %d \n", num);
    return 0;
}
