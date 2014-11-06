#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer08.h"

#define TRUE 1
#define FALSE 0
int tests_List_createNode(int);
int tests_List_destroyNode(int);
int tests_List_length(int);
//int compar(const char *,const char*);
List * make_list(int);
int strcmp_forward(const char * , const char * );
int strcmp_reverse(const char *, const char *); 
int strcmp_length(const char * , const char *);
int strcmp_int(const char * , const char * );
void List_print(List * );
void print_compar(int (*compar)(const char *, const char *));
List * List_clone(List *);
List * make_list(int);
int test_sort(List *, int (*compar)(const char *, const char *));
int tests_List_sort(int);

int main(int argc, char * argv[])
{
  int i = (int)(argv[1][0] - '0');
  //tests_List_createNode(i);
  //tests_List_destroyNode(i);
  //int len = tests_List_length(i);
  List*list = make_list(i);
  test_sort(list,compar);
  //printf("length of linked list is %d\n",len);
  return EXIT_SUCCESS;
}


int strcmp_forward(const char * str_a, const char * str_b)
{
  return strcmp(str_a, str_b);
}
int strcmp_reverse(const char * str_a, const char * str_b)
{
  return -strcmp(str_a, str_b);
}
int strcmp_length(const char * str_a, const char * str_b)
{
  return strlen(str_a) - strlen(str_b);
}
int strcmp_int(const char * str_a, const char * str_b)
{
  return atoi(str_a) - atoi(str_b);
}
void List_print(List * list)
{
  List * tail = list;
  while(tail != NULL) {
    printf("\"%s\" ==> ", tail->str);
    tail = tail->next;
  }
  printf("NULL");
}

void print_compar(int (*compar)(const char *, const char *))
{
  if(compar == strcmp_forward) printf("return strcmp(a, b)");
  else if(compar == strcmp_reverse) printf("return -strcmp(a, b)");
  else if(compar == strcmp_length) printf("return strlen(a) - strlen(b)");
  else if(compar == strcmp_int) printf("return atoi(a) - atoi(b)");
  else printf("[UNKNOWN]");
}
List * List_create(const char * * strArr, int len)
{
  if(len == 0)
    return NULL;
  List * ret = List_createNode(strArr[0]);
  ret->next = List_create(++strArr, len - 1);
  return ret;
}
List * List_clone(List * list)
{
  if(list == NULL)
    return NULL;
  List * ret = List_createNode(list->str);
  ret->next = List_clone(list->next);
  return ret;
}
List * make_list(int list_number)
{
  const char * l0[] = { "b", "d", "f" };
  const char * l1[] = { "a", "c", "e", "g", "h", "i", "j" };
  const char * l2[] = { "2", "3", "5", "7" };
  const char * l3[] = { "11", "13", "17", "19", "23" };
  const char * l4[] = { "2010" };
  const char * l5[] = { "Hello", "Doctor", "Name", "Continue", "Yesterday",
			"Tomorrow" };
  const char * l6[] = { "sea", "a", "be" };
  const char * l7[] = { "deee" };
  switch(list_number) {
  case 0: return List_create(l0, sizeof(l0) / sizeof(const char *));
  case 1: return List_create(l1, sizeof(l1) / sizeof(const char *));
  case 2: return List_create(l2, sizeof(l2) / sizeof(const char *));
  case 3: return List_create(l3, sizeof(l3) / sizeof(const char *));
  case 4: return List_create(l4, sizeof(l4) / sizeof(const char *));
  case 5: return List_create(l5, sizeof(l5) / sizeof(const char *));
  case 6: return List_create(l6, sizeof(l6) / sizeof(const char *));
  case 7: return List_create(l7, sizeof(l7) / sizeof(const char *));
  }
  return NULL;
} 

int test_sort(List * list, int (*compar)(const char *, const char *))
{
  int success = TRUE; // until proven otherwise
  printf("Testing List_sort(list, compar), where:\n\n");
  printf("+ compar is: ");
  print_compar(compar);
  printf("\n");
  printf("+ list is: ");
  List_print(list);
  printf("\n");
  // Check that the student doesn't reallocate nodes... store list pointers
  int len = List_length(list);
  List * * nodeArr = malloc(len * sizeof(List *));
  int ind = 0;
  List * node = NULL;
  node = list;
  while(node != NULL) {
    nodeArr[ind++] = node;
    node = node->next;
  }
  // Clone lhs, rhs, and get the solution
  List * solution = List_sort(List_clone(list), compar);
  // Run the students code
  List * sorted = List_sort(list, compar);
  // Display what we got
  printf("\nsorted is : ");
  List_print(sorted);
  printf("\nsolution is: ");
  List_print(solution);
  printf("\n");
  // Are we the correct length?
  int sorted_len = List_length(sorted);
  if(sorted_len != len) {
    printf("Error: sorted solution has length %d, but it should be %d\n",
	   sorted_len, len);
    success = FALSE;
  }
  // Check the solution is in order, and that every Node pointer is in nodeArr
  List * sol_node = solution;
  node = sorted;
  while(node != NULL && sol_node != NULL) {
    int found = FALSE;
    for(ind = 0; ind < len && !found; ++ind)
      found = (nodeArr[ind] == node);
    if(!found) {
      printf("Error: sorted list contained a node with pointer %p; \n"
"however, this pointer was not in the input list. You must\n"
"not create or destroy nodes when merge-sorting linked\n"
	     "lists.\n", node);
      success = FALSE;
    }
    if(strcmp(node->str, sol_node->str) != 0) {
      printf("Error: sorted list not in order (!)\n");
      success = FALSE;
    }
    sol_node = sol_node->next;
    node = node->next;
  }
  // Cleanup memory
  free(nodeArr);
  List_destroy(solution);
  List_destroy(sorted);
  return success;
}

int tests_List_sort(int test_number)
{
  int n_tests = 16;
  // If test_number is out of range, then...
  if(test_number < 0 || test_number >= n_tests)
    return n_tests; // return how many distinct test-cases we have.
  switch(test_number) {
  case 0: return test_sort(NULL, strcmp_forward);
  case 1: return test_sort(make_list(0), strcmp_forward);
  case 2: return test_sort(make_list(0), strcmp_reverse);
  case 3: return test_sort(make_list(1), strcmp_forward);
  case 4: return test_sort(make_list(1), strcmp_reverse);
  case 5: return test_sort(make_list(2), strcmp_forward);
  case 6: return test_sort(make_list(2), strcmp_reverse);
  case 7: return test_sort(make_list(2), strcmp_int);
  case 8: return test_sort(make_list(3), strcmp_forward);
  case 9: return test_sort(make_list(3), strcmp_reverse);
  case 10: return test_sort(make_list(3), strcmp_int);
  case 11: return test_sort(make_list(4), strcmp_forward);
  case 12: return test_sort(make_list(4), strcmp_reverse);
  case 13: return test_sort(make_list(5), strcmp_forward);
  case 14: return test_sort(make_list(5), strcmp_reverse);
  case 15: return test_sort(make_list(6), strcmp_length);
  }
  return FALSE;
}
