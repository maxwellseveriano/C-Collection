#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

int* random_vet(int);
void pogo_sort(int*);
void print(int *);
int ordem(int *);

int main(){
	time_t t;
	clock_t tempo;
	
	srand((unsigned) time(&t));
	
	int *x = random_vet(N);
	
	print(x);
	tempo = clock();
	
	while(!ordem(x)){
		pogo_sort(x);
	}
	
	tempo = clock() - tempo;
	print(x);
	
	double temp_total = (double)tempo / CLOCKS_PER_SEC;
	printf("tempo: %lfs\n", temp_total);
	
	return 0;
}
void pogo_sort(int *vet){
	int i = 0, indice, temp;
	
	int x[N] = {0};
	
	while(i < N){
		indice = rand() % N;
		
		if(x[indice] == 0){
			x[indice] = 1;
			
			temp = vet[i];
			vet[i] = vet[indice];
			vet[indice] = temp;
			
			i++;
		}
	}
}
int ordem(int *vet){
	
	for(int i = 0; i < N - 1; i++){
		if(vet[i] > vet[i + 1])
			return 0;
	}
	return 1;
}
int* random_vet(int n){
	int *vet = (int *) malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++){
		vet[i] = rand() % 10;
	}
	
	return vet;
}
void print(int *vet){
	for(int i = 0; i < N; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

