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
    srand(static_cast<unsigned>(time(0)));
    int num_usuario;
    printf("Digite um valor:\n");
    cin >> num_usuario;
    #pragma omp parallel num_threads(num_usuario)
    {
        int id = omp_get_thread_num();
        for(int i = 0; i < 10; i++){
            int random = rand() % 1001;
            printf("Thread ID %d gerou o numero %d\n", id, random); 
        }
    }
    printf("Fim da regiao paralela");
    return 0;
}
