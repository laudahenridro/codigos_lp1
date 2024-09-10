#include <stdio.h>
#include "function.h"


int leituraCabecalho( FILE*, int*, int*, int*);

int main(){
	FILE* fp = NULL;
	struct no* phead = NULL;
	int linha = 0, coluna = 0, max = 0, numero = 0;
	
	if((fp=fopen("img.pgm","r")) == NULL){
		printf("Erro: arquivo não encontrado.\n");
		return 1;
	}
	
	leituraCabecalho(fp, &linha, &coluna, &max);
	
	for(int i = max; i> 0; i--){
		insere_inicio(&phead, i);
	}
	
	
	while(fscanf(fp, "%d", &numero) == 1){
		exclui_valor(&phead, numero);
	}
	
	imprime(phead);
	exclui_lista(&phead);
	
	
	if(fclose(fp) != 0){
		printf("Erro: não foi possível fechar o arquivo.\n");
		return 2;
	}
	
	return 0;	
	
}

int leituraCabecalho( FILE* fp, int* linha, int* coluna, int* max){
	char frase[256];
	for(int i = 0; i<3;i++){
		fgets(frase, 255, fp);
		if( i == 1){
			sscanf(frase, "%d %d", coluna, linha);
		}
		else if(i == 2){
			sscanf(frase, "%d", max);
		}
	}
}


