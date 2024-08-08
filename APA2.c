#include <stdio.h>
#include <stdlib.h>

int maior_seq(int[], int);

int main(){
	//exemplo de entrada
    int X[] = {1, 6, 3, 5, 9, 7, 8, 10};
    int n = 8;

    maior_seq(X, n);
    //saida: 1 3 5 7 8 10

    return 0;
}
int maior_seq(int X[], int n){
	//vetor para armazenar o tamanho da subsequência crescente máxima até cada elemento
    int maior[n];
    //vetor para indicar o indice do elemento anterior que faz parte da subsequência crescente
	int ant[n];

    for (int i = 0; i < n; i++){
    	//todos os elemntos sao inicializados com subsequencia de tamnho 1
        maior[i] = 1;
        //nao existe elemento anterior inicialmente
        ant[i] = -1;
    }
    //algoritmo para determinar a subsequencia maxima: O(n^2)
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
        	//se X[i] for a maior que X[j] e
        	//se o tamanho da subsequencia atual de X[i] for menor que a de X[j] atualizada 
            if (X[i] > X[j] && maior[i] < maior[j] + 1){
            	//maior e ant sao atualizados
                maior[i] = maior[j] + 1;
                ant[i] = j;
            }
        }
    }
    int maximo = 0, fim = 0;
    //determinando o tamanho maximo da subsequencia
    for (int i = 0; i < n; i++){
        if (maior[i] > maximo){
            maximo = maior[i];
            fim = i;
        }
    }
    int res[maximo];
    int aux = fim;
    //Reconstruindo a subsequencia crescente máxima
    for(int i = maximo - 1; aux >= 0; i--){
    	res[i] = X[aux];
        aux = ant[aux];
	}
	
    printf("Maior subsequencia crescente: ");
    for (int i = 0; i < maximo; i++){
        printf("%d ", res[i]);
    }
}
