#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/quiz.h"
#include "../include/ranking.h"
#include "../include/arquivo.h"
#include "../include/structs.h"
#include "../include/utils.h"

int main() {
    srand(time(NULL));

    int opcao;
    int totalPerguntas;

    Pergunta *perguntas = carregarPerguntas(&totalPerguntas);

    Jogador ranking[100];
    int totalRanking;

    carregarRanking(ranking, &totalRanking);

    do {
        printf("\n===== MINI KAHOOT =====\n");
        printf("1 - Jogar\n");
        printf("2 - Ver Ranking\n");
        printf("3 - Adicionar Pergunta\n");
        printf("4 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                Jogador jogador;

                getchar();

                printf("Nome do jogador: ");
                fgets(jogador.nome, MAX_NOME, stdin);
                removerEnter(jogador.nome);

                jogador.pontos = jogarQuiz(perguntas,
                                            totalPerguntas,
                                            jogador.nome);

                atualizarRanking(ranking,
                                  &totalRanking,
                                  jogador);

                break;
            }

            case 2:
                mostrarRanking();
                break;

            case 3:
                adicionarPergunta();

                free(perguntas);
                perguntas = carregarPerguntas(&totalPerguntas);
                break;

            case 4:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while(opcao != 4);

    free(perguntas);

    return 0;
}