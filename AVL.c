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

Arv * inserirArv(Arv *arvore, int numero){
    if(arvore == NULL){
        return criaFolha(numero);
    }else if(arvore->valor == numero){
        return arvore;
    }else if(arvore->valor < numero){
        arvore->dir = inserirArv(arvore->dir,numero);
    }else{
        arvore->esq = inserirArv(arvore->esq,numero);
    }
}

Arv *inserir_arvore_AVL(Arv* arvore, int valor) {
    if(arvore == NULL) {
        return criaFolha(valor);
    }else if(arvore->valor < valor) {
        arvore->dir = inserir_arvore_AVL(arvore->dir, valor);
    }else {
        arvore->esq = inserir_arvore_AVL(arvore->esq, valor);
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

    pinheiro = inserir_arvore_AVL(pinheiro, 147);
    pinheiro = inserir_arvore_AVL(pinheiro, 7);
    pinheiro = inserir_arvore_AVL(pinheiro, 10);
    pinheiro = inserir_arvore_AVL(pinheiro, 15);
    pinheiro = inserir_arvore_AVL(pinheiro, 1);
    pinheiro = inserir_arvore_AVL(pinheiro, 4);
    pinheiro = inserir_arvore_AVL(pinheiro, 80);
    pinheiro = inserir_arvore_AVL(pinheiro, 9);
    
    printf("\n");

    print2DTree(pinheiro, 0);

    return 0;
}
