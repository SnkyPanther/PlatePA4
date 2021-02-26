#include "main.h"


Node delete(Node root, char* plate)  {

  if(strcmp(plate, root->plate) < 0) {
    root->left=delete(root->left, plate);
    return root;
  }
  if(strcmp(plate, root->plate) > 0) {
    root->right=delete(root->right, plate);
    return root;
  }
  if(strcmp(plate, root->plate) == 0) {
    struct node *newRoot, *originRoot;
    originRoot=root;
    while(1) {
    if(root->left==NULL) {
      newRoot=root->right;
      free(root);
      return(newRoot);
    }
    if(root->left->right == NULL) {
      newRoot=root->left;
      newRoot->right=root->right;
      free(root);
      return(newRoot);
      }
    newRoot=root->left;
    root=newRoot;
    newRoot=root->right;
    while(newRoot->right != NULL) {
      root=newRoot;
      newRoot=root->right;
    }
    if(newRoot->right == NULL) {
      root->right=newRoot->left;
      newRoot->right=originRoot->right;
      newRoot->left=originRoot->left;
      free(originRoot);
      return(newRoot); 
    }
  }
}
}
