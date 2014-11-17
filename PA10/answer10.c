#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer10.h"

//-------------------BusLoc----------------------
//BusLoc: Linked list indexed by id
//BusLoc is similar to the expected Locations,
//except it does not contain reviews in it
typedef struct BusLoc_t
{
  int id;
  char *address, *city, * state, * zip;//owned
  struct BusLoc_t * next;
}BusLoc;

BusLoc * BusLoc_create(int,const char *,const char*, 
		       const char*,const char*);
BusLoc * BusLoc_insert(BusLoc*, int, const char *, const char*,
		       const char *, const char *);
void BusLoc_destroy(BusLoc*);
void BusLoc_print(BusLoc*);
void test_BusLoc();

BusLoc * BusLoc_create(int id, const char * address,const char * city,
		       const char * state, const char * zip)
{
  BusLoc * head = malloc(sizeof(BusLoc));
  head->id = id;
  head->address = strdup(address);
  head->city = strdup(city);
  head->state = strdup(state);
  head->zip = strdup(zip);
  head->next = NULL;
  return head;
}

BusLoc * BusLoc_insert(BusLoc * head, int id, const char * address,
		       const  char * city,const  char * state,const  char * zip)
{
  BusLoc * newhead = BusLoc_create(id,address,city,state,zip);
  newhead->next = head;
  return newhead;
} 

void BusLoc_destroy(BusLoc * head)
{
  BusLoc * itr = head;
  while (itr!= NULL)
    {
      BusLoc * next = itr->next;
      free(head->zip);
      free(head->state);
      free(head->city);
      free(head->address);
      free(head);
      itr = next;
    }
}

void BusLoc_print(BusLoc * head)
{
  BusLoc * itr = head;
  while (itr != NULL)
    {
      printf("===>%p %d %s %s %s %s %p",itr,itr->id,itr->address,
	     itr->city,itr->state,itr->zip,itr->next);
      itr = itr->next;
    }
}

void test_BusLoc()
{
  BusLoc * head = BusLoc_create(1,"address","city","state",
				"47906");
  head = BusLoc_insert(head,2,"address2","city2","state2","44444");
  BusLoc_print(head);
  printf("\n");
}
//----------------BusTree------------------------
//BusTree: BST indexed by name;

typedef struct BusTree_t
{
  char * name;
  BusLoc * loc;
  struct BusTree_t * left;
  struct BusTree_t * right;
}BusTree;

BusTree * BusTree_create(const char*);
void BusTree_destroy(BusTree *);
BusTree * BusTree_insert(BusTree *, const char*,
			 int, const char*, const char*,
			 const char*, const char*);
void BusTree_print(BusTree *);
BusTree * BusTree_find(BusTree * ,const char *);
void test_BusTree();

BusTree * BusTree_create(const char* name)
{
  BusTree * root = malloc(sizeof(BusTree));
  root->name = strdup(name);
  root->left = NULL;
  root->right = NULL;
  root->loc = NULL;
  return root;
}

void BusTree_destroy(BusTree * root)
{
  if (root == NULL)
    return;
  BusTree_destroy(root->left);
  BusTree_destroy(root->right);
  free(root->name);
  BusLoc_destroy(root->loc);
  free(root);
}

BusTree * BusTree_insert(BusTree * root, const char*name,
			 int id,const char *address,const char*city,
			 const char* state, const char* zip)
{
  if (root == NULL)
    {
      root = BusTree_create(name);
      root->loc = BusLoc_create(id,address,city,state,zip);
    }

  int cmp = strcmp(name, root->name);
  if (cmp < 0)
    root->left = BusTree_insert(root->left,name,id,address,city,state,zip);
  else if (cmp > 0)
    root->right = BusTree_insert(root->right,name,id,address,city,state,zip);
  else //different locations for same name
    root->loc = BusLoc_insert(root->loc,id,address,city,state,zip);
  
  return root;
}

void BusTree_print(BusTree * root)
{
  if (root == NULL)
    return;
  printf("%p %s (%p %p)\n",root,root->name,root->left,root->right);
  BusLoc_print(root->loc);
  printf("\n");
  BusTree_print(root->left);
  BusTree_print(root->right);
}

BusTree * BusTree_find(BusTree * root, const char * name)
{
  if (root == NULL)
    return NULL;
  int compar = strcmp(name,root->name);
  if (compar == 0)
    return root;
  if (compar < 0)
    BusTree_find(root->left,name);
  BusTree_find(root->right,name);
  return NULL;
}

void test_BusTree()
{
  BusTree * root = BusTree_create("KFC");
  root = BusTree_insert(root, "KFC",1,"address1","city1","state1","11111");
  root = BusTree_insert(root, "ACD",2,"address1","city1","state1","22222");
  root = BusTree_insert(root, "ACD",2,"address2","city2","state2","22223");
  root = BusTree_insert(root, "KFC",1,"address2","city2","state2","11112");
  BusTree_print(root);
}

//------------------------explode------------------------
char** explode(const char*, const char*, int*);

char** explode(const char* str, const char *delims, int *arrLen)
{
  int n = 0;
  int ind;
  int len = strlen(str);
  for (ind = 0; ind < len; ind++)
    {
      if (strchr(delims,str[ind])!= NULL)
	n+=1;
    }
  char**strArr = malloc((n+1)*sizeof(char*));
  int arrInd = 0;
  int last = 0;

  for(ind = 0; ind<len;ind++)
    {
      //printf("%d\n",strchr(delims,str[ind])-str[ind]+11);
      if (strchr(delims,str[ind]) != NULL)
	{
	  strArr[arrInd] = malloc(sizeof(char)*(ind-last));
	  //printf("%d\n",ind-last);
	  memcpy(strArr[arrInd],str+last,ind-last);
	  //printf("%s\n",strArr[arrInd]);
	  last = ind+1;
	  arrInd++;
	}
    }
  strArr[n] = malloc(sizeof(char)*(len-last));
  memcpy(strArr[n],str+last,len-last-1);
  *arrLen = n+1;
  return strArr;
}
void test_explode();
void test_explode()
{
  int len;
  char** a = explode("id\tMcDonld\tWest Lafayett\tIN\t47906\n","\t",&len);
  printf("length = %d\n",len);
  int ind;
  for(ind = 0; ind<len;ind++)
    {
      printf("strArr[%d] is %s\n",ind,a[ind]);
    }
}

