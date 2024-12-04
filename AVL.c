// vinicius souza dias
// rafael munhoz castro
//arthur henrique  jardin da cunha pinto
//joão alberto torezan


//entrada 1 int por linha
//para cada valor int positivo, inserir na árvore AVL
    //cada rotação deve imprimir: 
        //RSD[valor dos nós P] "rot simples a direita"
        //RSE[valor do nó P]   "rot simples a esquerda"
        //RDD[valor do nó P]   "rot dupla a direita"
        //RDE[valor do nó P]   "rot dupla a esquerda"
//valor = 0, imprimir o balanço (-1, 0 ou 1) da raiz, excluir a árvore e iniciar nova leitura
//valor = -1, imprimir fim e finalizar o programa

//usar scranf e printf

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
        return 0;
    }
    else {
        arvore->dir = Excluir(arvore->dir);
        arvore->esq = Excluir(arvore->esq);
    }
    free(arvore);
    return NULL;
}

Arv *RSE(Arv * arvore) {
    printf("RSE %d\n", arvore->valor);
    arvore->dir->esq = arvore;
    arvore = arvore->dir;
    arvore->esq->dir = NULL;
    return arvore;
}

Arv *RSD(Arv * arvore) {
    printf("RSD %d\n", arvore->valor);
    arvore->esq->dir = arvore;
    arvore = arvore->esq;
    arvore->dir->esq = NULL;
    return arvore;
}

Arv *RDD(Arv *arvore) {
    printf("RDD %d\n", arvore->valor);
    arvore->esq->dir->dir = arvore;
    arvore->esq->dir->esq = arvore->esq;
    arvore = arvore->esq->dir;
    arvore->esq->dir = NULL;
    arvore->dir->esq = NULL;
    return arvore;
}

Arv *RDE(Arv *arvore) {
    printf("RDE %d\n", arvore->valor);
    arvore->dir->esq->esq = arvore;
    arvore->dir->esq->dir = arvore->dir;
    arvore = arvore->dir->esq;
    arvore->dir->esq = NULL;
    arvore->esq->dir = NULL;
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
        if(arvore->dir->esq == NULL) {
            arvore = RSE(arvore);
        }
        else {
            arvore = RDE(arvore);
        }
    }

    if((esquerda - direita) >= 2) {
        if(arvore->esq->dir == NULL) {
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
            printf("\nFIM\n");
            break;
        }
        else {
            pinheiro = inserirArv(pinheiro, valor);
        }
    }

    return 0;
}