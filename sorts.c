#include <stdio.h>
#include <stdlib.h>

#define N 10000

int* alocaVet(int);
void printVet(int *, int);
void convertNot(float);

int bSort(int *, int);
void qSort(int *, int);

int main()
{
	int *vet = alocaVet(N);
	int cont;
	
	printVet(vet, N);
	cont = bSort(vet, N);
	printVet(vet, N);
	
	printf("Verificacoes: %d\n", cont);
	convertNot((float) cont);
	
	
	return 0;
}

int bSort(int *vet, int n){
	int i, j, temp, cont = 0;
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(vet[j] > vet[j + 1]){
				temp = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = temp;
			}
			cont++;
		}
	}
	return cont;
}

int* alocaVet(int n){
	int i;
	int *vet = (int *) malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++){
		vet[i] = rand() % 10000;
	}
	
	return vet;
}
void printVet(int *vet, int n){
	for(int i = 0; i < n * 0.01; i++){
		printf("%d ", vet[i]);	
	}
	printf("\n\n");
}
void convertNot(float ver){
	int cont = 0;
	
	while(ver/10 >= 1){
		cont++;
		ver = ver / 10;
	}
	
	printf("verificacoes: %f x 10^%d\n", ver, cont);
}
