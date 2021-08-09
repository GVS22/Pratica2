#include "lista.h"

void lista_vazia(L1 *l){

	l->primeiro = 0;
	l->ultimo  = 0;
}

void  inserir_lista(L1 *l, Valor d){

	if (l->ultimo >= Tamanho_Maximo1){

		printf("LISTA CHEIA!\n");

	}else{

		l->vet[l->ultimo] = d;
		l->ultimo ++;
	}
}

void imprimir_lista(L1 *l){

    for(int i = l->primeiro; i < l->ultimo; i++){

		printf("%d:%d\t", i,l->vet[i].val);
		printf("\n");
	}
}

void Lista_dois_vazia(L2 *l){

	l->primeiro = 0;
	l->ultimo  = 0;
}

void Lista_dois_Insere(L2 *l, Valor d){

	if (l->ultimo >= Tamanho_Maximo2){

		printf("LISTA CHEIA!\n");

	}else{

		l->vet[l->ultimo] = d;
		l->ultimo ++;
	}
}

void Imprimir_Lista_dois(L2 *l1, L2 *l2){

    for(int i = l1->primeiro; i < l1->ultimo; i++)

		printf("(%d,%d)\t", l1->vet[i].val, l2->vet[i].val);

	printf("\n");
}

void Lista_dois(L2 *l1, L2 *l2){

	int aux1 = 0;

	srand((unsigned)time(NULL));

	while(aux1 != Tamanho_Maximo2){

		Valor d;
		d.val = rand()%13;
		if(d.val != 0){

			 inserir_lista_dois(l1, d);
			aux1++;
		}
	}

	int aux2 = 0;
	while(aux2 != Tamanho_Maximo2){

		Valor d;
		d.val = rand()%13;
		if(d.val != 0){

			inserir_lista_dois(l2, d);
			aux2++;
		}
	}	
}

void Swap(Valor *a, Valor *b){

	Valor aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void Lista_dois_Remove(L2 *l){

	bool ok = false;

	if(l->primeiro == l->ultimo)

		printf("LISTA VAZIA!\n");

	else{

		for(int i=l->primeiro; i<l->ultimo; i++){

			Swap(&l->vet[i], &l->vet[i+1]);
			ok = true;	
		}
		if(ok)

			l->ultimo --;
	}
}




//1a

void LetraA(L1 *par, L1 *imp, L1 *conc){

	int aux1 = 0;

	srand((unsigned)time(NULL));

	while(aux1 != Tamanho_Maximo1){

		Valor d;
		d.val = rand()%99;
		if(d.val % 2 == 0 && d.val != 0){

			ListInsert(par, d);
			aux1++;
		}
	}

	int aux2 = 0;
	while(aux2 != Tamanho_Maximo1){

		Valor d;
		d.val = rand()%99;
		if(d.val % 2 == 1 && d.val != 0){

			ListInsert(imp, d);
			aux2++;
		}
	}

	char str[10];
	int result;
	for(int i = par->primeiro; i < par->ultimo; i++){

		Valor c;
		sprintf(str, "%d%d",  par->vet[i].val, imp->vet[i].val);
		result = strtol(str, NULL, 10);
		c.val = result;
		inserir_lista(conc, c);
	}
}

void letraB(L2 *l1, L2 *l2, L2 *l3, L2 *l4, int aleatorio){

	int A = 0;
	int B = 0;
	int vetorA[3],vetorB[3];

	for(int i = l1->primeiro; i < l1->ultimo; i++){
		vetorA[i] = aleatorio - l1->vet[i].val;
		A = A+(aleatorio - l1->vet[i].val);
	}
	for(int i = l2->primeiro; i < l2->ultimo; i++){
		vetorB[i] = aleatorio - l2->vet[i].val;
		B = B+(aleatorio - l2->vet[i].val); 
	}

	for(int i = 0; i < Tamanho_Maximo2; i++){

		Valor v;
		v.val = vetorA[i];

		inserir_lista_dois(l3, v);
	}
	for(int i = 0; i < Tamanho_Maximo2; i++){
		Valor d;
		d.val = vetorB[i];

		inserir_lista_dois(l4, d);
	}

	if(A > B){
		printf("L1 Venceu! \n\n");
	}else if(B > A){
		printf("L2 Vence! \n\n");
	}else if(A == B){
		printf("Empate!");
	}
	
	imprimir_Lista_dois(l3,l4);
}

void Resposta1A(){
	L1 par;
    		L1 impar;
    		L1 c;

    		lista_vazia(&par);
    		lista_vazia(&impar);
    		lista_vazia(&c);

    		letraA(&par, &impar, &c);
			printf("\t______________________________\n");
			printf("\tLista Par: \n");
			imprimir_lista(&par);
			printf("\t______________________________\n");
			printf("Lista Impar: \n");
			imprimir_lista(&impar);
			printf("\t______________________________\n");
			printf("Lista catenada: \n");
			imprimir_lista(&c);
			printf("\t______________________________\n");
}

void Resposta1B(){

	L2 l1, l2, l3, l4;

			Lista_dois_vazia(&l1);
			Lista_dois_vazia(&l2);
			Lista_dois_vazia(&l3);
			Lista_dois_vazia(&l4);
			Lista_dois(&l1, &l2);
			printf("L1 & L2: \n\n");
			imprimir_Lista_dois(&l1, &l2);

			srand((unsigned)time(NULL));
			int aleatorio = (rand()%12)+1;
			printf("\t______________________________\n");
			printf("NUMERO aleatorio: %d", aleatorio);
			printf("\n\n");

			letraB(&l1, &l2, &l3, &l4, aleatorio);
}