#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializando o gerador de números aleatórios
    srand(time(0));

    // Abrindo o arquivo
    FILE *file = fopen("entrada.txt", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    int l1[102];
    int l2[102];
    int l3[102];
    int n;
    // Gerando e escrevendo os números
    fscanf(file, "%d", &n);
    for (int i = 0; i < 100; i++) {
        
        fscanf(file, "%d %d", &l2[i], &l3[i]);
        l1[i] = i+1;
    }

    FILE *file2 = fopen("fifo.txt", "w");
    fprintf(file2, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file2, "%d ", l1[i]);
    }fprintf(file2, "\n");
    for (int i = 0; i < n; i++) {
        fprintf(file2, "%d ", l2[i]);
    }fprintf(file2, "\n");
    for (int i = 0; i < n; i++) {
        fprintf(file2, "%d ", l3[i]);
    }

    // Fechando o arquivo
    fclose(file);

    return 0;
}
