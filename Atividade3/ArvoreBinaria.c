#include <stdio.h>
#include <stdlib.h>


/* Estrutura de Nó*/

typedef struct node{
    int key;
    struct node *left;
    struct node * right;

} Node;

//Declarações de funções implementadas.

Node* createNode(int key);
Node* getMin(Node* root);
Node* getMax(Node* root);
Node* getSuccessor(Node* root);
int getSize(Node* root);
int getHeight(Node* root);
int getMedian(Node* root);
Node* removeMin(Node* tree);
Node* changeKey(Node* root, int oldVal, int newVal);
//bool isBST(Node* root);

void insertNode (Node** node, int key); /*insertNode não possui retorno,
mas deve atualizar node (a árvore passada como parâmetro) internamente.
Exemplo de uso: 
Node* root = NULL;
insertNode(&root, 50);
insertNode(&root, 30);
insertNode(&root, 70); 
*/

int main(){
    Node * ref = NULL;

    Node * root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    //testando mínimo;
    ref = getMin(root);
    printf("O mínimo é: %d\n", ref->key);

    //Testando Sucessor do mínimo
    ref = getSuccessor(root);
    printf("O sucessor do mínimo é: %d\n", ref->key);

    //testando máximo;
    ref = getMax(root);
    printf("O máximo é: %d\n", ref->key);
    
    

}

//Criar Nó
Node *createNode(int key){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = newNode->right = NULL;
}


//Obter o mínimo
Node* getMin(Node * root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

//Obter o máximo
Node* getMax(Node * root){
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* getSuccessor(Node* root){
    Node * minNode = getMin(root);

    if (minNode == NULL) return NULL;

    if (minNode->right != NULL){
        return getMin(minNode->right); //Se tiver subárvore direita, o menor dela é o sucessor do mínimo
    }
    else{
        Node * suc = NULL;
        Node * current = root;
        while(current !=minNode)
        {
            if (minNode->key < current->key)
            {
                suc = current;
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        return suc;
    }

}

int getSize(Node *root){
    if (root == NULL) return 0;

    return 1 + size(root->left) + size(root->right);
}

int getHeight(Node* root){
    
}