#include <stdio.h>

int main(){
	
	int i, j, n;
	int cont, num, maior = 0;
	
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++){
		cont = 0;
		j = i;
		while(j != 1){
			if(j % 2 == 0)
				j = j / 2;
			else
				j = (3 * j) + 1;
			cont++;
		}
		if(cont >= maior){
			maior = cont;
			num = i;
		}
	}
	
	printf("numero: %d\npassoss: %d\n", num, maior);
	
	return 0;
}
