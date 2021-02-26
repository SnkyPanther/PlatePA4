#include "main.h"


void NLR(Node root){
  if (root==NULL) return;
  printf("Plate:<%s> Name: %s,%s\n", root->plate, root->last, root->first);
  NLR(root->left);
  NLR(root->right);


}
