#include<stdio.h>

void regressaoLinear(const double * x, const double * y, const int n, double * dec1, double * inter, double * r) {
    double somaX = 0.0;
    double somaXX = 0.0;
    double somaXY = 0.0;
    double somaY = 0.0;
    double somaYY = 0.0;
    double nReal = (double)(n);
    int k = 0;
    double dec = 0.0;
    double denominador = 0.0;

    for (k = 0; k < n; ++k) {
        somaX += x[k];
        somaXX += x[k] * x[k];
        somaXY += x[k] * y[k];
        somaY += y[k];
        somaYY += y[k] * y[k];
    }

    denominador = nReal * somaXX - somaX * somaX;
    dec = (nReal * somaXY - somaX * somaY) / denominador;

    if (dec1 != NULL) {
        *dec1 = dec;
    }

    if (inter != NULL) {
        *inter = (somaY  - dec * somaX) / nReal;
    }

    if (r != NULL) {
        denominador = ((nReal * somaXX) - (somaX * somaX)) * ((nReal * somaYY) - (somaY * somaY));
        *r = ((nReal * somaXY) - (somaX * somaY)) * ((nReal * somaXY) - (somaX * somaY)) / denominador;
    }
}

int main() {
    double a = 0.0;
    double b = 0.0;
    double erro = 0.0;
    
    double x[] = {1, 2, 3, 4, 5};	//Vetor com os prazos
    
	double y[] = {1100, 1200, 1300, 1400, 1500};	//Vetor com os juros	

    regressaoLinear(x, y, sizeof(x) / sizeof(x[0]), &a, &b, &erro);

    printf("y = %.2fx + %.2f\n", a, b);

    return 0;
}
