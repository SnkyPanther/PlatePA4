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
