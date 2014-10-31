
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer08.h"

#define TRUE 1
#define FALSE 0
int tests_List_createNode(int);
int tests_List_destroyNode(int);

int main(int argc, char * argv[])
{
  int i = (int)(argv[1][0] - '0');
  int j =  tests_List_createNode(i);
  int k = tests_List_destroyNode(i);
  printf("create %d\ndestroy %d",j,k);
  return EXIT_SUCCESS;
}
