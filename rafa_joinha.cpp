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

typedef struct avl_tree{
    int no;
    struct avl_tree* esq;
    struct avl_tree* dir;
}avl;




void inserir_arvore_AVL(int valor){


}



int main(){



    return 0;
}