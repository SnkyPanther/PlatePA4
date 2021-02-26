/*  Functionname : nodeFree
*
*   Purpose : this function is called from the treeFree functions and it frees the three different part of each node and the node itself
*
*   Inputs
*   Node root - the pointer to the root of the BST
*
*   Return:
*   void - it does not return anything
*
*   Side Effects : has to be called multiple times until all the things are freed
*/
#include "main.h"


void nodeFree(Node root)  {
  free(root->plate);
  free(root->last);
  free(root->first);
  free(root);
  
  
  
}
