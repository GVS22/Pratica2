#ifndef PILHAA_H
#define PILHAA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char caracter;
    struct No *proximo;
}No;

No* empilhar(No *pilha, char valor);

No* desempilhar(No **pilha);

void imprimir(No *pilha);

int forma_par(char f, char d);

int identifica_formacao(char x[]);

void Resposta2A();

#endif


