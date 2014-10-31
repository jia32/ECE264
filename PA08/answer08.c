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
  if(list != NULL)
    {
      if(list->str !=NULL)
	{
	  free(list->str);
	}      
      free(list);
    }
}
/*
int List_length(List * list)
{
  if (list = NULL)
    {
      return 0;
    }


}
*/
/*
List * List_merge(List * lhs, List * rhs,
		  int (*compar)(const char *, const char*))
{
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
}
*/
