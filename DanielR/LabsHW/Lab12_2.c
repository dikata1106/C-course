#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char newData) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        fprintf(stderr, "err");
        return NULL;
    }
    newNode->data=newData;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printBinTree(struct Node *tree) {
    if(!tree) {
        printf("NULL");
        return;
    }
    printf("{ NODE ");
    printf("%c", tree->data);
    printBinTree(tree->left);
    printBinTree(tree->right);
    printf("} ");
}

int main(void) {

}