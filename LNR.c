#include "main.h"

void LNR(Node root) {
  if (root==NULL) return;
  LNR(root->left);
  printf("%d\n", root->data);
  LNR(root->right);
  
  
  
}
