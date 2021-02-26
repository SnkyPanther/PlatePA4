/*  Functionname : treeFree
*
*   Purpose : this function makes sure the tree and everything that is in to be freed when the program is about to end
*
*   Inputs
*   Node root - the pointer to the root of the BST
*
*   Return:
*   exits if the root==NULL
*
*   Side Effects : it does it recursively and goes node by node freeing each node and its conntents
*/
#include "main.h"

void treeFree(Node root)  {
  if(root==NULL) {			//if the root is NULL then returns to the main program
    return;
  }
  treeFree(root->left);			//recursive call of the left tree
  treeFree(root->right);		//recursive fucntion call of the right tree
  nodeFree(root);			//calls the function to free the plate, first, last, and node

}
