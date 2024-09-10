#include <stdio.h>
#include <ctype.h>

int quantidadeDePalavrasPorLetra(FILE*);

int main(){
	FILE* fp;
	fp == NULL;
	
	if((fp = fopen("texto1.txt","r")) == NULL){
		printf("Erro: o arquivo não existe.\n");
		return 1;
	}
	
	quantidadeDePalavrasPorLetra(fp);
	
	if( fclose(fp) != 0){
		printf("Erro: não foi possível fechar o arquivo.\n");
		return 2;
	}
	
	return 0;

}

int quantidadeDePalavrasPorLetra(FILE* fp){
	char texto[256];
	char c;
	int Alfabeto[25];
	int letrasAlfabeto[25];
	
	for(int i = 0; i<26; i++){
		letrasAlfabeto[i] = (i+65);
	}
	
	for(int i = 0; i<26; i++){
		Alfabeto[i] = 0;
	}
	
	while (!feof(fp)){
		fscanf(fp, "%s", texto);
		c = texto[0];
		
		switch(tolower(c)){
			case 'a' : case 'A':
				Alfabeto[0]++;
				break;
			case 'b' : case 'B':
				Alfabeto[1]++;
				break;
			case 'c' : case 'C':
				Alfabeto[2]++;
				break;
			case 'd' : case 'D':
				Alfabeto[3]++;
				break;
			case 'e' : case 'E':
				Alfabeto[4]++;
				break;
			case 'f' : case 'F':
				Alfabeto[5]++;
				break;
			case 'g' : case 'G':
				Alfabeto[6]++;
				break;
			case 'h' : case 'H':
				Alfabeto[7]++;
				break;
			case 'i' : case 'I':
				Alfabeto[8]++;
				break;
			case 'j' : case 'J':
				Alfabeto[9]++;
				break;
			case 'k' : case 'K':
				Alfabeto[10]++;
				break;
			case 'l' : case 'L':
				Alfabeto[11]++;
				break;
			case 'm' : case 'M':
				Alfabeto[12]++;
				break;
			case 'n' : case 'N':
				Alfabeto[13]++;
				break;
			case 'o' : case 'O':
				Alfabeto[14]++;
				break;
			case 'p' : case 'P':
				Alfabeto[15]++;
				break;
			case 'q' : case 'Q':
				Alfabeto[16]++;
				break;
			case 'r' : case 'R':
				Alfabeto[17]++;
				break;
			case 's' : case 'S':
				Alfabeto[18]++;
				break;
			case 't' : case 'T':
				Alfabeto[19]++;
				break;
			case 'u' : case 'U':
				Alfabeto[20]++;
				break;
			case 'v' : case 'V':
				Alfabeto[21]++;
				break;
			case 'w' : case 'W':
				Alfabeto[22]++;
				break;
			case 'x' : case 'X':
				Alfabeto[23]++;
				break;
			case 'y' : case 'Y':
				Alfabeto[24]++;
				break;
			case 'z' : case 'Z':
				Alfabeto[25]++;
				break;
				
		}	
			
	}
	for( int i = 0; i< 26; i++){
		printf("%c %d\n", letrasAlfabeto[i] , Alfabeto[i]);
	}
}
