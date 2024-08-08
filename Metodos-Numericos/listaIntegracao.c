//Nome: MAXWELL WILLIAM SEVERIANO CHAGAS
#include <stdio.h>
#include <math.h>

double I1(double);
double I2(double);
double I3(double);
double I4(double);

void questao1(int, double, double);
void questao2(int, double, double);
void questao3(int, double, double);
void questao4(double, double);

double trapComp(int, double, double, double (*func)(double));
double simp1_3(int, double, double, double (*func)(double x));
double simp3_8(int, double, double, double (*func)(double x));

int main()
{
	questao1(4, 0, 1);
	questao2(6, 0, 1);
	questao3(300, 2, 4);
	questao4(0, 1);
	
	return 0;
}

void questao1(int n, double a, double b){
	double resQ1;
	printf("---------------QUESTAO 1-----------------\n\n");
	printf("Metodo\t\t\tValor aproximado\n");
	
	resQ1 = trapComp(n, a, b, I1);
	printf("Trapezios Composta\t%.8lf\n\n\n", resQ1);
}
void questao2(int n, double a, double b){
	double resQ2;
	printf("---------------QUESTAO 2-----------------\n\n");
	printf("Metodo\t\t\tValor aproximado\n");
	
	resQ2 = trapComp(n, a, b, I2);
	printf("Trapezios Composta\t%.8lf\n", resQ2);
	
	resQ2 = simp1_3(n, a, b, I2);
	printf("Regra 1/3 de Simpson\t%.8lf\n", resQ2);
	
	resQ2 = simp3_8(n, a, b, I2);
	printf("Regra 3/8 de Simpson\t%.8lf\n\n\n", resQ2);
}
void questao3(int n, double a, double b){
	double resQ3;
	printf("---------------QUESTAO 3-----------------\n\n");
	printf("Metodo\t\t\tValor aproximado\n");
	
	resQ3 = trapComp(n, a, b, I3);
	printf("Trapezios Composta\t%.8lf\n", resQ3);
	
	resQ3 = simp1_3(n, a, b, I3);
	printf("Regra 1/3 de Simpson\t%.8lf\n", resQ3);
	
	resQ3 = simp3_8(n, a, b, I3);
	printf("Regra 3/8 de Simpson\t%.8lf\n\n\n", resQ3);
}
void questao4(double a, double b){
	double resQ4;
	int n = 0;
	do{
		n++;
		resQ4 = trapComp(n, a, b, I4);
	}while(fabs(resQ4 - 0.3333) > 1e-4);
	printf("---------------QUESTAO 4-----------------\n\n");
	printf("Subintervalos\t\tValor aproximado\n");
	printf("%d\t\t\t%lf\n", n, resQ4);
}

double trapComp(int n, double a, double b, double (*func)(double x)){
	double h = (b - a) / n;
	double res = func(a) + func(b);
	int i;
	
	for(i = 1; i < n; i++){
		a += h;
		res += 2 * func(a);
	}
	
	res = res * h / 2;
	
	return res;
}

double simp1_3(int n, double a, double b, double (*func)(double x)){
	if(n % 2 != 0){
		printf("\nO NUMERO DE SUBINTERVALOS DEVE SER PAR!\n");
		return 0;
	}
	double h = (b - a) / n;
	double res = func(a) + func(b);
	int i;
	
	for(i = 1; i < n; i++){
		a += h;
		
		if(i % 2 == 0)
			res += 2 * func(a);
			
		else
			res += 4 * func(a);
	}
	
	res = res * h / 3;
	
	return res;
}

double simp3_8(int n, double a, double b, double (*func)(double x)){
	if(n % 3 != 0){
		printf("\nO NUMERO DE SUBINTERVALOS DEVE SER MULTIPLO DE 3!\n");
		return 0;
	}
	double h = (b - a) / n;
	double res = func(a) + func(b);
	int i;
	
	for(i = 1; i < n; i++){
		a += h;
		
		if(i % 3 == 0)
			res += 2 * func(a);
			
		else
			res += 3 * func(a);
	}
	
	res = res * (3 * h / 8);
	
	return res;
}

double I1(double x){
	if(x == 0)		return 1.0;
	if(x == 0.25)	return 1.284;
	if(x == 0.5)	return 1.649;
	if(x == 0.75)	return 2.117;
	if(x == 1)		return 2.718;
	
	printf("\nf(x) nao definida para esse ponto\n");
	return 0;
}

double I2(double x){
	return pow(x, 2);
}

double I3(double x){
	return 1 / (x + 1);
}

double I4(double x){
	return pow(x, 2);
}
