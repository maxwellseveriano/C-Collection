#include <stdio.h>
#include <stdlib.h>

double **geraMatriz(int);
double *geraVetor(int);
void imprime(double **, double *, int);

int main()
{

	int i, k;
	int n = 20;

	double **A = geraMatriz(n + 1);
	double *B = geraVetor(n + 1);

	imprime(A, B, n + 1);

	return 0;
}

double **geraMatriz(int n)
{
	int i, j, aux = 0;
	double **matriz1;

	matriz1 = (double **)malloc(n * sizeof(double *));
	for (i = 0; i < n; i++)
	{
		matriz1[i] = (double *)malloc(n * sizeof(double));
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matriz1[i][j] = abs(j - i);
		}
	}
	return matriz1;
}
double *geraVetor(int n)
{
	int i, j, aux = 0;
	double *matriz1;

	matriz1 = (double *)malloc(n * sizeof(double *));

	for (i = 0; i < n; i++)
	{
		matriz1[i] = i + 1;
	}
	return matriz1;
}
void imprime(double **matriz, double *vetor, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4.1f ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n[ ");
	for (i = 0; i < n; i++)
	{
		printf("%.1f ", vetor[i]);
	}
	printf("]");
}
