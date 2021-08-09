#ifndef PILHABC_H
#define PILHABC_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>


typedef struct No_da_pilhaBC No_da_pilhaBC;
typedef struct Valor_da_PilhaBC Valor_da_PilhaBC;
typedef struct Pilha Pilha;

struct Valor_da_PilhaBC{
	int val;
};

struct No_da_pilhaBC{
	Valor_da_PilhaBC data;
	No_da_pilhaBC *prox;
};

struct Pilha{
	No_da_pilhaBC *base;
	No_da_pilhaBC *topo;
};


void Empilhar(Pilha *p, Valor_da_PilhaBC v);

void Desempilhar(Pilha *p, Valor_da_PilhaBC *v);

void imprime(Pilha *p);

void totient(Pilha *p);

void Resposta2c();

#endif