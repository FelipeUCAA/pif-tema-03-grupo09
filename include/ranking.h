#ifndef RANKING_H
#define RANKING_H

#include "structs.h"

void carregarRanking(Jogador ranking[], int *total);
void salvarRanking(Jogador ranking[], int total);
void atualizarRanking(Jogador ranking[], int *total, Jogador novo);
void mostrarRanking();
void ordenarRanking(Jogador ranking[], int total, int i);

#endif