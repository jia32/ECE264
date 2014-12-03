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
  int address, city, state, zip;//these are all offsets
  struct BusLoc_t * next;
}BusLoc;

BusLoc * BusLoc_create(int,int,int,int,int);
BusLoc * BusLoc_insert(BusLoc*, int,int, int,
		       int, int);
void BusLoc_destroy(BusLoc*);
void BusLoc_print(BusLoc*);
//void test_BusLoc();

BusLoc * BusLoc_create(int id,int address,int city,
		       int state, int zip)
{
  BusLoc * head = malloc(sizeof(BusLoc));
  head->id = id;
  head->address =address;
  head->city = city;
  head->state = state;
  head->zip = zip;
  head->next = NULL;
  return head;
}

BusLoc * BusLoc_insert(BusLoc * head, int id,int address,
		       int city,int state,int zip)
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
      free(head);
      itr = next;
    }
}

void BusLoc_print(BusLoc * head)
{
  BusLoc * itr = head;
  while (itr != NULL)
    {
      printf("===>%p %d %d %d %d %d %p",itr,itr->id,itr->address,
	     itr->city,itr->state,itr->zip,itr->next);
      itr = itr->next;
    }
}
/*void test_BusLoc()
{
  BusLoc * head = BusLoc_create(1,"address","city","state",
				"47906");
  head = BusLoc_insert(head,2,"address2","city2","state2","44444");
  BusLoc_print(head);
  printf("\n");
}*/

//----------------BusTree------------------------
//BusTree: BST indexed by name;
//->YelpDataBST

typedef struct BusTree_t
{
  char * name;
  BusLoc * loc;
  struct BusTree_t * left;
  struct BusTree_t * right;
}BusTree;

BusTree * BusTree_create(const char*);
void BusTree_destroy(BusTree *);
BusTree *BusTree_insert(BusTree *, const char*,
			 int, int, int, int, int);
void BusTree_print(BusTree *);
BusTree * BusTree_find(BusTree * ,const char *);
//void test_BusTree();

BusTree *BusTree_create(const char* name)
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
			 int id,int address,int city, int state, int zip)

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

/*void test_BusTree()
{
  BusTree * root = BusTree_create("KFC");
  root = BusTree_insert(root, "KFC",1,"address1","city1","state1","11111");
  root = BusTree_insert(root, "ACD",2,"address1","city1","state1","22222");
  root = BusTree_insert(root, "ACD",2,"address2","city2","state2","22223");
  root = BusTree_insert(root, "KFC",1,"address2","city2","state2","11112");
  BusTree_print(root);
}*/

//------------------------explode------------------------
char** explode(const char*, const char*, int*);
void test_explode();

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

void test_explode()
{
  int len;
  char** a = explode("Ruby's Diner\t3111 W Chandler Blvd Ste 2146\tChandler\tAZ\t85226\t3111 W Chandler Blvd Ste 2146, Chandler, AZ 85226\n","\t",&len);
  printf("length is %d\n",len);
  int ind;
  for(ind = 0; ind<len;ind++)
    {
      printf("strArr[%d] is %s\n",ind,a[ind]);
      free(a[ind]);
    }
  free(a);
}

//------------------------Get offsets---------------------------
int * get_offsets(char**,int);
int * get_offsets(char** strArr, int offset)
{
  int * offsets = malloc(sizeof(int)*4);
  offsets[0] = strlen(strArr[2]) + offset;
  offsets[1] = strlen(strArr[3]) + strlen(strArr[2]) + offset;
  offsets[2] = strlen(strArr[4]) + strlen(strArr[3]) + strlen(strArr[2]) + offset;
  offsets[3] = strlen(strArr[5]) + strlen(strArr[4]) + strlen(strArr[3]) + strlen(strArr[2]) + offset;
  return offsets;
}

//------------------------create YelpDataBST---------------------

typedef struct YelpDataBST_t
{
  char * name;
  BusLoc *loc;
  struct YelpDataBST_t *left;
  struct YelpDATABST_t *right;
}YelpDataBST;

typedef struct Review_t
{
  int bus_id;
  long offset;
}Review;

struct YelpDataBST* create_business_bst(const char* businesses_path,
                                        const char* reviews_path)
{
  const char filename = business_path;
  int len;
  int lineno = 0;
  int last_id = -1;
  int num_id = 0;
  YelpDataBST * root = NULL;
  FILE *fp;
  
  fp = fopen(filename,"r");
  if(fp == NULL)
    {
      printf("File error\n");
      return NULL;
    }

  //basic idea here
  //read one line at a time till it reaches to the end
  //use explode to read address
  //when the id matches, insert the address offsets

  //how to get offsets: get current location (before read a line)
  //get the length of each part
  
  while (getline(&buffer,&len,fp)>0)
    //(not reaching the end of the file)
    {
      int arrlen;
      //buffer = fscanf("%s\n",fp);//read next line of file
      char ** strArr = explode(buffer,"\t",&arrlen);//explode that line
      
      if (arrlen == 7)//make sure there are all 8 elements for address
	{
	  int bus_id = atoi(strArr[0]);//insert id first
	  int * offsets = get_offsets(strArr,offset,offsets);
	  if (bus_id != last_id)//count number of id
	    {
	      num_id++;
	      last_id = bus_id;
	    }
	//insert node to bustree	
	  root = BusTree_insert(root, strArr[1],
				bus_id,offsets[0],offsets[1],offsets[2],offsets[3]);
	  file offset = ftell(fp);
	  destroystringarray(streArr,arrlen);
	  free(offsets);
	}
    }
  fseek(fp,0,SEEK_SET);
  free(buffer);
  fclose(fp);
  //---------working on review now------------                                               
  Review * review = malloc(sizeof(Review)*num_id);
  filename = reviews_path;
  
  fp = fopen(filename,"r");

  if(fp == NULL)
    {
      printf("File error.");
      return NULL;
    }
  

  
}

void StrArr_destory(char **,int);
void StrArr_destory(char ** strArr, int len)
{
  int ind;
  for (ind = 0, ind < len, ind++)
    {
      free(strArr[ind]);
    }
  free(strArr);
}
