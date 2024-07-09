#include <stdio.h>
#include <omp.h>

// LASTPRIVATE: Especifica que a versão da variável do contexto delimitador é definida 
// como a versão privada de qualquer thread que execute a iteração final (constructo for-loop)
// ou a última seção (seções #pragma).

// Aplica-se somente às diretivas 'for' e 'sections'


int main(int argc, char *argv[]){

    int result = 0;
    printf("Valor inicial de result: %d\n", result);

    #pragma omp parallel sections lastprivate(result) // Pegar valor da última section
    {
        #pragma omp section
        {
            result = 42; 
            printf("\nSection 1: Valor de result = %d\n", result);
        }

        #pragma omp section
        {
            result = 7; 
            printf("Section 2: Valor de result = %d\n", result);
        }
        #pragma omp section
        {
            result = 100; 
            printf("Section 3: Valor de result = %d\n", result);
        }
    }

    printf("\nValor final de result: %d\n", result);
    return 0;
}
