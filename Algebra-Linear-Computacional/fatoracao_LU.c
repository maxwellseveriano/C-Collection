#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double** geraMatriz(int, int);
double*  geraVetor(int);
void imprime(double **, int);
void imprimev(double *, int );

int main(){
	
	int i, j, k, l, m;
	int n = 20;
	double temp;
	
	double** A = geraMatriz(n + 1, 1);
	double** U = geraMatriz(n + 1, 1);
	double** L = geraMatriz(n + 1, 0);
	double*  b = geraVetor(n + 1);
	printf("Matriz A original:\n");
	imprime(A, n + 1);
	
	for(k = 0; k < n; k++){
		for(i = k + 1; i <= n; i++){
			int i_t = k;
			for(l = k + 1; l <= n; l++){
				if(abs(U[i_t][k]) < abs(U[l][k])){
					i_t = l;
				}
			}
			int i_c = k;
			for(l = k + 1; l <= n; l++){
				if(abs(U[i_c][k]) < abs(U[k][l])){
					i_c = l;
				}
			}
			if(i_t != k || i_c != k){
				if(U[i_t][k] >= U[k][i_c]){
					for(j = 0; j <= n; j++){
						temp = U[k][j];
						U[k][j] = U[i_t][j];
						U[i_t][j] = temp;
					}
					temp = b[k];
					b[k] = b[i_t];
					b[i_t] = temp;
				}
				else{
					for(j = 0; j <= n; j++){
						temp = U[j][k];
						U[j][k] = U[j][i_c];
						U[j][i_c] = temp;
					}
				}
			}
			for(j = k + 1; j <= n; j++){
				L[j][k] = -U[j][k] / U[k][k];
				for(m = k; m <= n; m++){
					L[m][m] = 1;
					U[j][m] = U[j][m] + L[j][k] * U[k][m];
				}
			}
		}
	}
	
	for(i = 0; i <= n; i++){
		for(j = 0; j <=n; j++){
			if(i <= j)
				A[i][j] = U[i][j];
			else
				A[i][j] = L[i][j];
		}
	}
	
	printf("Matriz L:\n");
	imprime(L, n + 1);
	printf("Matriz U:\n");
	imprime(U, n + 1);
	printf("Matriz A(LU):\n");
	imprime(A, n + 1);
	imprimev(b, n + 1);
	
	return 0;
}

double** geraMatriz(int n, int x){
	int i, j, aux = 0;
	double** matriz1;
	
	matriz1 = (double **) malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        matriz1[i] = (double *) malloc(n * sizeof(double));
    }
    if(x == 0){
    	for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				matriz1[i][j] = 0;
			}
		}
		return matriz1;
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matriz1[i][j] = abs(j - i);
		}
	}
	return matriz1;
}
double* geraVetor(int n){
	int i, j, aux = 0;
	double* matriz1;
	
	matriz1 = (double *) malloc(n * sizeof(double *));
    
	for(i = 0; i < n; i++){
		matriz1[i] = i + 1;
	}
	return matriz1;
}
void imprime(double ** matriz, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%4.1f ", matriz[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}
void imprimev(double *vetor, int n){
	printf("\nb = [ ");
	for(int i = 0; i < n; i++){
		printf("%.1f ", vetor[i]);
	}
	printf("]\n\n");
}
void cria_vetor(int v[], int n){
	for(int i = 0; i < n; i++){
		v[i] = i;
	}
}
