#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer08.h"

/*
typedef struct ListNode_st
{
    char * str;
    struct ListNode_st * next;
} List;
*/
List * List_createNode(const char * str)
{
  
  List *list = malloc(sizeof(List));
  list->str = strdup(str);
  list->next = NULL;
  return list;
}

void List_destroy(List * list)
{
  List * tmp;
  while(list != NULL)
    {
      tmp = list;
      list = list->next;
      //printf("Now free %s\n",tmp->str);
      free(tmp->str);
      free(tmp);
    }
}


int List_length(List * list)
{
  int count = 0;
  while (list != NULL)
    {
      list = list->next;
      count++;
    }
  return count;
}

/*
List * List_merge(List * lhs, List * rhs,
		  int (*compar)(const char *, const char*))
{
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
}
*/
