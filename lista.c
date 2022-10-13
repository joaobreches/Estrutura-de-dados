#include <stdio.h>
#include <stdlib.h>

typedef struct Lponto{
    int valor;
    struct Lponto *next;
}Lponto;

typedef struct{
    Lponto *ini;
    int tam;
}List;

void List_inicia(){
    List lista;

    lista.ini = NULL;
    lista.tam = 0;
}

void inserir(List *lista, int valor){
    Lponto *new = (Lponto*)malloc(sizeof(Lponto));
    new->valor = valor;
    new->next = lista->ini;
    lista->ini = new;
    lista->tam++;
}

void inserir_final(List *lista, int valor){
    Lponto *no, *new = (Lponto*)malloc(sizeof(Lponto));
    new->valor = valor;
    new->next = NULL;

    if(lista->ini == NULL){
        lista->ini = new;
    }else{
        no = lista->ini;
        while (no->next != NULL)
            no = no->next;    
        no->next = new; 
    }
    lista->tam++;

}

void Remove_list(List *lista, int valor){
    Lponto *ini = lista->ini;
    Lponto * removido = NULL;
    if(lista-> ini != NULL && lista->ini->valor == valor){
        removido = lista->ini;
        lista->ini = removido->next;
    }else{
        while (ini != NULL && ini->next != NULL && ini->next->valor != valor){
            ini = ini->next;
        }
        if(ini != NULL && ini->next != NULL){
            removido = ini->next;
            ini->next = removido->next;
        }
    }
    if(removido){
        free(removido);
        lista->tam--;
    }
}


void impri(List *lista){
    Lponto *ini = lista->ini;
    while (ini != NULL){
        printf("%d ", ini->valor);
        ini = ini->next;
    }
    printf("\n\n");  
}


int main(){
  List lista;
  int opc, valor;
  List_inicia();
  do{
    printf("1- Inserir no início\n2- Imprimir\n3- Inserir no fim\n4- Remover\n5- Sair\n");
    scanf("%d", &opc);
    switch (opc){
      case 1:
        printf("Valor a ser inserido: ");
        scanf("%d", &valor);
        inserir(&lista, valor);
        break;
      case 2:
        impri(&lista);
        break;
      case 3:
        printf("Valor a ser inserido: ");
        scanf("%d", &valor);
        inserir_final(&lista, valor);
        break;
      case 4:
        printf("Valor a ser removido: ");
        scanf("%d", &valor);
        Remove_list(&lista, valor);
        break;
      case 5:
        printf("Encerrando\n");
      default:
        printf("Erro\n");
        break;
      }
    }while(opc != 5);

    


    return 0;
}