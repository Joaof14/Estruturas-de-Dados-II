#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

int main(){
    Node * ref = NULL;
    int refInt;

    Node * root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->right->left = createNode(12);
    root->right->right = createNode(18);


    //Funções de travessia
    printf("\nBusca em pré-ordem:");
    preOrder(root);

    printf("\nBusca em ordem:");
    inOrder(root);

    printf("\nBusca em pós-ordem:");
    posOrder(root);


    //Questão 1:
    printf("\n\nQuestão 1\n");
    //Mínimo e sucessor do mínimo
    ref = getMin(root);
    printf("O mínimo é: %d\n", ref->key);

    ref = getSuccessor(root);
    printf("O sucessor do mínimo é: %d\n", ref->key);

    //Plus: Máximo
    ref = getMax(root);
    printf("O máximo é: %d\n", ref->key);
    

    //Questão 2:
    printf("\n\nQuestão 2\n");
    //Descobrir altura da árvore
    refInt = getHeight(root);
    printf("A altura é: %d\n", refInt);

    //Descobrir tamanho da árvore
    refInt = getSize(root);
    printf("O tamanho é: %d\n", refInt);

    //Mediana da árvore
    printf("\n\nMediana da árvore: %.2f", getMedian(root));


    ////Questão 7: Inserção por passagem de referencia
    printf("\n\nQuestão 7: Inserção por passagem de referencia\n");
    insertNodeRef(&root, 50);
    insertNodeRef(&root, 30);
    insertNodeRef(&root, 70); 
    inOrder(root);
    

    //Questão 4 -----

    //Questão 3 remoção de mínimo:
    printf("\n\nQuestão 3 remoção de mínimo\n");
    printf("\nBusca em ordem após remover mínimo:");
    Node * min = removeMin(root);
    inOrder(root);

    //Questão 5: BST
    printf("\n\n//Questão 5: BST\n");
    printf("Árvore é BST?: %d", isBST(root));

    /*printf("\nBusca em ordem após remover mínimo:");
    min = removeMin(root);
    inOrder(root);

    printf("\nÁrvore é BST após remover mínimo?: %d", isBST(root));*/

    //Questão 6: inserção iterativa
    printf("\n\nQuestão 6: inserção iterativa\n");
    root = insertNodeIter(root, 38);
    printf("Árvore após inserir nó 50:\n");
    preOrder(root);

    



    //Questão 8: Busca iterativa;
    printf("\n\nQuestão 8: Busca iterativa\n");
    ref = SearchIter(root, 18);
    ref = SearchIter(root, 122);

    free(ref);

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

//QUESTão 1
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

//QUESTão 2
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



//Questão 3
Node * removeMin(Node * tree){
    if (tree == NULL){return NULL;} // se a raíz é nula retorna nulo
    
    //Se não tem filho esquerdo, ele é o mínimo.
    if (tree->left == NULL){ // se for a raíz retorna nulo (remove)
        Node * rightC = tree->right;
        free(tree);
        return rightC;
    }

    tree->left = removeMin(tree->left);
    return tree;
    
    /* Abordagem iterativa
    if (tree == NULL) {
        return NULL;
    }

    Node * min = getMin(tree);
    if (min == tree) {
        Node * newRoot = tree->right;
        free(tree);
        return newRoot;
    }

    Node * father = tree;
    while (father->left != min) {
        father = father->left;
    }

    if (min->right == NULL) {
        father->left = NULL;
    } else {
        father->left = min->right;
    }

    free(min);
    return tree;
}*/
    
    
}


//Questão 4

//função de busca de nó
Node * search(Node* root, int key){
    if (root = NULL) {
        printf("Nó não encontrado!");
        return NULL;
    }
    if (key < root->key){return root;}
    else if (key > root->key){
        root = search(root->right, key);
    }
    else{root = search(root->left, key);}
    return root;
    
}

Node * removeNode(Node* root, int key){
    if (root == NULL){
        return NULL;
    }
    if (key > root->key){
        root->right = removeNode(root->right, key);
    }
    else if (key < root->key){
        root->left = removeNode(root->right, key);
    }
    else{
        if (root->left == NULL){
            Node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node * temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node * temp = getMin(root->right);
            root->key = temp->key;
            root->right = removeNode(root->right, temp->key);
        }
    }

}

Node * insertNode(Node* root, int key){
    if(root == NULL){
        Node * newNode = createNode(key);
        return newNode;
    }
    if(key > root->key){
        root->right = insertNode(root->right, key);
    }
    else if(key < root->key){
        root->left = insertNode(root->left, key);
    }
    else{
        printf("Erro, nó ja existe!\n");
    }
    return root;

}


/*Node* changeKey(Node* root, int oldVal, int newVal){
    if (root == NULL) return NULL;

    if (oldVal > root->key){
        if (newVal >= root->key){
            root->right = changeKey(root->right, oldVal, newVal);
        }
        else{
            printf("Erro: Nova chave quebra a propriedade BST\n");
            return root;
        }
        
    }
    else if (oldVal < root->key){
        if (newVal <= root->key){
            root->left = changeKey(root->left, oldVal, newVal);
            return root;
        }
        else{
            printf("Erro: Nova chave quebra a propriedade BST\n");
            return root;
        }
        
    }
    else{

        int maxLeft = (root->left != NULL) ? getMax(root->left) : INT_MIN;
        int minRight = (root->right != NULL) ? getMin(root->right) : INT_MAX;

        if (newVal >= maxLeft && newVal <= minRight)
        {root->key = newVal;}
        else{
            printf("Erro: Nova chave quebra a propriedade BST\n");
        }
    }
    return root;
}
*/

bool isBST(Node * root){
    if (root == NULL){
        return true;
    }

   int rightV = (root->right != NULL) ? getMin(root->right)->key : INT_MAX;
    int leftV  = (root->left  != NULL) ? getMax(root->left)->key  : INT_MIN;
    if ( rightV > root->key && leftV < root->key){
        return true & isBST(root->right) && isBST(root->left);
    }
    return false;
}



//Questão 6
Node * insertNodeIter (Node* node, int key){

    if (node == NULL){
        
        return createNode(key);
    }

    Node * current = node;

    while(current!= NULL){
        
        if (key > current->key){

            if (current->right != NULL) {current = current->right;}

            else {
                current->right = createNode(key);
                break;
            }

        }

        else if (key < current->key){

            if (current->left != NULL){current = current->left;}
            else{
                current->left = createNode(key);
                break;
                }
        }
        else{
            printf("\nNó com esse valor ja existe!. Nessa versão não são aceitas duplicatas!");
            break;
        }
    }
    return node;
}

//Questão 7
void insertNodeRef(Node** node, int key){
    if (*node == NULL){
        *node = createNode(key);
        return;
    }

   Node * current = *node;

    while(current!= NULL){
        
        if (key > current->key){

            if (current->right != NULL) {current = current->right;}

            else {
                current->right = createNode(key);
                break;
            }

        }

        else if (key < current->key){

            if (current->left != NULL){current = current->left;}

            else{
                current->left = createNode(key);
                break;
                }
        }
        else{
            printf("\nNó com esse valor ja existe!. Nessa versão não são aceitas duplicatas!");
            break;
        }
    }
}

//Questão 8
Node * SearchIter(Node * root, int key){

    while (root != NULL){
        if (key > root->key){
            root = root->right;
        }
        else if (key < root->key){
            root = root->left;
        }
        else{
            printf("Nó de valor %d encontrado!\n", root->key);
            break;
        }
    }
    if (root == NULL) {
        printf("Nó de valor %d não encontrado\n", key);
    }

    return root;
    

    

}