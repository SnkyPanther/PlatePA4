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
  if (root==NULL) return;   							//returns to the main function if the root is equal to NULL
  LNR(root->left);								//recursive function call
  printf("Plate:<%s> Name: %s,%s\n", root->plate, root->last, root->first);	//prints the plate, first, and last
  LNR(root->right);								//recuresive function call of the right branch
  
  
  
}
