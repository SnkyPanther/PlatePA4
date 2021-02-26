#include "main.h"


void nodeFree(Node root)  {
  free(root->plate);
  free(root->last);
  free(root->first);
  free(root);
  
  
  
}
