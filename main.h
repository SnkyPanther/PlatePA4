/*  Function name : main.h
*
*   Purpose : has the name of the functions the struct node and the include(s)
*
*   Inputs
*
*   Return:
*
*   Side Effects : the good thing to have this is that I do not have to right the functions in all the programs
*/
#include <string.h>
#include <stdio.h>		//the include(s)
#include <stdlib.h>
struct node {
  char *plate;			//The struct node structure
  char *first;
  char *last;
  struct node *left;
  struct node *right;
};

typedef struct node* Node;		//Node definition

int height(Node root);
int balanced(Node root);
Node add(Node root,
	char *plate,			//function names
	char *first,
	char *last);
int search(Node root,
	char *plate,
	char *first,
	char *last);
Node delete(Node root,
	char*plate);
void LNR(Node root);
void NLR(Node root);
void LRN(Node root);
void treeFree(Node root);
void nodeFree(Node root);
