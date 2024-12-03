// vinicius souza dias
// rafael munhoz castro
//arthur henrique  jardin da cunha pinto
//joão alberto torezan

#include <stdio.h>
#include <stdlib.h>

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

Arv *inserirArv(Arv* arvore, int valor) {
    if(arvore == NULL) {
        return criaFolha(valor);
    }else if(arvore->valor < valor) {
        arvore->dir = inserirArv(arvore->dir, valor);
    }else {
        arvore->esq = inserirArv(arvore->esq, valor);
    }
    return arvore;
}

int altura(Arv* arvore){
    if(arvore == NULL){
        return -1;
    }else{
        int direita = altura(arvore->dir),
        esquerda = altura(arvore->esq);

        if(direita > esquerda){
            return direita + 1;
        }else{
            return esquerda + 1;
        }
    } 
}

void printArv(Arv* arvore, int space) {
    if (arvore == NULL) {
        return;
    }
    space += 5;

    printArv(arvore->dir, space);

    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", arvore->valor);

    printArv(arvore->esq, space);
}


int main() {

    Arv * pinheiro = NULL;

    pinheiro = inserirArv(pinheiro, 147);
    pinheiro = inserirArv(pinheiro, 7);
    pinheiro = inserirArv(pinheiro, 10);
    pinheiro = inserirArv(pinheiro, 15);
    pinheiro = inserirArv(pinheiro, 1);
    pinheiro = inserirArv(pinheiro, 4);
    pinheiro = inserirArv(pinheiro, 80);
    pinheiro = inserirArv(pinheiro, 9);
    
    printf("\n");

    printArv(pinheiro, 0);

    return 0;
}
