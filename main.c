/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left; 
  struct node *right;
} Node;

// Check if two trees are mirror images 
bool isMirror(Node* a, Node* b) {
  if (a == NULL && b == NULL) return true;
  if (a == NULL || b == NULL) return false;
  
  return (a->data == b->data) && 
         isMirror(a->left, b->right) &&
         isMirror(a->right, b->left); 
}

// Create a mirror image of a tree
Node* createMirror(Node* root) {
  if (root == NULL) return NULL;
  
  Node* mirror = malloc(sizeof(Node));
  mirror->data = root->data;
  mirror->right = createMirror(root->left);
  mirror->left = createMirror(root->right);

  return mirror;
}

// Print tree in order  
void printInOrder(Node* root) {
  if (root == NULL) return;
  
  printInOrder(root->left);
  printf("%d ", root->data);
  printInOrder(root->right);
}

int main() {
  // Create binary tree 1
  Node* tree1 = malloc(sizeof(Node));
  tree1->data = 5; 
  tree1->left = malloc(sizeof(Node));
  tree1->left->data = 2;
  tree1->right = malloc(sizeof(Node));
  tree1->right->data = 1;
  
  // Create binary tree 2
  Node* tree2 = malloc(sizeof(Node));
  tree2->data = 6; 
  tree2->left = malloc(sizeof(Node));
  tree2->left->data = 2;
  tree2->right = malloc(sizeof(Node));
  tree2->right->data = 2;
  
  // Check if tree 1 is a mirror of itself
  if (isMirror(tree1, tree1)) {
    printf("Tree 1 is a mirror of itself\n"); 
  }
  
  // Create mirror of tree 1
  Node* mirrorTree = createMirror(tree1);

  // Check if tree 1 and tree 2 are mirrors
  if (isMirror(tree1, tree2)) {
    printf("Tree 1 and Tree 2 are mirrors\n");
  } else {
    printf("Tree 1 and Tree 2 are not mirrors\n"); 
  }

  // Print mirror of tree 1
  printf("Mirror image of tree 1: ");
  printInOrder(mirrorTree);

  return 0;
}