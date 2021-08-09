#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define Tamanho_Maximo1 100
#define Tamanho_Maximo2 3


typedef struct L1 L1;
typedef struct L2 L2;



 typedef struct Valor{
	int val;
}Valor;

 struct L1{
    Valor vet[100];
    int primeiro;
    int ultimo;
};

 struct L2{
    Valor vet[3];
    int primeiro;
    int ultimo;
};


void lista_vazia(L1 *l);

void lista_dois_vazia(L2 *l);

void inserir_lista(L1 *l, Valor d);

void remover_lista_dois(L2 *l);

void inserir_lista_dois(L2 *l, Valor d);

void Swap(Valor *a, Valor *b);

 
void lista_dois(L2 *l1, L2 *l2);

void imprimir_lista(L1 *l);

void imprimir_lista_dois(L2 *l1, L2 *l2);


void letraA(L1 *par, L1 *impar, L1 *c);

void letraB(L2 *l1, L2 *l2, L2 *l3, L2 *l4, int random);

void Resposta1A();

void Resposta1B();

#endif