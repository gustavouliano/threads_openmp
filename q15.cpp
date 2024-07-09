// Windows
#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h>
#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;


int main(int argc, char *argv[]){
    srand((unsigned) time(0));
    int num_threads, inicio_random, fim_random;
    printf("Digite o numero de threads:\n");
    cin >> num_threads;
    printf("Digite o inicio dos numeros aleatorios:\n");
    cin >> inicio_random;
    printf("Digite o fim dos numeros aleatorios:\n");
    cin >> fim_random;
    #pragma omp parallel num_threads(num_threads)
    {
        int id = omp_get_thread_num();
        for(int i = 0; i < 10; i++){
            int random = rand() % (fim_random - inicio_random + 1) + inicio_random;
            printf("Thread ID %d gerou o numero %d\n", id, random); 
        }
    }
    printf("Fim da regiao paralela");
    return 0;
}
