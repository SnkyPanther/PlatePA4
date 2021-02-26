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
  int hleft, hright;
  if(root==NULL) {
    return -1;
  }
  hleft=height(root->left);
  hright=height(root->right);
  if(hleft > hright) {
    return(hleft+1);
  }
  return(hright+1);

}
