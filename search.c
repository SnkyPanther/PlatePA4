#include "main.h"

int search(Node root, char *plate, char *first, char *last)  {
  if(root==NULL) {
    return 0;
  }
  if(strcmp(root->plate, plate) == 0) {
    strcpy(first, root->first);
    strcpy(last, root->last);
    return 1;
  }
  if(strcmp(plate, root->plate) < 0) {
    return(search(root->left, plate, first, last)); 
  }
  else {
   return(search(root->right, plate, first, last)); 
  }







}
