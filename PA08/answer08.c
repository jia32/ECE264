#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer08.h"

List * List_half(List*,int);
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


List * List_merge(List * lhs, List * rhs,
		  int (*compar)(const char *, const char*))
{  
  List * head;
  List * tail;
  int ct = 0;
  while ((rhs != NULL) || (lhs != NULL))
    {
      if (rhs == NULL)
	{
	  tail = lhs;
	  lhs = lhs->next;
	}
      else if (lhs == NULL)
	{
	  tail = rhs;
	  rhs = rhs->next;
	}
      else if (compar(lhs->str,rhs->str) < 0) //left < right
	{
	  tail = lhs;
	  lhs = lhs->next;
	}
      else //when right >= left 
	{
	  tail = rhs;
	  rhs = rhs->next;
       }
      if (ct == 0)
	{
	  head = tail;
	}
      if (tail != NULL)
	{
	  tail = tail->next;
	}
      ct++;
    }
  return head;
}


List * List_sort(List * list, int (*compar)(const char *, const char*))
{
  int len = List_length(list);
  if ((len == 0)||(len == 1))
    {
      return list;
    }
  List *right = List_half(list,len/2);
  list =  List_sort(list,compar);
  right = List_sort(right,compar);  
  List * result = List_merge(list,right,compar);
  return result;
}    

int compar(const char * a,const char * b)
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
