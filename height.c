/* Function name: height
*  Purpose: tries to find out what is the height of the bianry search tree
*
*  Inputs:
*  Node *root - pointer to the root of the BST
*
*  Return:
*  -1 - if the root is NULL
*  height - return the height of which of the child trees is bigger and adds 1 to it
*
*  Side Effects: goes recursively, trying to find the longes branch that is possible and then adds 1 to it
*               
*/
#include "main.h"

int height(Node root) {
  int hleft, hright;			//assigning some variables
  if(root==NULL) {			//if the root is NULL then exits with a -1 value
    return -1;
  }
  hleft=height(root->left);		//finds the longest branch possible in the bianry search tree
  hright=height(root->right);		
  if(hleft > hright) {			//adds 1 and returns the greater height value
    return(hleft+1);
  }
  return(hright+1);

}
