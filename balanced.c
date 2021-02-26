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
  if(root==NULL)  {				//if the root is NULL the functions return 1
    return 1;
  }
  if(height(root->left)-height(root->right) <= 1) { 	//checks if the differences of the heights right and left trees are less 
    if(balanced(root->left) == 1) {			// that equal to 1, and then checks recursively if the root->left and root->right
      if(balanced(root->right) == 1) {			//are both balanced then it returns 1, which means that it is balanced
        return 1;
      }
    }
    else {
      return 0;						//if not then it returns 0
    }
  }  
  return 0;  

}
