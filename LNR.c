/*  Functionname : LNR
*   
*   Purpose : to print out the bianary search tree in a left, node, rightformat
*
*   Inputs
*   Node root - the pointer to the root of the BST
*
*   Return:
*   exit - exits the function if the root is equal to NULL
*
*   Side Effects : this is a recursive function and keeps on going through the function until the nodes are printed out in the proper format
*/
#include "main.h"

void LNR(Node root) {
  if (root==NULL) return;
  LNR(root->left);
  printf("Plate:<%s> Name: %s,%s\n", root->plate, root->last, root->first);
  LNR(root->right);
  
  
  
}
