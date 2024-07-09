#include <stdio.h>
#include <omp.h>

// LASTPRIVATE: Especifica que a versão da variável do contexto delimitador é definida 
// como a versão privada de qualquer thread que execute a iteração final (constructo for-loop)
// ou a última seção (seções #pragma).

// Aplica-se somente às diretivas 'for' e 'sections'

int main(int argc, char *argv[]){

    int fim = 10;
    int soma = 5;

    printf("Antes da regiao paralela: Valor inicial de x: %d\n", soma);

    #pragma omp parallel for lastprivate(soma) // Pega o valor de 'soma' da última iteração
    for (int i = 0; i < fim; i++) {
        soma = i + 1;
        int id = omp_get_thread_num();
        printf("Paralela - Thread id = %d e (soma = i + 1) = %d \n", id, soma); 
    }

    printf("Depois da regiao paralela: Valor final de x: %d\n", soma);

    return 0;
}
