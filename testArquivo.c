#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[100];
    int idade;
    float altura;
} PESSOA;

void escreve(char *nome);
void escreveB(char *nome);
void le(char *nome);
void leB(char *nome);

int main()
{
    escreve("arquivoTest.txt");
    le("arquivoTest.txt");

    escreveB("arquivoTestB.txt");
    leB("arquivoTestB.txt");

    return 0;
}

void escreve(char *nome){
    FILE *fp = fopen(nome, "a");
    PESSOA *pes = malloc(sizeof(PESSOA));

    if(fp == NULL){
        printf("ERRO SEU BURRO!!!\n");
        exit(1);
    }

    scanf("%100[^\n]%d%f", pes->nome, &pes->idade, &pes->altura);

    fprintf(fp, "%s\n%d %.2f\n", pes->nome, pes->idade, pes->altura);

    fclose(fp);
    free(pes);
}

void le(char *nome){
    FILE *fp = fopen(nome, "r");
    PESSOA *pes = malloc(sizeof(PESSOA));

    if(fp == NULL){
        printf("ERRO SEU BURRO!!!\n");
        exit(1);
    }
    
    while(!feof(fp)){
        fgets(pes->nome, 100, fp);
        fscanf(fp, "%d %f ", &pes->idade, &pes->altura);

        printf("Nome: \t%sIdade: \t%d\nAltura:\t%.2f\n\n", pes->nome, pes->idade, pes->altura);
    }

    fclose(fp);
    free(pes);
}
void escreveB(char *nome){
    FILE *fp = fopen(nome, "ab");
    PESSOA pes;
    
    if(fp == NULL){
        printf("ERRO SEU BURRO!!!\n");
        exit(1);
    }

    scanf(" %100[^\n] %d %f", pes.nome, &pes.idade, &pes.altura);

    fwrite(&pes, sizeof(PESSOA), 1, fp);

    fclose(fp);
}
void leB(char *nome){
    FILE *fp = fopen(nome, "rb");
    PESSOA pes;
    
    if(fp == NULL){
        printf("ERRO SEU BURRO!!!\n");
        exit(1);
    }

    while(!feof(fp)){
        if(fread(&pes, sizeof(PESSOA), 1, fp))
            printf("%s\n%d %f\n\n", pes.nome, pes.idade, pes.altura);
    }

    fclose(fp);
}