#include <stdio.h>
#include <string.h>
#include "../include/ranking.h"

void carregarRanking(Jogador ranking[], int *total) {
    FILE *arquivo = fopen("data/ranking.txt", "r");

    *total = 0;

    if(arquivo == NULL)
        return;

    while(fscanf(arquivo, "%49[^;];%d\n",
           ranking[*total].nome,
           &ranking[*total].pontos) == 2) {

        (*total)++;
    }

    fclose(arquivo);
}

void salvarRanking(Jogador ranking[], int total) {
    FILE *arquivo = fopen("data/ranking.txt", "w");

    for(int i = 0; i < total && i < 10; i++) {
        fprintf(arquivo, "%s;%d\n",
                ranking[i].nome,
                ranking[i].pontos);
    }

    fclose(arquivo);
}

void ordenarRanking(Jogador ranking[], int total, int i) {
    if(i >= total - 1)
        return;

    for(int j = i + 1; j < total; j++) {
        if(ranking[j].pontos > ranking[i].pontos) {
            Jogador temp = ranking[i];
            ranking[i] = ranking[j];
            ranking[j] = temp;
        }
    }

    ordenarRanking(ranking, total, i + 1);
}

void atualizarRanking(Jogador ranking[], int *total, Jogador novo) {
    ranking[*total] = novo;
    (*total)++;

    ordenarRanking(ranking, *total, 0);

    salvarRanking(ranking, *total);
}

void mostrarRanking() {
    Jogador ranking[100];
    int total;

    carregarRanking(ranking, &total);

    printf("\n===== RANKING =====\n");

    for(int i = 0; i < total && i < 10; i++) {
        printf("%d. %s - %d pontos\n",
               i + 1,
               ranking[i].nome,
               ranking[i].pontos);
    }
}