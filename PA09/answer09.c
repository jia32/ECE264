#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"


BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode *new;
  new = malloc(sizeof(BusinessNode));
  new->name = malloc(sizeof(char)*(1+strlen(name)));
  strcpy(new->name,name);
  new->stars = malloc(sizeof(char)*(1+strlen(stars)));
  strcpy(new->stars,stars);
  new->address = malloc(sizeof(char)*(1+strlen(address)));
  strcpy(new->address,address);
  new->left = NULL;
  new->right = NULL;
  return new;
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if (root == NULL)
    {
      return create_node(node->stars,node->name,node->address);
    }
  int compar = strcmp(root->name,node->name);
  if (compar <= 0)
    {
      root->left=tree_insert(root->left,node);
    }
  if (compar > 0)
    {
      root->right = tree_insert(root->right,node);
    }
  return root;
}

/*
BusinessNode * load_tree_from_file(char * filename)
{
  
}

BusinessNode *
tree_search_name(char * name, BusinessNode * root);
*/

void print_node(BusinessNode * node)
{
  
}


void print_tree(BusinessNode * tree)
{
  if(tree == NULL)
    {
      return;
    }
  printf("name is %s\n", tree->name);
  printf("stars is %s\n",tree->stars);
  printf("address is %s\n",tree->address);
  printf("-------------------\n");
  print_tree(tree->left);
  print_tree(tree->right);
  return;
}


void destroy_tree(BusinessNode * root)
{
  //printf("---Destroying %s---\n",root->name);
  //printf("next is %s\n",root->left->name);
  //printf("if %s is NULL: %d\n",root->name, (root==NULL));
  if (root==NULL)
  {
    printf("Reaching to an end.\n");
    return;
  }
  destroy_tree(root->left);
  destroy_tree(root->right);
  free(root->name);
  free(root->stars);
  free(root->address);
  free(root);
  return;
}

