/*  Functionname : LRN
*
*   Purpose : to print out the bianary search tree in a left, right, node, format
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

void LRN(Node root)  {
  if (root==NULL)  return;		//checks if the root is NULL and if it is returns to the main fucntion
  LRN(root->left);			//recursive function call of the left branch
  LRN(root->right);			//recursive function call of the right branch
  printf("Plate:<%s> Name %s,%s\n", root->plate, root->last, root->first); 	//prints out the plate, last and first


}
