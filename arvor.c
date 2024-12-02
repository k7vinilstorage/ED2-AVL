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
        return;
    }else if(arvore->valor < numero){
        arvore->dir = criar(arvore->dir,numero);
    }else{
        arvore->esq = criar(arvore->esq,numero);
    }
}

void print2DTree(Arv* root, int space)
{
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

int maior(Arv* arvore){
    if(arvore->dir == NULL){
        return arvore->valor;
    }else{
        return maior(arvore->dir);
    }
}

int contar(Arv * arvore){
    if(arvore == NULL){
        return 0;
    }

    return 1 + contar(arvore->dir) + contar(arvore->esq);
}

int contarNivel(Arv* arvore){
    if(arvore == NULL){
        return -1;
    }else{
        int direita = contarNivel(arvore->dir),
        esquerda = contarNivel(arvore->esq);

        if(direita > esquerda){
            return direita + 1;
        }else{
            return esquerda + 1;
        }

    }
    
}

int contarFolha(Arv* arvore){
    if(arvore != NULL){
        if(arvore->dir == NULL && arvore->esq == NULL){
            return 1;
        }
        return contarFolha(arvore->dir) + contarFolha(arvore->esq);
    }
    
    return 0;
}

int main(){
    Arv * raiz = criar(NULL,25);

    criar(raiz,36);
    criar(raiz,18);
    criar(raiz,8);
    criar(raiz,25); 
    criar(raiz,30);
    criar(raiz,31);
    criar(raiz,40);
    criar(raiz,29);
    criar(raiz,41);
    criar(raiz,42);

    print2DTree(raiz, 0);

    printf("Nos: %d",contarFolha(raiz));

    printf("\nfim");
    return 0;
}