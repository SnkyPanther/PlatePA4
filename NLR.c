/*  Functionname : NLR
*
*   Purpose : to print out the bianary search tree in a node, left, rightformat
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


void NLR(Node root){
  if (root==NULL) return;   					//checks if the root is NULL and if it is returns to the main function
  printf("Plate:<%s> Name: %s,%s\n", root->plate, root->last, root->first);	//prints out the plate last first 
  NLR(root->left);			//recursive call of the left tree
  NLR(root->right);			//recursive function call of the right tree


}
