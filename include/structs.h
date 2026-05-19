#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_PERGUNTA 200
#define MAX_ALT 80
#define MAX_NOME 50

typedef struct {
    char enunciado[MAX_PERGUNTA];
    char alternativas[4][MAX_ALT];
    int correta;
} Pergunta;

typedef struct {
    char nome[MAX_NOME];
    int pontos;
} Jogador;

#endif