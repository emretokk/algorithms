#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node* parent;
    struct ndoe* left;
    struct node* right;
}node;

node* createNode(int val){
    node* new = (node*) malloc(sizeof(node));
    new->key = val;
    new->parent = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insertNode(node* root, node* newNode){
    node* y = NULL;
    node* x = root;
    // in that part we are looking for newNode's place
    while(x != NULL){
        y = x;
        if (newNode->key <= x->key) x = x->left;
        else x = x->right;
    }
    // we found that where should be newNode its parent is y
    newNode->parent = y;
    
    if (y == NULL) root = newNode; // in this key the tree is completely empty and we inserted it as root
    else if (newNode->key <= y->key) y->left = newNode; // newNode value is smaller than y which is the parent of newNode
    else y->right = newNode; // newNode value is greater than y which is the parent of newNode
}

void preorderTreeWalk(node* root){
	if (root != NULL)
	{
		printf("%d ", root->key);
		preorderTreeWalk(root->left);
		preorderTreeWalk(root->right);
	}
 }

int main(){
    node* root = createNode(10);
    insertNode(root, createNode(3));
    insertNode(root, createNode(4));
    insertNode(root, createNode(1));
    insertNode(root, createNode(11));
    insertNode(root, createNode(13));
    insertNode(root, createNode(12));


    preorderTreeWalk(root);
}

