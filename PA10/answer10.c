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
typedef BusLoc_t
{
  int id;
  char *address, *city, * state, * zip;//owned
  BusLoc_t * next;
}BusLoc;

BusLoc * BusLoc_create(int id, char * address, char * city,
		       char * state, char * zip)
{
  BusLoc * head;
  head = malloc(sizeof(BusLoc));
  head->id = id;
  head->address = strdup(address);
  head->city = strdup(city);
  head->state = strdup(state);
  head->zip = strdup(zip);
  head->nest = NULL;
  return head;
}


//BusLoc_insert
void BusLoc_destroy(BusLoc * head)
{
  while (head != NULL)
    {
      BusLoc itr = head->next;
      free(head->zip);
      free(head
}
//BusLoc_print
//test_BusLoc
