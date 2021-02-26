/* Function name: balanced
*  Purpose: checks if the current BST is balanced or not and returns YES or NO
*
*  Inputs:
*  Node root - pointer to the root of the BST
*
*  Return:
*  1 if balanced and 0 if not balanced
*
*  Side Effects: goes recursively through out the tree
*               
*/
#include "main.h"


int balanced(Node root) {
  if(root==NULL)  {
    return 1;
  }
  if(height(root->left)-height(root->right) <= 1) {
    if(balanced(root->left) == 1) {
      if(balanced(root->right) == 1) {
        return 1;
      }
    }
    else {
      return 0;
    }
  }  
  return 0;  

}
