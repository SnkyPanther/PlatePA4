/* Function name: add
*  Purpose: adds a triple of license plate: plate, first, and last, into the binary tree. if goes recuresively to first find a spot
*  for the new_node and then allocates space for it.
*
*  Inputs:
*  Node *root - pointer to the root of the BST
*  char *plate - character arraythat contains the license plate number
*  char *first - contains the first name of the owner of the license plate
*  char *last - last name that is associated with the plate
*
*  Return:
*  Node - the (potentially new) root of the tree after the above data has been added
*
*  Side Effects: allocates the space for new node, and dynamically allocates space for the tree pieces of data. 
*               Later has to be freed
*/
#include "main.h"
Node add(Node root, char *pl, char *fst, char *lst) {
  if(root==NULL) {					//checks if the root is NULL
    struct node *new;			 		//if it is then it make a new node and then allocates space for it
    new=malloc(sizeof(struct node));			//and for the plate, first, and last
    new->plate=malloc(strlen(pl)+1);
    strcpy(new->plate, pl);				//copies using the strcpy function
    new->first=malloc(strlen(fst)+1);
    strcpy(new->first, fst);
    new->last=malloc(strlen(lst)+1);
    strcpy(new->last, lst);

    new->left=NULL;					//sets the children to NULL
    new->right=NULL;
    root=new;						//returns the new root
    return(root);    
  }
  if(strcmp(pl, root->plate) < 0)  {			//compares using strcmp and if less thatn root->plate goes to the root->left branch and
    root->left=add(root->left, pl, fst, lst);		//calls the add function again recursivly
    return(root);					//return root
  }
  else {
    root->right=add(root->right, pl, fst, lst); 	//else it then goes to the root->right child and calls the function again, returns root
    return(root);
  }
  return root;

}
