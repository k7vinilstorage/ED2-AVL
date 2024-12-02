#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da AVL
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Função para obter a altura de um nó
int height(Node* node) {
    int altura = 0;
    if (node->left != NULL)
        altura = height(node->left) + 1;
    return node->height;
}

// Função para obter o maior entre dois números
int big(int a, int b) {
    return (a > b) ? a : b;
}

// Criação de um novo nó
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Rotação à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = big(height(y->left), height(y->right)) + 1;
    x->height = big(height(x->left), height(x->right)) + 1;

    return x; // Nova raiz
}

// Rotação à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = big(height(x->left), height(x->right)) + 1;
    y->height = big(height(y->left), height(y->right)) + 1;

    return y; // Nova raiz
}

// Calcula o fator de balanceamento
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para inserir um nó na AVL
Node* insert(Node* node, int value) {
    // Realiza a inserção normal de uma BST
    if (node == NULL)
        return createNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node; // Não são permitidos valores duplicados

    // Atualiza a altura do nó atual
    node->height = 1 + big(height(node->left), height(node->right));

    // Obtém o fator de balanceamento
    int balance = getBalance(node);

    // Caso 1: Esquerda-Esquerda
    if (balance > 1 && value < node->left->value)
        return rotateRight(node);

    // Caso 2: Direita-Direita
    if (balance < -1 && value > node->right->value)
        return rotateLeft(node);

    // Caso 3: Esquerda-Direita
    if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso 4: Direita-Esquerda
    if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Retorna o nó (inalterado se estiver balanceado)
}

// Função para imprimir a AVL em pré-ordem
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Programa principal
int main() {
    Node* root = NULL;

    // Sequência de inserção
    int values[] = {70, 60, 40, 20, 65, 50, 10, 25, 28, 27, 75, 62};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Pre-ordem da AVL resultante:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
