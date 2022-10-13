#include <stdio.h>
#include <stdlib.h>
#define M_TM 100

typedef struct{
  int data[M_TM];
  int top;
} Pilha;

void Pilha_ini(Pilha *p){
    p->top = -1;
}

int Pilha_vazia(Pilha *p){
    if(p->top == -1){
        return 1;
    } else{
        return 0;
    }
}

int Pilha_cheia(Pilha *p){
    if(p->top == M_TM-1){
        return 1;
    } else{
        return 0;
    }
}

void Pilha_entra(Pilha *p, int n){
    if(Pilha_cheia(p) == 1){
        printf("PIlha cheia\n");
    } else{
        p->top++;
        p->data[p->top] = n;
    }
}

int Pilha_sai(Pilha *p){
    int m;
    if(Pilha_vazia(p) == 1){
        printf("Pilha vazia\n");
    } else{
        m = p->data[p->top];
        p->top--;
        return m;
    }
}

void imprim(Pilha *p){
    int i;
    printf("Pilha:\n ");
    for(i=0;i<=p->top;i++){
        printf("%d\n ", p->data[i]);
    }
}


int main(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    Pilha_ini(p);

    free(p);
    return 0;
}