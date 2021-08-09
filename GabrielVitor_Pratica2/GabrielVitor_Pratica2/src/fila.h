#ifndef FILA_H
#define FILA_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Valor1 Valor1;
typedef struct No1 No1;
typedef struct fila1 fila1;
typedef struct No2  No2;
typedef struct fila2 fila2;
typedef struct Valor3 Valor3;
typedef struct No3 No3;
typedef struct fila3 fila3;
typedef struct Valor2 Valor2;



 struct Valor1{
	int k;
    char x;
    char y;
};

 struct No1{
	Valor1 data;
	No1 *prox;
};

 struct fila1{
	No1 *primeiro;
	No1 *ultimo;
};

 struct Valor2{
	int val;
	int peso[5];
};

 struct No2{
	Valor2 Data;
	No2 *prox;
};

 struct fila2{
	No2 *primeiro;
	No2 *ultimo;
};

 struct Valor3{
	char *result;
};

 struct No3{
	Valor3 data;
	No3 *prox;
};

 struct fila3{
	No3 *primeiro;
	No3 *ultimo;
};



void fila_vazia(fila1 *f);
void enfileira(fila1 *f, Valor1 d);
void desenfileira(fila1 *f, Valor1 *d);
void imprimir_fila(fila1 *f);

void fila_dois_vazia(fila2 *f);
void enfileira_fila_dois(fila2 *f, Valor2 d);
void imprimir_fila_dois(fila2 *f);

void fila_tres_vazia(fila3 *f);
void enfileira_fila_tres(fila3 *f, Valor3 d);
void imprimir_fila_tres(fila3 *f);




int fatorial(int n);

int combinacao(int n, int p);

void binomio(int n, char x, char y, fila3 *res);

void classe(fila2 *f, Valor2 *d);

void Resposta3A();

void Resposta3B();

#endif