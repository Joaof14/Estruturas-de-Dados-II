#include <stdio.h>
#include <stdlib.h>

/* Estrutura de Nó*/

typedef struct node{
    int key;
    struct node *left;
    struct node * right;

} Node;
//declaração de funções auxiliares
int max(int a, int b){
    return (a > b) ? a : b;
}

//Declarações de funções a serem implementadas.

//Funções de travessoa
void preOrder(Node* root);
void inOrder(Node* root);
void posOrder(Node* root);


Node* createNode(int key);
//questao 1
Node* getMin(Node* root);
Node* getMax(Node* root);
Node* getSuccessor(Node* root);

//questao 2
int getSize(Node* root);
int getHeight(Node* root);
float getMedian(Node* root);

//questao 3
Node* removeMin(Node* tree);

//Questao 4
Node* changeKey(Node* root, int oldVal, int newVal);
//Questao 5
//bool isBST(Node* root);


//Questao 7
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
    int refInt;

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
    
    //Descobrir altura da árvore
    refInt = getHeight(root);
    printf("A altura é: %d\n", refInt);

    //Descobrir tamanho da árvore
    refInt = getSize(root);
    printf("O tamanho é: %d\n", refInt);

    //Funções de travessia
    printf("\nBusca em pré-ordem:");
    preOrder(root);

    printf("\nBusca em ordem:");
    inOrder(root);

    printf("\nBusca em pós-ordem:");
    posOrder(root);

    //Mediana da árvore
    printf("\n\nMediana da árvore: %.2f", getMedian(root));


}

//Criar Nó
Node *createNode(int key){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}


//Funções de travessia na arvore: pré-ordem, ordem e pós ordem:
void preOrder(Node * root){
    if (root){
        printf(" %d", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node * root){
    if(root){
        inOrder(root->left);
        printf(" %d", root->key);
        inOrder(root->right);
    }
}

void posOrder(Node * root){
    if (root){
        posOrder(root->left);
        posOrder(root->right);
        printf(" %d", root->key);
    }
}

//QUESTAO 1
Node* getMin(Node * root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

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

//QUESTAO 2
int getSize(Node *root){
    if (root == NULL) return 0;

    return 1 + getSize(root->left) + getSize(root->right);
}

int getHeight(Node *root){
    if (root == NULL) return -1;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}   

int countNodes(Node * root){
    if (root == NULL){return 0;}
    return 1 + countNodes(root->right) + countNodes(root->left);
}

void inOrderTransversal(Node * root, int * array, int*index){
    if (root == NULL){return;}

    inOrderTransversal(root->left, array, index);
    array[(*index)++] = root -> key;
    inOrderTransversal(root->right, array, index);
}

float getMedian(Node * root){
    int n = countNodes(root);
    if (n == 0) { return 0.0f;}

    int * elements = (int*)malloc(n*sizeof(int));
    int index = 0;

    inOrderTransversal(root, elements, &index);

    float median;

    if (n%2 == 1)
    {
        median = (float)elements[n/2];
    }
    else{
        median = (float)(elements[(n/2) -1] + elements[n/2]) / 2;
    }

    free(elements);
    return median;


}



//Questao 3
Node * removeMin(Node * tree){

}