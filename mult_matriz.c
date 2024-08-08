#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <pthread.h>

void matriz_mult(int n, int**, int**);
int** gerar_matriz_aleatoria(int);
int** gerar_matriz_zero(int);

int main()
{
    clock_t start, end;
    double execution_time;
    start = clock();

	int n = 600;
	
	int **matriz1 = gerar_matriz_aleatoria(n);
	int **matriz2 = gerar_matriz_aleatoria(n);
	
	matriz_mult(n, matriz1, matriz2);
	
	/*for (i = 0; i < n; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
    }
    free(matriz1);
    free(matriz2);*/
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Tempo: %lf", execution_time);

    return 0;
}
void matriz_mult(int n, int **matriz1, int **matriz2)
{
	
	
	int i, j, k;
	int **matriz3 = gerar_matriz_zero(n);

    #pragma omp parallel for 
    
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                for(k=0; k<n; k++){
                    matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
    
    
	
	/*for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ", matriz3[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
        free(matriz3[i]);
    }
    free(matriz3);*/
    
    
}
int** gerar_matriz_aleatoria(int n)
{
	int **matriz;
    int i, j;

    matriz = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *) malloc(n * sizeof(int));
    }
    
    srand(time(NULL));
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            matriz[i][j] = rand() % 100;
        }
    }
    return matriz;
}
int** gerar_matriz_zero(int n)
{
	int **matriz;
    int i, j;

    matriz = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *) malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            matriz[i][j] = 0;
        }
    }
    
    return matriz;
}
