#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *lista;
    int size;
} VETOR;

VETOR* concat(VETOR *, VETOR *);

int main()
{
    VETOR vet1, vet2;

    vet1.size = 3;
    vet1.lista = (int *) malloc(vet1.size * sizeof(int));
    vet1.lista[0] = 1;
    vet1.lista[1] = 2;
    vet1.lista[2] = 3;

    vet2.size = 4;
    vet2.lista = (int *) malloc(vet2.size * sizeof(int));
    vet2.lista[0] = 4;
    vet2.lista[1] = 5;
    vet2.lista[2] = 6;
    vet2.lista[3] = 7;
   
    VETOR *vet = concat(&vet1, &vet2);

    int i;
    for(i = 0; i < vet->size; i++){
        printf("%d ", vet->lista[i]);
    }

    return 0;
}

VETOR* concat(VETOR *vet1, VETOR *vet2){
    VETOR *vetor = malloc(sizeof(VETOR));

    int tamanho = vet1->size + vet2->size;
    int i;

    vetor->lista = (int *) malloc(tamanho * sizeof(int));
    vetor->size = tamanho;

    for(i = 0; i < (tamanho - vet2->size); i++){
        vetor->lista[i] = vet1->lista[i];
    }
    for(i = vet1->size; i < tamanho; i++){
        vetor->lista[i] = vet2->lista[i - vet1->size];
    }
    return vetor;

    free(vetor);
}