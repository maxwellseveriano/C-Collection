#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double** geraMatriz(int, int);
double*  geraVetor(int);
void imprime(double **, double*, int);
void cria_vetor(int[], int);

int main(){
	
	int i, j, k, l, m;
	int n = 20, temp2;
	double pivo, total, temp;
	int aux[21];
	cria_vetor(aux, n+1);
	
	double** A = geraMatriz(n + 1, 0);
	double** U = geraMatriz(n + 1, 1);
	double** L = geraMatriz(n + 1, 0);
	double*  b = geraVetor(n + 1);
	
	for(k = 0; k < n; k++){
		for(i = k + 1; i <= n; i++){
			int i_t = k;
			for(l = k + 1; l <= n; l++){
				if(abs(U[i_t][k]) < abs(U[l][k])){
					i_t = l;
				}
			}
			if(i_t != k){
				for(j = 0; j <= n; j++){
					temp = U[k][j];
					U[k][j] = U[i_t][j];
					U[i_t][j] = temp;
				}
				temp = b[k];
				b[k] = b[i_t];
				b[i_t] = temp;
			}
			for(j = k + 1; j <= n; j++){
				pivo = -U[j][k] / U[k][k];
				for(m = k; m <= n; m++){L[m][m] = 1;
					U[j][m] = U[j][m] + pivo * U[k][m];
				}
				b[j] += pivo * b[k];
			}
		}
	}
	
	double res_sis[n];
	double y[n];
	memset(res_sis, 0, n);
	memset(y, 0, n);
	
	for(i = 0; i <= n; i++){
		double total = 0;
		for(j = 0; j <= i; j++){
			total += L[i][j] * y[j]; 
		}
		y[i] = (b[i] - total) / L[i][i];
	}
	for(i = n; i >= 0; i--){
		double total = 0;
		for(j = i+1; j <=n; j++){
			total += U[i][j] * res_sis[j]; 
		}
		res_sis[i] = (y[i] - total) / U[i][i];
	}
	for(i = 0; i <= n; i++){
		printf("y%-2d = %19.16lf     ", i + 1, y[i]);
		printf("x%-2d = %19.16lf\n", i + 1, res_sis[i]);
	}
	
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
void cria_vetor(int v[], int n){
	for(int i = 0; i < n; i++){
		v[i] = i;
	}
}
