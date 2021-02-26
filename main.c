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


int main( int argc, char *argv[] ) {
  struct node *root, *less, *more;
  int number, result;
  char file[50], response[40], command[40];
  if(argc == 2){
    root=NULL;
    sscanf(argv[1], "%s", file);
    char first[50], last[50], plate[50], plateD[50], buffer[120];
    FILE *fp;
    fp=fopen(file, "r");
    if(fp == NULL) {
      printf("Cannot open %s\n", file);
      return 1;
    }
    while(NULL != fgets(buffer, 120, fp)) {
      sscanf(buffer, "%s %s %s", plate, first, last);
      root=add(root, plate, first, last);
    }
    while(1){
      printf("Enter command or plate: ");
      if(fgets(command, 40, stdin) == NULL) {
        printf("Freeing memory...\n");
        treeFree(root);
        return 0;
      }  
      sscanf(command, "%s %s", response, plateD);
      if(strcmp(response, "*DUMP") == 0) {
        printf("TREE HEIGHT: %d\n", height(root));
        if(balanced(root) == 1) {
          printf("BALANCED: YES\n");
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
      else if(strcmp(response, "*DELETE") == 0) {
        if(search(root, plateD, first, last) != 0) {
          root=delete(root, plateD);
          printf("SUCCESS\n");
        } 
        else {
          printf("PLATE NOT FOUND\n");
        }
      }
      
      else {
        strcpy(plate, response);
        if (search(root, plate, first, last) != 0) {
          printf("First name: %s\nLast name: %s\n", first, last);
        }
        else {
          printf("Plate not found\n");
        }
      }
    }
  }
  else {
    return 1;
  }
}
