#include "fila.h"


void fila_vazia(fila1 *f){

	f->primeiro = (No1*) malloc (sizeof(No1));
	f->ultimo  = f->primeiro;
	f->primeiro->prox = NULL;
}

void enfileira(fila1 *f, Valor1 d){

	f->ultimo->prox = (No1*) malloc (sizeof(No1));
	f->ultimo = f->ultimo->prox;
	f->ultimo->data = d;
	f->ultimo->prox = NULL;
}

void desenfileira(fila1 *f, Valor1 *d){

	No1 *aux;

	if(f->primeiro == f->ultimo || f == NULL || f->primeiro->prox == NULL){
		printf("\t------------fila vazia------------\n");
		return;
	}
	
	aux = f->primeiro;
	f->primeiro = f->primeiro->prox;
	d->k   = aux->data.k;
    d->x   = aux->data.x;
    d->y   = aux->data.y;
	free(aux);
}


void imprimir_fila(fila1 *f){
	No1 *aux;

	aux = f->primeiro->prox;
	while(aux != NULL){

		printf("(%c+%c)^%d\n", aux->data.x, aux->data.y, aux->data.k);
		aux = aux->prox;
	}

}


void fila_dois_vazia(fila2 *f){

	f->primeiro = (No2*) malloc (sizeof(No2));
	f->ultimo  = f->primeiro;
	f->primeiro->prox = NULL;
}

void enfileira_fila_dois(fila2 *f, Valor2 d){

	f->ultimo->prox = (No2*) malloc (sizeof(No2));
	f->ultimo = f->ultimo->prox;
	f->ultimo->Data = d;
	f->ultimo->prox = NULL;
}

void imprimir_fila_dois(fila2 *f){

	No2 *aux;

	aux = f->primeiro->prox;

	while(aux != NULL){

		printf("\t---------------------------------!\n");
		printf("Atributo:\n");
		printf("%d\n", aux->Data.val);
		printf("Vetor Peso:\n");
		for(int i = 0; i < 5; i++)
			printf("%d\t", aux->Data.peso[i]);
		printf("\n");
		aux = aux->prox;
	}
}

void fila_tres_vazia(fila3 *f){

	f->primeiro = (No3*) malloc (sizeof(No3));
	f->ultimo  = f->primeiro;
	f->primeiro->prox = NULL;
}

void enfileira_fila_tres(fila3 *f, Valor3 d){

	f->ultimo->prox = (No3*) malloc (sizeof(No3));
	f->ultimo = f->ultimo->prox;
	f->ultimo->data = d;
	f->ultimo->prox = NULL;
}

void imprimir_fila_tres(fila3 *f){

	No3 *aux;

	aux = f->primeiro->prox;
	while(aux != NULL){

		printf("%s", aux->data.result);
		aux = aux->prox;
	}
}


int fatorial(int n){

    int fatorial = 0;

    for(fatorial = 1; n > 1; n = n - 1){

        fatorial = fatorial * n;
    }
    return fatorial;
}

int combinacao(int n, int p){  

    int c;
    int aux;
    aux = n - p;
    c = fatorial(n);
    c = c/(fatorial(p)*fatorial(aux));

    return c;
}

void Binomio(int n, char x, char y, fila3 *res){

    for(int j = 0; j <= n; j++){

        if(j < n){

            char *str = malloc(sizeof(str));
            sprintf(str, "%d(%c^%d * %c^%d) + ", combinacao(n, j), x,n-j, y, j);
            Valor3 r;
            r.result = str;
            enfileira_fila_tres(res, r);
        }else if(j == n){

            char *str = malloc(sizeof(str));
            sprintf(str, "%d(%c^%d * %c^%d)\n", combinacao(n, j), x,n-j, y, j);
            Valor3 r;
            r.result = str;
            enfileira_fila_tres(res, r);    
        }
    }
}

void FindClasse(fila2 *f, Valor2 *d){

    No2 *aux;

	aux = f->primeiro->prox;
	while(aux != NULL){

        if(&aux->Data == d){

            int max = aux->Data.peso[0];
            int classe = 0;
            for (int i = 1; i < 5; i++){

                if(max < aux->Data.peso[i]){

                    max = aux->Data.peso[i];
                    classe = i;
                }else if(max == aux->Data.peso[i]){

                    max = aux->Data.peso[i];
                    classe = i;
                }
            }
            printf(" Classe: %d", classe);
            printf("\n");
        }
        aux = aux->prox;
    }
}
void Resposta3A(){

        fila1 f;
        fila_vazia(&f);
        fila3 res;
        fila_tres_vazia(&res);
        int max = 7;
        for(int i = 2; i < max; i++){
            Valor1 d;
            d.k = i;
            d.x = 'a';
            d.y = 'b';
            enfileira(&f, d);   
        }
        imprimir_fila(&f);
        printf("\n");
        No1 *aux;
        aux = f.primeiro->prox;
        while(aux != NULL){
            Binomio(aux->data.k, aux->data.x, aux->data.y, &res);
            aux = aux->prox;
        }
        imprimir_fila_tres(&res);
}

void Resposta3B(){

    fila2 f;
        fila_dois_vazia(&f);
        srand((unsigned)time(NULL));
        for(int i = 0; i < 10; i++){
            Valor2 b;
            b.val = (rand()%99)+1;
            for (int j = 0; j < 5; j++){
                b.peso[j] = (rand()%5)+1;
            }
            enfileira_fila_dois(&f, b);
        }
        imprimir_fila_dois(&f);
        printf("\n");

        No2 *x;
        x = f.primeiro->prox;

        while(x != NULL){
            printf("Valor: ");
            printf("%d", x->Data.val);
            FindClasse(&f, &x->Data);	
            x = x->prox;
        }    
}