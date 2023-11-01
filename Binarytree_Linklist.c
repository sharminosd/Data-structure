#include<stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* left;
struct Node* right;
};
typedef struct Node node;

node *newNode(int data) {
node *n = (node*) malloc(sizeof(node));
n->data = data;
n->left = NULL;
n->right = NULL;
return n;
}

void print_In_Order(node *n) {
if (n == NULL) return;
print_In_Order(n->left);
printf("%d ", n->data);
print_In_Order(n->right);
}

int main()
{
node *root = newNode(10);
root->left = newNode(20);
root->right = newNode(30);
root->left->left = newNode(40);
root->left->right = newNode(50);
printf("Traversal of a binary tree: \n");
print_In_Order(root);
return 0;
}

