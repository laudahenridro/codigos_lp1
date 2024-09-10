#include <stdio.h>

int bissexto(int,int*);

int main(){
    int i;
    int dia = 0;
    int mes = 0;
    int ano = 0;
    int result = 0;
    scanf("%d %d %d",&dia,&mes,&ano);
    for(i=1;i<=mes;i++){
        if (i==mes){
            result+=dia;
        }
        else{
            while(i<8){
                if((i%2)==1){
                    result+=31;
                }
                else{
                    if (i==2){
                    result+=28;
                    }
                    else{
                        result+=30;
                    }
                }
            }
            if((i%2)==0){
                result+=30;
            }
            else{
                result+=31;
            }
        }
    }    
    bissexto(ano,&result);
    printf("%d\n",result);
    return 0;
