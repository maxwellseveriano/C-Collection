#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome_arq1[41], nome_arq2[41], nome_jog[41], sobre_jog[41];
    int partidas, pontos;

    scanf("%s%s", nome_arq1, nome_arq2);

    FILE *fp1 = fopen(nome_arq1, "r");
    FILE *fp2 = fopen(nome_arq2, "w");

    if(fp1 == NULL || fp2 == NULL){
        printf("ERRO\n");
        exit(1);
    }

    while(!feof(fp1)){
        if(fscanf(fp1, "%d %d", &pontos, &partidas) != -1){
            fscanf(fp1, "%s %s", nome_jog, sobre_jog);
            float media = pontos / (partidas * 1.0);
            fprintf(fp2, "%s %s %d %d %.2f\n", nome_jog, sobre_jog, partidas, pontos, media);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}