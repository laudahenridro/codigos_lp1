// Código que faz a leitura de uma imagem PGM do tipo P2 caso ele exista, com nome do arquivo inserido pelo usuário, e a imprime no monitor.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int leituraCabecalho(int*, int*, int*, FILE*);
int** criacaoMatriz(int, int);
int preencheMatriz(int**, int, int, int, FILE*);

int main(){
    int linha, coluna, pixel;
    int** M;
    FILE* fp = NULL;
    char nome[256];
    
    scanf("%s", nome);
    
    if((fp=fopen(nome,"r"))==NULL){
        printf("Erro: arquivo inexistente\n");
        return 1;
    }
    
    leituraCabecalho(&linha, &coluna, &pixel, fp);
    M = criacaoMatriz(linha, coluna);
    preencheMatriz(M, linha, coluna, pixel, fp);

    //Impressão da imagem PGM
    for(int j = 0; j<(linha); j++){
        for(int k = 0; k<(coluna); k++){
            if(k == ((coluna)-1)){
                printf("%3X\n",M[j][k]);
            }
            else{
                printf("%3X ",M[j][k]);
            }
        }
    }

    
    if(fclose(fp)!=0){
        perror("Erro: não foi possível fechar o arquivo");
        return 2;
    }
    
    return 0;
}

int leituraCabecalho(int* linha, int* coluna, int* pixel, FILE*fp){
    char frase[256];
    int i = 0;
    for(i = 0;i<4;i++){
        fgets(frase, 255, fp);
        if(i == 2){
            sscanf(frase,"%d %d", coluna, linha);
        }
        else if(i == 3){
            sscanf(frase,"%d", pixel);
        }
    }
}

int** criacaoMatriz(int linha, int coluna){
    int i = 0, j = 0, k = 0;
    int** M;
    
    M = malloc(linha*sizeof(int*));
    
    for(int i = 0; i<linha;i++){
        M[i] = malloc(coluna*sizeof(int));
    }
    
    return M;

}

int preencheMatriz(int** M, int linha, int coluna, int pixel, FILE* fp){
    
    int i = 0, j = 0, temp = 0;
    for(i = 0; i<linha; i++){
        for(j = 0; j<coluna; j++){
            fscanf(fp,"%d", &temp);
            M[i][j] = temp;
        }    
    }
    
}
