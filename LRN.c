#include "main.h"

void LRN(Node root)  {
  if (root==NULL)  return;
  LRN(root->left);
  LRN(root->right);
  printf("Plate:<%s> Name %s,%s\n", root->plate, root->last, root->first);


}
