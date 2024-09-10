#include <stdio.h>
#include <stdlib.h>

struct armazenaNum{
    int num;
    struct armazenaNum* next;
};

struct armazenaNum* criaElem(int);
struct armazenaNum* insereOrdenado(struct armazenaNum** , int);
int imprimeLista(struct armazenaNum*);
int limparLista(struct armazenaNum**);
int tamanhoLista(struct armazenaNum*, int*);
int mediana(struct armazenaNum*, int);

int main(){
	
	FILE* fp = NULL;
	int num = 0, tamanho = 0;
	struct armazenaNum* phead = NULL;
	
	if((fp = fopen("teste.txt","r")) == NULL){
		printf("Erro: o arquivo não existe.\n");
		return 1;
	}
	
	while(fscanf(fp, "%d", &num) == 1){
	    insereOrdenado(&phead, num);
	}
	
	imprimeLista(phead);
	tamanhoLista(phead, &tamanho);
	mediana(phead, tamanho);
	limparLista(&phead);
	
	
	if(fclose(fp) != 0){
		printf("Erro: não foi possível fechar o arquivo.\n");
		return 2;
	}
	
	return 0;
}

struct armazenaNum* criaElem(int numero){
    struct armazenaNum* p = malloc(sizeof(*p));
    p->num = numero;
    p->next = NULL;
    return p;
}

struct armazenaNum* insereOrdenado(struct armazenaNum** p, int numero){
    struct armazenaNum* elem = criaElem(numero);
    if(*p){
        if(((*p)->num) <= numero){
            insereOrdenado(&((*p)->next), numero);
        }
        else{
            elem->next = *p;
            *p = elem;
        }
    }
    else{
        elem->next = *p;
        *p = elem;
    }
}

int imprimeLista(struct armazenaNum* p){
    if(p){
        printf("%d\n", p->num);
        imprimeLista(p->next);
    }
    else{
        printf("Fim da lista\n");
    }
    
}

int limparLista(struct armazenaNum** p){
    if(*p){
        limparLista(&((*p)->next));
        free(*p);
        *p = NULL;
    }
}

int tamanhoLista(struct armazenaNum* p, int* tamanho){
    if(p){
        (*tamanho)++;
        tamanhoLista(p->next, tamanho);
        
    }
        
}

int mediana(struct armazenaNum* p, int tamanho){
    
    int mediana = tamanho/2;
    
    for(int i = 0; i < mediana; i++){
        if(p){
            p = p->next;
        }
    }
    printf("%d\n", p->num);
}
    


