#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"


BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode *new;
  new = malloc(sizeof(BusinessNode));
  new->name = name;
  new->stars = stars;
  new->address = address;
  new->left = NULL;
  new->right = NULL;
  return new;
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if (root == NULL)
    {
      return create_node(strdup(root->stars),strdup(node->name),strdup(node->address));
    }
  int compar = strcmp(root->name,node->name);
  if (compar <= 0)
    {
      root->left=tree_insert(node,root->left);
    }
  if (compar > 0)
    {
      root->right = tree_insert(node,root->right);
    }
  return root;
}


BusinessNode * load_tree_from_file(char * filename)
{
  FILE *fp = NULL;
  fp = fopen(filename,"rb");
  if (fp == NULL)//check valid
    {  
      printf("File error\n");
      return NULL;
    }
  fseek(fp,0,SEEK_END);
  long int size = ftell(fp);//get the size of the file
  fseek(fp,0,SEEK_SET);//get back to beginning
  char * buffer;
  buffer = malloc(sizeof(char)*(size+1));
  fread(buffer,sizeof(char),size,fp);//read all the file
  
  char * stars;
  char * name;
  char * address;
  char * s1 = "\t";
  char * s2 = "\n";
  BusinessNode * root;
  BusinessNode * node;
  stars = strtok(buffer,s1);
  name = strtok(buffer,s1);
  address = strtok(buffer,s2);
  //create root;
  root = create_node(stars,name,address);
  //keep creating node until no "\t" is found
  stars = strtok(buffer,s1);
  while (stars != NULL)
    {
      name = strtok(buffer,s1);
      address = strtok(buffer,s2);
      node = create_node(buffer,name,address);
      root = tree_insert(node,root);
      stars = strtok(buffer,s1);
    }
  free(buffer);
  fclose(fp);
  return root;
}


BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  //printf("name: %s\n",root->name);
  BusinessNode * node = NULL;
  if (root == NULL)
    return NULL;
  else
    {
      int compar = strcmp(root->name, name);
      if (compar == 0)
	{
	  //printf("Got it: %s\n",root->name);
	  return root;
	}
      node = tree_search_name(name,root->right);
      if (node != NULL)
	{
	  return node;
	}
      //printf("nothing on the right\n");
      
      node = tree_search_name(name,root->left);
      if (node != NULL)
	{
	  return node;
	}
      //printf("nothing on the left\n");
    } 
  //printf("Nope nothing\n");
  return NULL;
}


void print_node(BusinessNode * node)
{
  if (node == NULL)
    {
      printf("NULL node\n");
      return;
    }
  printf("\n%s\n",node->name);
  printf("========\n");
  printf("Stars:\n  %s\n",node->stars);
  printf("Address:\n  %s\n",node->address);
  return;
}


void print_tree(BusinessNode * tree)
{
  if(tree == NULL)
    {
      return;
    }
  print_node(tree);
  print_tree(tree->left);
  print_tree(tree->right);
  return;
}


void destroy_tree(BusinessNode * root)
{
  if (root==NULL)
  {
    //printf("Reaching to an end.\n");
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

