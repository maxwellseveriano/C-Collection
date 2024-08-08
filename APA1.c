#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(x, y) x >= y ? x : y

/*Esse algoritmo nao seria ideal com pesos negativos pela verificacao max(x, y)
pois mesmo o maior valor de dois numeros negativos ainda eh menor que se nenhum dosse escolhido.
Ou seja, o maior entre -1 e -2 estaria decrementando o peso total*/
int maior_peso(char[], char[], int, int);
int peso(char);

int main(){
	
	//entrada exemplo
	char X[] = {"ab/CdZ"};
	char Y[] = {"Zab/Cd"};
	
	int res = maior_peso(X, Y, strlen(X), strlen(Y));
	
	//na entrada de exemplo a saida eh 25
	//mesmo que a maior subsequencia seja "ab/Cd", a subsequencia "z" tem o maior peso
	printf("Maior peso: %d\n", res);
	
	return 0;
}
int maior_peso(char X[], char Y[], int n, int m){
	int i, j;
	int L[n + 1][m + 1];
	
	for(i = 0; i <= n; i++){
		L[i][0] = 0;
	}
	for(j = 0; j <= m; j++){
		L[0][j] = 0;
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			//se os caracteres sao iguais, seu peso eh somado ao peso que esta na diagonal 
			if(X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + peso(X[i - 1]);
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	return L[n][m];
}
int peso(char a){
	// variavel para o peso
	int p;
	
	//cada caracter entre a e z recebe um peso de 0 a 25 respectivamente
	if(a >= 'a' && a <= 'z')
		p = a - 'a';
	//cada caracter entre A e Z recebe um peso de 0 a 25 respectivamente
	else if(a >= 'A' && a <= 'Z')
		p = a - 'A';
	//caso contrario, o caracter recebe um peso de 0 a 15 baseado no seu codigo inteiro
	else
		p = a % 16;
	
	return p;
}
