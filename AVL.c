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

void print2DTree(Arv* root, int space) {
  // Caso base;
  if (root == NULL)
    return;
  // Aumento da distância entre os níveis
  space += 5;
  // Avalia primeiro o nó direita
  // Vai empilhar todas subárvores direitas;
  print2DTree(root->dir, space);
  // Imprime o nó no retorno da recursão
    for (int i = 5; i < space; i++)
      printf(" ");
  printf("%d\n", root->valor);
  // Avalia o nó esquerda
  print2DTree(root->esq, space);
}

int main() {
    Arv * pinheiro = NULL;
    int valor = 0;
   
    while(true) {
        scanf("%d", &valor);
        if(valor == 0){
            print2DTree(pinheiro, 2);
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