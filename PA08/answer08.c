#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer08.h"

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
*/


List * List_sort(List * list, int (*compar)(const char *, const char*))
{
  int len = List_length(list);
  if ((len == 0)||(len == 1))
    {
      return list;
    }
  List *right = List_half(list,len/2);
  List *tmp;
  list = tmp->next;
  tmp->next = right;
  while ((list! = NULL) && (right != NULL))
    {
      if (compar(list->str,right,str) < 0)
	{
	  List_sort(
		    }
}
      

int compar(const char*a,const char*b)
{
  return (strcmp(a,b));
}

List *List_half(List *list, int len)
{
  List *left = list;
  while (len > 1)
    {
      left = left->next;
      len--;
    }
  List *right = left->next;
  left->next = NULL;
  return right;
}
