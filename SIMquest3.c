#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("ganhos.txt", "r");
    if(fp == NULL){
        printf("EERO\n");
        exit(1);
    }
    int ano, i, total;
    char sequencia[51];

    fscanf(fp, "%d", &ano);
    int pMaior = 0, anoMaior = ano;
    
    while (ano != 0){
        total = 0;

        fscanf(fp, "%s", sequencia);
        for(i = 0; sequencia[i] != '\0'; i++){
            if(sequencia[i] == 'V' || sequencia[i] == 'v')
                total += 3;

            else if(sequencia[i] == 'E' || sequencia[i] == 'e')
                total += 1;
        }
        if(total > pMaior){
            pMaior = total;
            anoMaior = ano;
        }
        printf("O time fez %d pontos em %d\n", total, ano);
        fscanf(fp, "%d", &ano);
    }
    printf("Melhor ano: %d; pontos: %d", anoMaior, pMaior);
    fclose(fp);

    return 0;
}