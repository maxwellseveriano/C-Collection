#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N_VAGAS 5
#define N_VAGAS_FORA 10

sem_t semaforo_estacionamento; // Semáforo para controlar o acesso ao estacionamento
sem_t semaforo_vagas_fora; // Semáforo para controlar as vagas na área de estacionamento fora

void* carro(void* arg) {
    int id_carro = *((int*)arg);
    int tempo_estacionado = rand() % 10 + 1; // Tempo aleatório de estacionamento entre 1 e 10 segundos

    // Tentar estacionar dentro do estacionamento
    if (sem_trywait(&semaforo_estacionamento) == 0) {
        printf("Carro %d estacionou no estacionamento por %d segundos.\n", id_carro, tempo_estacionado);
        sleep(tempo_estacionado); // Simula o tempo de estacionamento
        sem_post(&semaforo_estacionamento); // Libera vaga no estacionamento
    } else {
        // Caso o estacionamento esteja cheio, tenta estacionar na área fora
        if (sem_trywait(&semaforo_vagas_fora) == 0) {
            printf("Carro %d estacionou fora por %d segundos.\n", id_carro, tempo_estacionado);
            sleep(tempo_estacionado); // Simula o tempo de estacionamento fora
            sem_post(&semaforo_vagas_fora); // Libera vaga fora do estacionamento
        } else {
            printf("Carro %d não conseguiu estacionar e procurará outro estacionamento.\n", id_carro);
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    // Inicialização dos semáforos
    sem_init(&semaforo_estacionamento, 0, N_VAGAS);
    sem_init(&semaforo_vagas_fora, 0, N_VAGAS_FORA);

    pthread_t carros[20]; // Simula 20 carros tentando estacionar
    int ids_carros[20];

    // Criar threads para simular os carros
    for (int i = 0; i < 20; ++i) {
        ids_carros[i] = i + 1;
        pthread_create(&carros[i], NULL, carro, &ids_carros[i]);
        sleep(1); // Intervalo de 1 segundo entre a criação de carros
    }

    // Aguardar as threads terminarem
    for (int i = 0; i < 20; ++i) {
        pthread_join(carros[i], NULL);
    }

    // Destruir os semáforos após o término da simulação
    sem_destroy(&semaforo_estacionamento);
    sem_destroy(&semaforo_vagas_fora);

    return 0;
}
