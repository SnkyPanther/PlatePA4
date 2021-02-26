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
