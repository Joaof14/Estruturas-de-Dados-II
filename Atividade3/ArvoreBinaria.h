#ifndef ARVOREBINARA_H
#define ARVORE_BINARIA_H


/* Estrutura de Nó*/

typedef struct node{
    int key;
    struct node *left;
    struct node * right;

} Node;


//Declarações de funções a serem implementadas.

//Funções de travessoa
void preOrder(Node* root);
void inOrder(Node* root);
void posOrder(Node* root);


Node* createNode(int key);
//questão 1
Node* getMin(Node* root);
Node* getMax(Node* root);
Node* getSuccessor(Node* root);

//questão 2
int getSize(Node* root);
int getHeight(Node* root);
float getMedian(Node* root);

//questão 3
Node* removeMin(Node* tree);

//Questão 4
Node* changeKey(Node* root, int oldVal, int newVal);
//Questão 5
bool isBST(Node* root);

//Questão 6
Node * insertNodeIter (Node* node, int key);

//Questão 7
void insertNodeRef(Node** node, int key); /*insertNode não possui retorno,
mas deve atualizar node (a árvore passada como parâmetro) internamente.
Exemplo de uso: 
Node* root = NULL;
insertNode(&root, 50);
insertNode(&root, 30);
insertNode(&root, 70); 
*/

//Questão 8
Node * SearchIter(Node * root, int key);

#endif