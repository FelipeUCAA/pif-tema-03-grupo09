#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arquivo.h"
#include "../include/utils.h"

Pergunta* carregarPerguntas(int *total) {
    FILE *arquivo = fopen("data/perguntas.txt", "r");

    if(arquivo == NULL) {
        printf("Erro ao abrir perguntas.txt\n");
        *total = 0;
        return NULL;
    }

    int quantidade = 0;
    char linha[300];

    while(fgets(linha, sizeof(linha), arquivo)) {
        quantidade++;
    }

    rewind(arquivo);

    *total = quantidade / 6;

    Pergunta *perguntas = malloc(sizeof(Pergunta) * (*total));

    for(int i = 0; i < *total; i++) {
        fgets(perguntas[i].enunciado, MAX_PERGUNTA, arquivo);
        removerEnter(perguntas[i].enunciado);

        for(int j = 0; j < 4; j++) {
            fgets(perguntas[i].alternativas[j], MAX_ALT, arquivo);
            removerEnter(perguntas[i].alternativas[j]);
        }

        fscanf(arquivo, "%d\n", &perguntas[i].correta);
    }

    fclose(arquivo);

    return perguntas;
}

void adicionarPergunta() {
    FILE *arquivo = fopen("data/perguntas.txt", "a");

    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    Pergunta p;

    getchar();

    printf("Enunciado: ");
    fgets(p.enunciado, MAX_PERGUNTA, stdin);
    removerEnter(p.enunciado);

    for(int i = 0; i < 4; i++) {
        printf("Alternativa %d: ", i);
        fgets(p.alternativas[i], MAX_ALT, stdin);
        removerEnter(p.alternativas[i]);
    }

    printf("Indice da correta (0-3): ");
    scanf("%d", &p.correta);

    fprintf(arquivo, "%s\n", p.enunciado);

    for(int i = 0; i < 4; i++) {
        fprintf(arquivo, "%s\n", p.alternativas[i]);
    }

    fprintf(arquivo, "%d\n", p.correta);

    fclose(arquivo);

    printf("Pergunta adicionada com sucesso!\n");
}