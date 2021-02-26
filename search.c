/*  Functionname : search
*
*   Purpose : searched the current bianary search tree and see if the plate is found in the tree
*
*   Inputs
*   Node root - the pointer to the root of the BST
*   char *plate - this is the plate number
*   char *first - this is the first name that is associated with the plate number
*   char *last - this is the last name that is associated with plate number
*
*   Return:
*   0 - returns if the root == NULL
*   1 - this returns if the search was succesful
*   returns the search again to keep going until runs out or found
*
*   Side Effects : this function is recursive and has to also copy strings using strcpy.
*/
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
