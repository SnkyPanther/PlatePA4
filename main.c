#include "main.h"
void directions();
int scratch(Node root);
int main( int argc, char *argv[] ) {
  struct node *root, *less, *more;
  int number, result;
  root=malloc(sizeof(struct node));
  less=malloc(sizeof(struct node));
  more=malloc(sizeof(struct node));
  root->data=10;
  less->data=6;
  more->data=12;
  root->left=less;
  root->right=more;
//  scratch(root); 


  LNR(root);


}
int scratch(Node root) {
  struct node *less, *more;
  less=malloc(sizeof(struct node));
  more=malloc(sizeof(struct node));
//  root->data=10;
  less->data=6;
  more->data=12;
  less=root->left;
  more=root->right;
  return(0);
 }
