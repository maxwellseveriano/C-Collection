#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define N_VAGAS 3
#define N_VAGAS_FORA 10

HANDLE semaforo_estacionamento; // Semáforo para controlar o acesso ao estacionamento
HANDLE semaforo_vagas_fora; // Semáforo para controlar as vagas na área de estacionamento fora

DWORD WINAPI carro(LPVOID lpParam) {
    int id_carro = *((int*)lpParam);
    int tempo_estacionado = rand() % 10 + 1; // Tempo aleatório de estacionamento entre 1 e 10 segundos

    // Tentar estacionar dentro do estacionamento
    if (WaitForSingleObject(semaforo_estacionamento, 0) == WAIT_OBJECT_0) {
        printf("Carro %d estacionou no estacionamento por %d segundos.\n", id_carro, tempo_estacionado);
        Sleep(tempo_estacionado * 1000); // Simula o tempo de estacionamento
        ReleaseSemaphore(semaforo_estacionamento, 1, NULL); // Libera vaga no estacionamento
    } else {
        // Caso o estacionamento esteja cheio, tenta estacionar na área fora
        if (WaitForSingleObject(semaforo_vagas_fora, 0) == WAIT_OBJECT_0) {
            printf("Carro %d estacionou fora por %d segundos.\n", id_carro, tempo_estacionado);
            Sleep(tempo_estacionado * 1000); // Simula o tempo de estacionamento fora
            ReleaseSemaphore(semaforo_vagas_fora, 1, NULL); // Libera vaga fora do estacionamento
        } else {
            printf("Carro %d não conseguiu estacionar e procurará outro estacionamento.\n", id_carro);
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));

    // Inicialização dos semáforos
    semaforo_estacionamento = CreateSemaphore(NULL, N_VAGAS, N_VAGAS, NULL);
    semaforo_vagas_fora = CreateSemaphore(NULL, N_VAGAS_FORA, N_VAGAS_FORA, NULL);

    HANDLE carros[20]; // Simula 20 carros tentando estacionar
    int ids_carros[20];

    // Criar threads para simular os carros
    for (int i = 0; i < 20; ++i) {
        ids_carros[i] = i + 1;
        carros[i] = CreateThread(NULL, 0, carro, &ids_carros[i], 0, NULL);
        Sleep(1000); // Intervalo de 1 segundo entre a criação de carros
    }

    // Aguardar as threads terminarem
    WaitForMultipleObjects(20, carros, TRUE, INFINITE);

    // Fechar handles das threads após o término da simulação
    for (int i = 0; i < 20; ++i) {
        CloseHandle(carros[i]);
    }

    // Fechar semáforos após o término da simulação
    CloseHandle(semaforo_estacionamento);
    CloseHandle(semaforo_vagas_fora);

    return 0;
}
