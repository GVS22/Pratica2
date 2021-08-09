#include "pilhaBC.h"


void Empilhar(Pilha *p, Valor_da_PilhaBC v){

	No_da_pilhaBC *aux = (No_da_pilhaBC*) malloc (sizeof(No_da_pilhaBC));

	aux->data = v;
	aux->prox = p->topo;
	p->topo = aux;
}

void Desempilhar(Pilha *p, Valor_da_PilhaBC *v){

	No_da_pilhaBC *aux;

	if(p->base == p->topo || p == NULL){

		printf("\t-----------pilha vazia-----------!\n");

		return;
	}
	aux = p->topo;
	p->topo = aux->prox;
	*v = aux->data;
}

void imprime(Pilha *p){
	No_da_pilhaBC *aux;

	aux = p->topo;

    printf("\t--------------pilha--------------!\n");

	while(aux != p->base){

		printf("%d\n", aux->data.val);

		aux = aux->prox;
	}
    printf("\t------------fim pilha------------!\n");
}
//2.b

void totient(Pilha *p){

	const int N = 1e5+2;
	int totient[N];

	for(int i = 0; i < N; i++){

		totient[i] = i;
	} 

	for(int i = 2; i < N; i++){

		if(totient[i] == i){

			for (int j = 2*i; j < N; j+=i){

				totient[j] *= i-1;
				totient[j] /= i;
			}
			totient[i] = i-1;
		}
	}
	No_da_pilhaBC *aux;
	aux = p->topo;

	printf("\t-------------totientient-------------!\n");
	while(aux != p->base){

		Desempilhar(p, &aux->data);
        
		printf("%d\n", totient[aux->data.val]);
		aux = aux->prox;
	}
	
}

void Resposta2c(){

    Pilha p;
			
			srand((unsigned)time(NULL));

			for (int i = 0; i < 20; i++){

				Valor_da_PilhaBC d;
				d.val = (rand()%99)+1;
				Empilhar(&p, d);
			}

			printf("Pilha: \n");
			imprime(&p);
			printf("\n\n");
			totient(&p);
}