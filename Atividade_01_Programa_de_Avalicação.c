#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char nome[MAX_NAME_LENGTH];
    double nota1;
    double nota2;
} Aluno;

int main() {
    FILE *entrada, *saida;
    char linha[MAX_LINE_LENGTH];
    char *token;
    Aluno aluno;
    
    entrada = fopen("DadosEntrada.csv", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    saida = fopen("SituacaoFinal.csv", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(entrada);
        return 1;
    }

    while (fgets(linha, sizeof(linha), entrada)) {
        token = strtok(linha, ",");
        strcpy(aluno.nome, token);
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        aluno.nota1 = atof(token);
        token = strtok(NULL, ",");
        aluno.nota2 = atof(token);

        double media = (aluno.nota1 + aluno.nota2) / 2.0;

        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        fprintf(saida, "%s, %.2f, %s\n", aluno.nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    printf("Análise pronta. Veja o arquivo SituacaoFinal.csv.\n");

    return 0;
}