#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int valor;
    struct arv * esq;
    struct arv * dir;
}Arv;

Arv* criaFolha(int info) {
   Arv* folha = (Arv*) malloc(sizeof(Arv));
   folha->valor = info;
   folha->esq = NULL;
   folha->dir = NULL;
   return folha;
}

Arv * criar(Arv *arvore,int numero){
    if(arvore == NULL){
        return criaFolha(numero);
    }else if(arvore->valor == numero){
        return arvore;
    }else if(arvore->valor < numero){
        arvore->dir = criar(arvore->dir,numero);
    }else{
        arvore->esq = criar(arvore->esq,numero);
    }
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


