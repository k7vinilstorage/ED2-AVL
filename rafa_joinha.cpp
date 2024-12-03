#include <iostream>

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

typedef struct avl_tree {
    int no;
    struct avl_tree* esq;
    struct avl_tree* dir;
}avl;

void cria_folha(int valor){
    avl* no_prim = (avl*)malloc(sizeof(avl));
    no_prim->no = valor;
    no_prim->esq = NULL;
    no_prim->dir = NULL;
}

void inserir_arvore_AVL(avl* no_prim, int valor) {
    if(no_prim->no == NULL) {
        cria_folha(valor);
    }else if(no_prim->no < valor) {
        inserir_arvore_AVL(no_prim->dir, valor);
    }else {
        inserir_arvore_AVL(no_prim->esq, valor);
    }
}

int altura_avl(avl* raiz) {
    if(raiz->no == NULL) {
        return -1;
    }else {
        int dir = altura_avl(raiz->dir),
        esq = altura_avl(raiz->esq);
        if(dir > esq){
            return dir + 1;
        }else{
            return esq + 1;
        }
    }
}

int main() {
    avl* no_prim = (avl*)malloc(sizeof(avl));
    no_prim->no = NULL;


    return 0;
}