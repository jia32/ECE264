
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer08.h"

#define TRUE 1
#define FALSE 0
int tests_List_createNode(int);
int tests_List_destroyNode(int);
int tests_List_length(int);
int main(int argc, char * argv[])
{
  int i = (int)(argv[1][0] - '0');
  //tests_List_createNode(i);
  //tests_List_destroyNode(i);
  int len = tests_List_length(i);
  //printf("length of linked list is %d\n",len);
  return EXIT_SUCCESS;
}
