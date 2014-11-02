#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer08.h"
List * List_half(List*,int);

List * List_createNode(const char * str)
{
  List *list = malloc(sizeof(List));
  list->str = strdup(str);//strdup malloc and copy the string
  list->next = NULL;//make sure list->next is null
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
  while (list != NULL)//terminate when reach NULL
    {
      list = list->next;//move to next node
      count++;//count the move
    }
  return count;
}


List * List_merge(List * lhs, List * rhs,
		  int (*compar)(const char *, const char*))
{  
  List * head = NULL;//head of merged list
  List * tmp = NULL;//mergerd list
  List * tail = NULL;//tail of merged list
  int ct = 0;
  //printf("---Getting Started----\n");    
  while ((rhs != NULL) || (lhs != NULL))
    //when lhs and rhs are both null
    // merge is done
    {
      if (rhs == NULL)//pass lhs while rhs is null
	{
	  tail = lhs;
	  lhs = lhs->next;
	  //printf("rhs is NULL\n");
	}
      else if (lhs == NULL)//pass rhs while lhs is null
	{
	  tail = rhs;
	  rhs = rhs->next;
	  //printf("lhs is NULL\n");
	}
      else if (compar(lhs->str,rhs->str) < 0) //left < right
	{
	  tail = lhs;
	  //printf("lhs: %s is smaller than rhs: %s now\n",lhs->str,rhs->str);
	  lhs = lhs->next;
	}
      else //when right >= left 
	{
	  tail = rhs;
	  //printf("lhs: %s >= rhs: %s now\n",lhs->str,rhs->str);
	  rhs = rhs->next;
       }
      if (ct == 0)//the first node is head
	{
	  head = tail;
	  tmp = head;
	  //printf("head is '/%s'(%s)/\n",head->str,tmp->str);
	}
      if (tail != NULL)
	{
	  if (ct != 0)
	    {
	      tmp->next = tail;//put tail at the end of the list
	      //printf("list is '/%s'/\n",tmp->str);
	      tmp = tmp->next;
	    }
	  tail = tail->next;
	}
      ct++;
      //printf("-------%dth round-------\n",ct);
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
  List *right = List_half(list,len/2);//split list into 2 part, list and right
  list =  List_sort(list,compar);
  right = List_sort(right,compar);//sort each part recursively  
  List * result = List_merge(list,right,compar);//merge small parts
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
      len--;//move to the middle
    }
  List *right = left->next;//the right part starts at the end of left part
  left->next = NULL;//Mark the end of left part
  return right;
}
