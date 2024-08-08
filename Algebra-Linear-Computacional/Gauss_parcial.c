#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double** geraMatriz(int);
double*  geraVetor(int);
void imprime(double **, double*, int);

int main(){
	
	int i, j, k, l, m;
	int n = 20;
	double pivo, temp;
	
	double** A = geraMatriz(n + 1);
	double*  b = geraVetor(n + 1);
	
	for(k = 0; k < n; k++){
		for(i = k + 1; i <= n; i++){
			int i_t = k;
			for(l = k + 1; l <= n; l++){
				if(abs(A[i_t][k]) < abs(A[l][k])){
					i_t = l;
				}
			}
			if(i_t != k){
				for(j = 0; j <= n; j++){
					temp = A[k][j];
					A[k][j] = A[i_t][j];
					A[i_t][j] = temp;
				}
				temp = b[k];
				b[k] = b[i_t];
				b[i_t] = temp;
			}
			for(j = k + 1; j <= n; j++){
				pivo = -A[j][k] / A[k][k];
				for(m = k; m <= n; m++){
					A[j][m] = A[j][m] + pivo * A[k][m];
				}
				b[j] += pivo * b[k];
			}
		}
	}
	double res_sis[n];
	memset(res_sis, 0, n);
	
	for( i = n; i >= 0; i--){
		temp = b[i];
		for(j = n; j >= i; j--){
			temp += -A[i][j] * res_sis[j]; 
		}
		res_sis[i] = temp / A[i][i];
	}
	imprime(A, b, n + 1);
	
	for(i = 0; i <= n; i++){
		printf("x%-2d = %19.16lf\n", i + 1, res_sis[i]);
	}

	return 0;
}

double** geraMatriz(int n){
	int i, j, aux = 0;
	double** matriz1;
	
	matriz1 = (double **) malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        matriz1[i] = (double *) malloc(n * sizeof(double));
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
void imprime(double ** matriz, double* vetor, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%4.1f ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\nb = [ ");
	for(i = 0; i < n; i++){
		printf("%.1f ", vetor[i]);
	}
	printf("]\n\n");
}
