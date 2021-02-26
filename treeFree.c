#include "main.h"

void treeFree(Node root)  {
  if(root==NULL) {
    return;
  }
  treeFree(root->left);
  treeFree(root->right);
  nodeFree(root);

}
