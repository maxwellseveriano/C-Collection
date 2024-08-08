#include <stdio.h>

#define NQ 6
#define NT 5
#define NP NQ + NT * 2

int main(){
	
	double q, t;
	double mf, ap1 = 0, ap2, ap3;
	
	for(int i = 0; i < NQ; i++){
		printf("Q%d: ", i + 1);
		scanf(" %lf", &q);
		ap1 += q;
	}
	for(int i = 0; i < NT; i++){
		printf("T%d: ", i + 1);
		scanf(" %lf", &t);
		ap1 += (t * 2);
	}
	printf("P1: ");
	scanf(" %f", &ap2);
	
	printf("P2: ");
	scanf(" %f", &ap3);
	
	mf = ((ap1 / 16) + ap2 + ap3) / 3;
	
	if(mf >= 5)
		printf("Media:%f\nPARABENS. APROVADO!!!\n", mf);
	else
		printf("Media:%f\nBURROKKKKKK\n", mf);	
		
	return 0;
}
