#include <stdio.h>
#include <omp.h>

// Cláusula 'default': Especifica o comportamento de variáveis sem escopo em uma região paralela. 
// Por padrão, as variáveis são compartilhadas.
// Se você usa '#pragma omp parallel default(none)' você necessita especificar as variáveis privadas e as variáveis compartilhadas.

int main() {
    int privada = 5; 
    int compartilhada = 0; 

    // Aqui, como não há padrão definido, é necessário definir como será trabalhado com cada variável.
    #pragma omp parallel default(none) shared(compartilhada) private(privada)
    {
        int id = omp_get_thread_num();
        privada += id;
        compartilhada += id;
        printf("Thread %d: compartilhada = %d\n", id, compartilhada);
        printf("Thread %d: privada = %d\n", id, privada);
    }

    printf("Valor final de variavel compartilhada: %d\n", compartilhada);
    printf("Valor final da variavel privada: %d\n", privada);

    return 0;
}
