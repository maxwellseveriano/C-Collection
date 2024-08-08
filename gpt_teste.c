#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para realizar o produto escalar de dois vetores
double dotProduct(const double *a, const double *b, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }
    return result;
}

// Função para calcular a norma (comprimento) de um vetor
double norm(const double *v, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

// Função para normalizar um vetor
void normalize(double *v, int n) {
    double vNorm = norm(v, n);
    for (int i = 0; i < n; i++) {
        v[i] /= vNorm;
    }
}

// Função para calcular a decomposição QR
void qrDecomposition(const double *A, int m, int n, double *Q, double *R) {
    double *tmpA = malloc(m * n * sizeof(double));
    double *tmpQ = malloc(m * n * sizeof(double));
    double *tmpR = malloc(n * n * sizeof(double));

    // Copiar a matriz A para tmpA
    for (int i = 0; i < m * n; i++) {
        tmpA[i] = A[i];
    }

    for (int i = 0; i < n; i++) {
        // Extrair a coluna i de tmpA
        double *ai = malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            ai[j] = tmpA[j * n + i];
        }

        // Subtrair a projeção nos vetores já computados
        for (int j = 0; j < i; j++) {
            double *qj = malloc(m * sizeof(double));
            for (int k = 0; k < m; k++) {
                qj[k] = tmpQ[k * n + j];
            }

            double proj = dotProduct(ai, qj, m);
            for (int k = 0; k < m; k++) {
                ai[k] -= proj * qj[k];
            }
            free(qj);
        }

        // Normalizar o vetor resultante
        normalize(ai, m);

        // Preencher a coluna i de Q
        for (int j = 0; j < m; j++) {
            tmpQ[j * n + i] = ai[j];
        }

        // Preencher a coluna i de R
        for (int j = 0; j < i; j++) {
            tmpR[j * n + i] = dotProduct(ai, &tmpA[j * n], m);
        }
        tmpR[i * n + i] = norm(ai, m);

        free(ai);
    }

    // Copiar a matriz temporária Q para a matriz de saída Q
    for (int i = 0; i < m * n; i++) {
        Q[i] = tmpQ[i];
    }

    // Copiar a matriz temporária R para a matriz de saída R
    for (int i = 0; i < n * n; i++) {
        R[i] = tmpR[i];
    }

    free(tmpA);
    free(tmpQ);
    free(tmpR);
}

int main() {
    double i = 0.0;
    double j = 0.0;
    double r = 0.0;
    int res = 0;

    double x[] = {1, 2, 3, 4, 5};    // Vetor com os prazos
    double y[] = {1100, 1200, 1300, 1400, 1500};    // Vetor com os juros
    int n = sizeof(x) / sizeof(x[0]);

    // Criar a matriz A a partir dos vetores x e y
    double *A = malloc(n * 2 * sizeof(double));
    for (int k = 0; k < n; ++k) {
        A[k] = x[k];
        A[n + k] = 1.0; // Adicionar uma coluna de 1's para o termo independente
    }

    double *Q = malloc(n * 2 * sizeof(double));
    double *R = malloc(2 * 2 * sizeof(double));

    qrDecomposition(A, n, 2, Q, R);

    // Resolver o sistema linear usando a matriz R
    double dec = R[0] * (dotProduct(Q, y, n) / norm(Q, n));
    double inter = R[n + 1] * (dotProduct(&Q[n], y, n) / norm(&Q[n], n));

    if (&i != NULL) {
        i = dec;
    }

    if (&j != NULL) {
        j = inter;
    }

    if (&r != NULL) {
        // Calcular r
        double somaX = 0.0;
        double somaXX = 0.0;
        double somaXY = 0.0;
        double somaY = 0.0;
        double somaYY = 0.0;
        double nReal = (double)(n);
        int k = 0;
        double denominador = 0.0;

        for (k = 0; k < n; ++k) {
            somaX += x[k];
            somaXX += x[k] * x[k];
            somaXY += x[k] * y[k];
            somaY += y[k];
            somaYY += y[k] * y[k];
        }

        denominador = nReal * somaXX - somaX * somaX;
        r = ((nReal * somaXY) - (somaX * somaY)) * ((nReal * somaXY) - (somaX * somaY)) / denominador;
    }

    free(A);
    free(Q);
    free(R);

    printf("y = %.2fx + %.2f\n", i, j);
    printf("r: %f\n", r);

    return 0;
}

