// Implementação do vetinput.h
#include <stdio.h>
#include <stdlib.h>

int tamanhoVetor(FILE* fp){
	int tamanho = 0;
	fscanf( fp, "%d", &tamanho);
	return tamanho;
}

float* entradaVetor(FILE* fp, int tamanho){
	float* V;
	float elemento = 0;
	int i = 0;
	
	V = malloc(tamanho*sizeof(float));
	
	for(i = 0; i<tamanho; i++){
		fscanf( fp, "%f", &elemento);
		V[i] = elemento;
	}
	
	return V;
	
}
