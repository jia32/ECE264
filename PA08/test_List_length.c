
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer08.h"

#define BUFLEN 256
#define TRUE 1
#define FALSE 0
List* List_half(List*,int);
int tests_List_length(int test_number)
{
    int n_tests = 7;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests)
	return n_tests; // return how many distinct test-cases we have.

    // Create a linked-list of the prescribed size
    
    char buffer[BUFLEN];
    List * list = NULL;
    int len = test_number;
    int ind;
    for(ind = 0; ind < len; ++ind) {
	snprintf(buffer, BUFLEN, "[%d]", test_number - ind);
	List * head = List_createNode(buffer);
	head->next = list; // append to start of list
	list = head;
    }
   
    // Explain what's about to happen
    printf("Testing: List_length(list) = ");
    fflush(stdout);
    int stu_len = List_length(list);
    printf("%d",stu_len);
    printf(", where list is: ");
    List * tail = list;
    while(tail != NULL) {
	printf("\"%s\" ==> ", tail->str);    
	tail = tail->next;
    }
    printf("NULL\n");

    int ret = TRUE;
    int sol_len = List_length(list);
    if(sol_len != stu_len) {
	printf("Error: expected length is %d\n", sol_len);
	ret = FALSE;
    }

    List * q = List_half(list,len/2);
    printf("Testing: List_half(list):\n");
    printf("Left hand side is:\n");
    while (list != NULL)
      {
	printf("\"%s\" ==> ",list->str);
	list = list->next;
      }
    printf("NULL\nRight hand side is:\n");
    while(q != NULL) {
      printf("\"%s\" ==> ", q->str);
      q = q->next;
    }    
    printf("NULL");
    // Cleanup
    List_destroy(list);
    return ret;
}

