/* Function name: delete
*  Purpose: it looks through out the bianary search tree and tries to find the plate that was entered to be deleted
*
*  Inputs:
*  Node root - pointer to the root of the BST
*  char *plate - character arraythat contains the license plate number
*
*  Return:
*  root or newRoot- return the root if it is still going through the function again and returns newRoot the new root of the tree
*
*  Side Effects: it goes through recusively and is trying to find the node, later, when the root is set up in the tree, the old root has to 
*               be freed.
*/
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
