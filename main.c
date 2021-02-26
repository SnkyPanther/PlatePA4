/*  Functionname : main.c
*   
*   Purpose: this is the main function of the assignment, in this file, the program runs and check in the input into the command line, using fgets
*   and sscanf. It also asks the user for differen types of commads whichs are "*DUMP" in order to look at the stats, "*DELETE" to delete a plate
*   number, plate number- to see the name that it is associated with, and CTRL-D to exit the program and free all the memory
*
*   Inputs
*   argc - this checks how much arguments there are in the command line
*   char *argv[] - this stores the argument in a string
*
*   Return:
*   1 - if the file cannot be opened
*   0 - exits the program
*
*   Side Effects: Have to have all the functions and command options to work properly and have to release all the memory in the end
*/
#include "main.h"


int main( int argc, char *argv[] ) {			//command line arguements
  struct node *root, *less;				//defining struct node variables
  int number, result;
  char file[50], response[40], command[40];		//char strings
  if(argc == 2){					//program runs when there is 2 command line arguements
    root=NULL;						//sets root to NULL
    sscanf(argv[1], "%s", file);			//sscanfs the file
    char first[50], last[50], plate[50], plateD[50], buffer[120];	//more definitions of char strings
    FILE *fp;						//use the file name to fopen
    fp=fopen(file, "r");
    if(fp == NULL) {					//check if I can open
      printf("Cannot open %s\n", file);
      return 1;
    }
    while(NULL != fgets(buffer, 120, fp)) {		//read in all the contents of the file
      sscanf(buffer, "%s %s %s", plate, first, last);	//sscanf the contents and place under three strings
      root=add(root, plate, first, last);		//call the add function
    }
    fclose(fp);						//close the file
    while(1){						//infinite loop
      printf("Enter command or plate: ");		//asks for the command and use the fgets
      if(fgets(command, 40, stdin) == NULL) {		//if CTRL-D is pressed, then the fgets return is NULL 
        printf("Freeing memory...\n");			//and then I free the memory of the tree
        treeFree(root);					//and return 0
        return 0;
      }  
      sscanf(command, "%s %s", response, plateD);	//sscanf the command entered
      if(strcmp(response, "*DUMP") == 0) {		//if the command was "*DUMP" 
        printf("TREE HEIGHT: %d\n", height(root));	//then I print out the stats
        if(balanced(root) == 1) {			// which are the height, if it is balanced
          printf("BALANCED: YES\n");			//and the three different traversals of the bianary search tree
        }
        else {
        printf("BALANCED: NO\n");
        }
        printf("\nLNR TRAVERSAL\n");
        LNR(root);
        printf("\nNLR TRAVERSAL\n");
        NLR(root);
        printf("\nLRN TRAVERSAL\n");
        LRN(root);
        printf("\n");
      }
      else if(strcmp(response, "*DELETE") == 0) {	//if the response was "*DELETE"
        if(search(root, plateD, first, last) != 0) {    //if searches if the plate entered is found in the tree
          root=delete(root, plateD);			// if it is it calls the delete functions and deletes the node
          printf("SUCCESS\n");
        } 
        else {
          printf("PLATE NOT FOUND\n");
        }
      }
      
      else {
        strcpy(plate, response);			//this is the last option and it searches for the plate entered
		if (search(root, plate, first, last) != 0) {	// if the plate is recognized as a plae, then is prints out the first and last
          printf("First name: %s\nLast name: %s\n", first, last);	//names
        }
        else {
          printf("Plate not found\n");
        }
      }
    }
  }
  else {
    return 1;				//if something did not work, then returns 1
  }
}
