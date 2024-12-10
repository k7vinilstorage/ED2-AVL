// vinicius souza dias 2562599
// rafael munhoz castro 2564380
// arthur henrique jardim  da cunha pinto 2564300
// joão alberto benaci torezan 2564386

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arv{
    int valor;
    struct arv * esq;
    struct arv * dir;
}Arv;

Arv* criaFolha(int info) {
   Arv* folha = (Arv*)malloc(sizeof(Arv));
   folha->valor = info;
   folha->esq = NULL;
   folha->dir = NULL;
   return folha;
}

int altura(Arv* arvore){
    if(arvore == NULL){
        return 0;
    }
    else {
        int direita = altura(arvore->dir);
        int esquerda = altura(arvore->esq);

        if(direita > esquerda){
            return direita + 1;
        }
        else {
            return esquerda + 1;
        }
    } 
}

Arv *Excluir(Arv* arvore) {
    if(arvore == NULL) {
        return NULL;
    }
    else {
        arvore->dir = Excluir(arvore->dir);
        arvore->esq = Excluir(arvore->esq);
    }
    free(arvore);
    return NULL;
}

Arv *RSE(Arv * arvore) {
    Arv *aux;

    printf("RSE %d\n", arvore->valor);
    aux = arvore->dir->esq;
    arvore->dir->esq = arvore;
    arvore = arvore->dir;
    arvore->esq->dir = aux;
    return arvore;
}

Arv *RSD(Arv * arvore) {
    Arv *aux;
    
    printf("RSD %d\n", arvore->valor);
    aux = arvore->esq->dir;
    arvore->esq->dir = arvore;
    arvore = arvore->esq;
    arvore->dir->esq = aux;
    return arvore;
}

Arv *RDD(Arv *arvore) {
    Arv *aux1;
    Arv *aux2;

    printf("RDD %d\n", arvore->valor);
    aux1 = arvore->esq->dir->esq;
    aux2 = arvore->esq->dir->dir;
    arvore->esq->dir->dir = arvore;
    arvore->esq->dir->esq = arvore->esq;
    arvore = arvore->esq->dir;
    arvore->esq->dir = aux1;
    arvore->dir->esq = aux2;
    return arvore;
}

Arv *RDE(Arv *arvore) {
    Arv *aux1;
    Arv *aux2;

    printf("RDD %d\n", arvore->valor);
    aux1 = arvore->dir->esq->dir;
    aux2 = arvore->dir->esq->esq;
    arvore->dir->esq->esq = arvore;
    arvore->dir->esq->dir = arvore->dir;
    arvore = arvore->dir->esq;
    arvore->dir->esq = aux1;
    arvore->esq->dir = aux2;
    return arvore;
}

Arv *inserirArv(Arv* arvore, int valor) {
    if(arvore == NULL) {
        return criaFolha(valor);
    }
    else if(arvore->valor < valor) {
        arvore->dir = inserirArv(arvore->dir, valor);
    }
    else {
        arvore->esq = inserirArv(arvore->esq, valor);
    }

    int direita = altura(arvore->dir);
    int esquerda = altura(arvore->esq);

    if((direita - esquerda) >= 2) {
        direita = altura(arvore->dir->dir);
        esquerda = altura(arvore->dir->esq);

        if((direita - esquerda) >= 0) {
            arvore = RSE(arvore);
        }
        else {
            arvore = RDE(arvore);
        }
    }

    if((esquerda - direita) >= 2) {
        esquerda = altura(arvore->esq->esq);
        direita = altura(arvore->esq->dir);

        if((esquerda - direita) >= 0) {
            arvore = RSD(arvore);
        }
        else {
            arvore = RDD(arvore);
        }
    }

    return arvore;
}

void printBal(Arv *arvore) {
    int altura_dir = 0;
    int altura_esq = 0;

    altura_dir = altura(arvore->dir);
    altura_esq = altura(arvore->esq);
    printf("Bal = %d\n", (altura_dir - altura_esq));
}

int main() {
    Arv * pinheiro = NULL;
    int valor = 0;
   
    while(true) {
        scanf("%d", &valor);
        if(valor == 0){
            printBal(pinheiro);
            pinheiro = Excluir(pinheiro);
        }
        else if(valor == -1) {
            printf("FIM\n");
            break;
        }
        else if(valor > 0){
            pinheiro = inserirArv(pinheiro, valor);
        }
    }

    return 0;
}