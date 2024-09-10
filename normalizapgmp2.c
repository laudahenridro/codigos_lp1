#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int leituraCabecalho(int*, int*, FILE*);
float** criacaoMatriz(int, int);
float preencheMatriz(float**, int, int, FILE*);
float desvioPadrao(float**, int, int, float, FILE*);
float normalizaMatriz(float**, int, int, float, float, FILE*);


int main(){
	
	int linha = 0, coluna = 0;
	float** M, mediaPixels = 0, resDesvioPadrao = 0;;
	FILE* fp = NULL;
	char nome[256];
	
	scanf("%s", nome);
	
	if((fp=fopen(nome,"r"))==NULL){
        	printf("Erro: arquivo inexistente\n");
        	return 1;
	}
	
	leituraCabecalho(&linha, &coluna, fp);
	M = criacaoMatriz(linha, coluna);
	mediaPixels = preencheMatriz(M, linha, coluna, fp);
	resDesvioPadrao = desvioPadrao(M, linha, coluna, mediaPixels, fp);
	normalizaMatriz(M, linha, coluna, mediaPixels, resDesvioPadrao, fp);
	
	
	
	for(int j = 0; j<linha; j++){
        	for(int k = 0; k<coluna; k++){
            		if(k == ((coluna)-1)){
                		printf("%.4f\n",M[j][k]);
            		}	
            		else{
                		printf("%.4f ",M[j][k]);
            		}	
        	}	
    	}
    	
	
	
	if(fclose(fp)!=0){
        	perror("Erro: não foi possível fechar o arquivo");
        	return 2;
    	}	
    
 	return 0;   
}

int leituraCabecalho(int* linha, int* coluna, FILE* fp){

	char frase[256];
	for(int i = 0; i<4; i++){
		fgets(frase, 255, fp);
		if(i == 2){
			sscanf(frase,"%d %d", coluna, linha);
		}
	}
	
}

float** criacaoMatriz(int linha, int coluna){
	
	float** M = malloc(linha*sizeof(*M));
	
	for(int i = 0; i<linha; i++){
		M[i] = malloc(coluna*sizeof(**M));
	}
	
	return M;
}

float preencheMatriz(float** M, int linha, int coluna, FILE* fp){
	float somatorio = 0, temp = 0;
	
	for(int i = 0; i<linha; i++){
		for(int j = 0; j<coluna; j++){
			fscanf(fp,"%f", &temp);
			M[i][j] = temp;
			somatorio += temp;
		}
	}
	
	return (somatorio/(linha*coluna));
}

float desvioPadrao(float**M, int linha, int coluna, float mediaPixels, FILE* fp){
	
	float somatorioDP = 0, resPow = 0, resSqrt;
	
	for(int i = 0; i<linha; i++){
		for(int j = 0; j<coluna; j++){
			resPow = pow ((M[i][j] - mediaPixels), 2);
			somatorioDP += resPow;
		}
	}
	
	resSqrt = sqrt (somatorioDP/(linha*coluna-1));
 	return resSqrt; 
}

float normalizaMatriz(float** M, int linha, int coluna, float mediaPixels, float resDesvioPadrao, FILE* fp){
	
	for(int i = 0; i<linha; i++){
		for(int j = 0; j< coluna; j++){
			M[i][j] = ((M[i][j] - mediaPixels)/resDesvioPadrao);
		}
	}
}

