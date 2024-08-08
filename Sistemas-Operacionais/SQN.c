#include <stdio.h>
int main()
{
	// Matrix for storing Process Id, Burst
	// Time, Average Waiting Time & Average
	// Turn Around Time.
	int A[100][5];
	int i, j, n, total = 0, index, temp, max = 1, counter;
	float avg_wt, avg_tat;
	FILE *arquivo = fopen("sjf.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fscanf(arquivo, "%d", &n);
	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		fscanf(arquivo, "%d", &A[i][4]);
		fscanf(arquivo, "%d", &A[i][1]);
		max += A[i][1];
		A[i][0] = i + 1;
	}
	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		counter = max;
		for (j = i; j < n; j++){
			if (A[j][1] < counter && A[j][4] <= total){
				index = j;
				counter = A[index][1];
			}
		}

		total += A[index][1];

		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;

		temp = A[i][4];
		A[i][4] = A[index][4];
		A[index][4] = temp;
	}
	total = 0;
	A[0][2] = 0;
    float tat = 0.0, wtt =0.0;
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		total += A[i-1][1];
		A[i][2] = total - A[i][4];
		wtt += A[i][2];
		
	}
	total = 0;
	avg_wt = (float)wtt / n;
	printf("P	 BT	 WT	 TAT\n");
	// Calculation of Turn Around Time and printing the
	// data.
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("P%d	 %d	 %d	 %d\n", A[i][0],
			A[i][1], A[i][2], A[i][3]);
        tat += A[i][3] * 1.0 / A[i][1];
	}
	avg_tat = (float)total / n;
    float tr_tx = tat / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
    printf("\nTr/Tx= %f", tr_tx);
}
