#include <stdio.h>
#include <stdlib.h>

struct no{
	int valor;
	struct no* seguinte;
};

struct no* criaElem(int numero){
	struct no* p = malloc(sizeof(*p));
	p->valor = numero;
	p->seguinte = NULL;
	return p;
}

void insere_inicio(struct no** pp, int valor){
	struct no* elem = criaElem(valor);
	if(*pp){
		elem->seguinte = *pp;
		*pp = elem;
		
	}
	else{
		*pp = elem;
	}
}

void exclui_valor(struct no** pp, int valor){

	if(*pp){
		if((*pp)->valor == valor){
			struct no* aux = *pp;
			*pp = aux->seguinte;
			free(aux);
		}
		else{
			exclui_valor((&(*pp)->seguinte), valor);
		}
	}
}

void exclui_lista(struct no** pp){
	if(*pp){
		exclui_lista((&(*pp)->seguinte));
		free(*pp);
		*pp = NULL;
		
	}
}

void imprime(struct no* p){
	if(p){
		printf("%d ", p->valor);
		imprime(p->seguinte);
	}
	else{
		printf("\n");
	}
}


