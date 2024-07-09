// Windows
#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h>
#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

// Especifica se um loop deve ser executado em paralelo ou série

int main(int argc, char *argv[]){
    srand((unsigned) time(0));
    int random = rand() % (10 - 0 + 1) + 0;
    printf("Numero gerado: %d\n", random);

    // Se o número gerado for maior 5, executará a região de forma paralela.
    // Caso contrário, executará de forma serial.
    #pragma omp parallel if(random > 5)
    {
        printf("Executando regiao...\n");
    }
    printf("Fim da execucao...\n");
    return 0;
}
