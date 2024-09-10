#include <stdio.h>

int checaTamanhoDoVetor(int tamanhoVetor1, int tamanhoVetor2){
	if(tamanhoVetor1 == tamanhoVetor2){
		return 0;
	}
	else{
		return 1;
	}
}

float produtoEscalar(float* V, float* W, int tamanhoVetor1){
	float resultado = 0;
	
	for(int i = 0; i< tamanhoVetor1; i++){
		resultado = resultado + (V[i] * W[i]);
		
	}
	return resultado;
}
