/* Function name: delete
*  Purpose: it looks through out the bianary search tree and tries to find the plate that was entered to be deleted
*
*  Inputs:
*  Node root - pointer to the root of the BST
*  char *plate - character arraythat contains the license plate number
*
*  Return:
*  root or newRoot- return the root if it is still going through the function again and returns newRoot the new root of the tree
*
*  Side Effects: it goes through recusively and is trying to find the node, later, when the root is set up in the tree, the old root has to 
*               be freed.
*/
#include "main.h"


Node delete(Node root, char* plate)  {

  if(strcmp(plate, root->plate) < 0) {			//compares the two strings and sees if the result is less than 0
    root->left=delete(root->left, plate);		//if it then the root goes to root-left and calls delete again and returns root
    return root;
  }
  if(strcmp(plate, root->plate) > 0) {			//compare the two strings and sees if the result is greater than 0
    root->right=delete(root->right, plate);		//if it is then the root goes to the root->right and calls delete again and returns root
    return root;
  }
  if(strcmp(plate, root->plate) == 0) {			//if the result of the compared string is equal to 0 then the following happens
    struct node *newRoot, *originRoot;			//define two different structs, that will help
    originRoot=root;					//set one of the struct to equal to root
    while(1) {						//infinite while loop until it returns the main program
    if(root->left==NULL) {				//this is one situation if the left branch is NULL
      newRoot=root->right;				//then the new root becomes the root->right
      nodeFree(root);					//and returns the new root and frees the old root
      return(newRoot);
    }
    if(root->left->right == NULL) {			// this is another situation and the folling happens if it meets the requirements
      newRoot=root->left;				//this situations is if the root->left is the biggest value 
      newRoot->right=root->right;			//make that the new root make the old root->right equal to the newRoot->right
      nodeFree(root);					//frees the root
      return(newRoot);					//returns the new root
      }
    newRoot=root->left;					//this situation basically tries to find the biggest value of a license plate in the left
    root=newRoot;					//sub tree
    newRoot=root->right;				//so it bascially goes node by node first goes to the left sub tree, then tries to find
    while(newRoot->right != NULL) {			//the node that is on the very right
      root=newRoot;					//goes while the right is not NULL
      newRoot=root->right;				//and moves node by node with reassigning
    }
    if(newRoot->right == NULL) {			//when it exits the while loop then it has found the biggest node
      root->right=newRoot->left;			//assigns the left and right points so that they do not include the biggest node anymore
      newRoot->right=originRoot->right;			//the biggest node becomes the root of the current tree and has the right and left
      newRoot->left=originRoot->left;			//branches assigned to it
      nodeFree(originRoot);				//frees the old root and returns the new root
      return(newRoot); 
    }
  }
}
  
}
