#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 4

typedef struct Tfila {
    int data[MAXTAM];
    int fim;
    int ini;
}Tfila;

void inicia_fila(Tfila *f){
    int i;
    for(i=0;i<MAXTAM;i++){
        f->data[i] = 0;
    }
    f->fim = 0;
}

void enfil(int dado, Tfila *f){
    if(f->fim == MAXTAM){
        printf("fila cheia\n\n");
        return;
    } else{
        f->data[f->fim] = dado;
        f->fim++;
    }
}

void desenfil(Tfila *f){
    int data_1, i;
    if (f->fim == 0){
        printf("fila vazia\n\n");
        return;
    } else{
        data_1 = f->data[0];
        for(i=0;i<f->fim;i++){
            f->data[i] = f->data[i+1];
        }
        f->fim--;
        return data_1;
    }
    
}

void imprim(Tfila *f){
    int i;
    printf("Fila: ");
    for(i=0;i<f->fim;i++){
        printf("%d ", f->data[i]);
    }
    printf("\n\n");
}

int main(){
    Tfila f1;
    inicia_fila(&f1);
  
    return 0;
}