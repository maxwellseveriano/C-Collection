#include <stdio.h>
#include <stdlib.h>

#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define QUANT_BITS B6(0), B6(1), B6(1), B6(2)

typedef struct SimilarityPair {
        int posicao;
        int similaridade;
} SIMILARITYPAIR;

void simil(unsigned char * S, int n, unsigned char * a, int nb, int k);
void print_conj(unsigned char * a, int nb);
static inline int card_inters(unsigned char * a, unsigned char * b, int nb);

int main() {
	
    unsigned long long int mat = 20220011994; // preencher com seu numero de matriculana UFRRJ
    int n = sizeof(unsigned long long int) << 8;
    unsigned long long int S[n];
    
	unsigned long long int j;
	int i, k, l;
	
    for (i = 0, k = 0, l = 0; i < sizeof(unsigned long long int); i++, l += 8){
        for (j = 0; j < 256; j++, k++){
            S[k] = mat & ~(~j << l);
        }
    }

    int L = 10;
    simil((unsigned char *) S, n, (unsigned char *) &mat, sizeof(unsigned long long int), L);
    printf("%d Conjuntos mais similares a %llu dentre os %d:\n", L,mat,n);
    
    print_conj((unsigned char *) &mat, sizeof(unsigned long long int));
    printf("\n-----------------------\n");

    for (i = 0; i < L; i++) {
        printf("S[%d] = %llu\n", i, S[i]);
        print_conj((unsigned char *) (S+i), sizeof(unsigned long long int));
        printf("\n");
    }
    return 0;
}
simil(unsigned char * S, int n, unsigned char * a, int nb, int k){
	
	SIMILARITYPAIR *simi = malloc(n * sizeof(SIMILARITYPAIR));
	
	// Calcula a similaridade entre o elemento a e cada elemento em S
    for (int i = 0; i < n; i++) {
        simi[i].posicao = i;
        simi[i].similaridade = card_inters(a, &S[i * nb], nb);
    }
	
	for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (simi[j].similaridade < simi[j + 1].similaridade) {
                SIMILARITYPAIR temp = simi[j];
                simi[j] = simi[j + 1];
                simi[j + 1] = temp;
            }
        }
    }
}
// Fun��o para contar cardinalidade da interse��o
// a,b: ponteiros para vetores de bytes
// n: quantidade de bytes em cada vetor
static inline int card_inters(unsigned char * a, unsigned char * b, int nb) {
	const unsigned int __qbits_tab[256] = { QUANT_BITS };
    int ret = 0;
    // percorre bytes dosvetores
    for (int i = 0; i < nb; i++)
        ret += __qbits_tab[a[i] & b[i]]; // i-esimo byte
    return ret;
}
void print_conj(unsigned char * a, int nb) {
	
	int b, i, j;   
   
    printf("{");
    for (b = 0, i = 0; b < nb; b++)
        for (j = 0; j < 8; j++, i++) {
            char n = a[b] >> j;
            if (n & 1)
                printf(" %d", i);
        }
    printf(" }");
}
