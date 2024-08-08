/*
 * FCFS Scheduling Program in C
 */
 
#include <stdio.h>
int main()
{
    int n;
    FILE *arquivo = fopen("fifo.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fscanf(arquivo, "%d", &n);

    int pid[n];
    int bt[n];
    int arrt[n];

    for(int i=0;i<n;i++)
    {
        fscanf(arquivo, "%d", &pid[i]);
    }
    for(int i=0;i<n;i++)
    {
        fscanf(arquivo, "%d", &arrt[i]);
    }
    int total_burst_time = 0;
    for(int i=0;i<n;i++)
    {
        fscanf(arquivo, "%d", &bt[i]);
        total_burst_time += bt[i];
    }
 
    int i, wt[n];
    wt[0]=0;
    int total = 0;
 
    //for calculating waiting time of each process
    for(i=1; i<n; i++)
    {
        total += bt[i-1];
        wt[i] = total - arrt[i];
    }
    total = total + bt[i-1];
 
    printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float twt=0.0, abt =0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
 
        //calculating and printing turnaround time of each process
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
 
        //for calculating total waiting time
        twt += wt[i];
 
        //for calculating total turnaround time
        tat += (wt[i]+bt[i]);
        abt += (wt[i]+bt[i]) * 1.0 / bt[i];
    }
    float att, awt;
 
    //for calculating average waiting time
    awt = twt/n;
 
    //for calculating average turnaround time
    att = tat/n;

    abt = abt / n;

    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f\n",att);
    printf("Tr/Tx= %f",abt);
}
