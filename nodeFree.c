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
  free(root->plate);		//free the roots plate first
  free(root->last);		// then frees the root's last
  free(root->first);		//then frees the root's first name
  free(root);			//and last free the root itself
  
  
  
}
