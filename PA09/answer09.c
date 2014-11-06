#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"


BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode *new0;
  new = malloc(sizeof(BusinessNode));
  new->name = malloc(sizeof(char)*name);
  strcpy(new->name,name);
  new->stars = malloc(sizeof(char)*stars);
  strcpy(new->stars,stars);
  new->address = malloc(sizeof(char)*address);
  strcpy(new->address,address);
  new->left = NULL;
  new->right = NULL;
  return new;
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if (node == NULL)
    {
      return create_node(root->stars,root->name,root->address);
    }
  int compar = strcmp(node->name,root->name);
  if (compar <= 0)
    {
      node->left=tree_insert(node->left,root);
    }
  if (compar > 0)
    {
      node->right = tree_insert(node->right,root);
    }
  return node;
}

BusinessNode * load_tree_from_file(char * filename)
{
  
}
/*
BusinessNode *
tree_search_name(char * name, BusinessNode * root);
void
print_node(BusinessNode * node);
void
print_tree(BusinessNode * tree);
void
destroy_tree(BusinessNode * root);
*/
