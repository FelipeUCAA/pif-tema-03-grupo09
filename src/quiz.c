#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/quiz.h"

void embaralharPerguntas(Pergunta *p, int total) {
    for(int i = 0; i < total; i++) {
        int aleatorio = rand() % total;

        Pergunta temp = p[i];
        p[i] = p[aleatorio];
        p[aleatorio] = temp;
    }
}

int jogarQuiz(Pergunta *p, int total, char nome[]) {
    int pontos = 0;
    int resposta;

    embaralharPerguntas(p, total);

    printf("\n===== QUIZ =====\n");
    printf("Jogador: %s\n", nome);

    for(int i = 0; i < total; i++) {
        printf("\nPergunta %d\n", i + 1);
        printf("%s\n", p[i].enunciado);

        for(int j = 0; j < 4; j++) {
            printf("%d - %s\n", j, p[i].alternativas[j]);
        }

        printf("Resposta: ");
        scanf("%d", &resposta);

        switch(resposta) {
            case 0:
            case 1:
            case 2:
            case 3:
                if(resposta == p[i].correta) {
                    printf("Correto!\n");
                    pontos += 2;
                } else {
                    printf("Errado!\n");
                }
                break;

            default:
                printf("Opcao invalida\n");
        }
    }

    printf("\nPontuacao final: %d\n", pontos);

    return pontos;
}