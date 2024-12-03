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
    }else{
        int direita = altura(arvore->dir);
        int esquerda = altura(arvore->esq);

        if(direita > esquerda){
            return direita + 1;
        }else{
            return esquerda + 1;
        }
    } 
}

Arv *inserirArv(Arv* arvore, int valor) {
    if(arvore == NULL) {
        return criaFolha(valor);
    }else if(arvore->valor < valor) {
        arvore->dir = inserirArv(arvore->dir, valor);
    }else {
        arvore->esq = inserirArv(arvore->esq, valor);
    }

    int direita = altura(arvore->dir),
    esquerda = altura(arvore->esq);

    printf("%d, d: %d, e: %d\n",arvore->valor, direita, esquerda);
    
    if((direita - esquerda) >= 2) {
        printf("direita\n");
    }
     if((esquerda - direita) >= 2) {
        printf("esquerda\n");
    }
    printf("\n");
    return arvore;
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

    pinheiro = inserirArv(pinheiro, 14);
    pinheiro = inserirArv(pinheiro, 7);
    pinheiro = inserirArv(pinheiro, 10);
    pinheiro = inserirArv(pinheiro, 15);
    pinheiro = inserirArv(pinheiro, 1);
    pinheiro = inserirArv(pinheiro, 4);
    pinheiro = inserirArv(pinheiro, 80);
    pinheiro = inserirArv(pinheiro, 9);
    
    printf("\n");

    printArv(pinheiro, 0);
    printf("\n");



/* 
Arv * pinheiro = NULL;
int valor = 0;

while(){
    scanf("%d", &valor);

    if(valor == 0){

        // imprimir o balanço (-1, 0 ou 1) da raiz, excluir a árvore e iniciar nova leitura

    }else if(valor == -1){
        printf("\n FIM");
        break;
    }else{
        pinheiro = inserirArv(pinheiro, valor);
    }
}
*/

    return 0;
}
