#include <stdio.h>

int busca_b(int *, int, int, int);

int main()
{
	int n = 10;
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int x = 10;
	int i = busca_b(vet, x, 0, n);
	
	printf("vet[%d] = %d\n", i, vet[i]);
	
	return 0;
}
int busca_b(int *vet, int x, int ini, int fim){
	
	int meio = (fim + ini) / 2;
	
	if(vet[meio] > x)
		return busca_b(vet, x, ini, meio);

	if(vet[meio] < x)
		return busca_b(vet, x, meio, fim);
		
	return meio;
}
