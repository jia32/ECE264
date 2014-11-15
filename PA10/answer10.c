#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer10.h"

/*
struct YelpDataBST_t{

}



struct YelpDataBST* create_business_bst(const char* businesses_path,
                                        const char* reviews_path);

struct Business* get_business_reviews(struct YelpDataBST* bst,
                                      char* name, char* state, char* zip_code);

void destroy_business_bst(struct YelpDataBST* bst);
void destroy_business_result(struct Business* b);
*/

//--------------------------------BusLoc
//BusLoc: Linked list indexed by id (sorted)
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
