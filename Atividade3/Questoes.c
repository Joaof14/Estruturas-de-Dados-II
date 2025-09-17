#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "ArvoreBinaria.h"


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
    printf("Mediana da árvore: %.2f\n", getMedian(root));


    ////Questão 7: Inserção por passagem de referencia
    printf("\n\nQuestão 7: Inserção por passagem de referencia\n");
    insertNodeRef(&root, 50);
    insertNodeRef(&root, 30);
    insertNodeRef(&root, 70); 
    inOrder(root);
    

    //Questão 4 -----


    //Questão 3 remoção de mínimo:
    printf("\n\n\nQuestão 3 remoção de mínimo\n");
    printf("Busca em ordem após remover mínimo:");
    Node * min = removeMin(root);
    inOrder(root);


    //Questão 5: BST
    printf("\n\n\n//Questão 5: BST\n");
    printf("Árvore é BST?: %d", isBST(root));

    /*printf("\nBusca em ordem após remover mínimo:");
    min = removeMin(root);
    inOrder(root);

    printf("\nÁrvore é BST após remover mínimo?: %d", isBST(root));*/

    //Questão 6: inserção iterativa
    printf("\n\n\nQuestão 6: inserção iterativa\n");
    root = insertNodeIter(root, 38);
    printf("Árvore após inserir nó 50:\n");
    preOrder(root);


    //Questão 8: Busca iterativa;
    printf("\n\n\nQuestão 8: Busca iterativa\n");
    ref = SearchIter(root, 18);
    ref = SearchIter(root, 122);

    free(ref);
    free(min);
    

}
