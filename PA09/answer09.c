#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"


BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode *new;
  new = malloc(sizeof(BusinessNode));
  new->name =  name;
  new->stars = stars; 
  new->address = address; 
  new->left = NULL; 
  new->right = NULL;
  return new; 
}


BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root) 
{ 
  if (node == NULL) 
    { 
      return root; 
    } 
  if (root == NULL) 
    {
      return node;
    }
  else
    {
      int compar = strcmp(node->name,root->name);
      if (compar <= 0)
	{       
	  root->left=tree_insert(node,root->left); 
	} 
      else if (compar > 0)
	 { 
	   root->right = tree_insert(node,root->right);
	 }
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
  char stars[3]; 
  char name[200];
  char address[200];
  
  BusinessNode * root; 
  BusinessNode * node; 
  
  fscanf(fp,"%[^\t]\t%[^\t]\t%[^\n]\n",stars,name,address);
  //printf("%s\t%s\t%s\n",stars,name,address);
  //printf("%d\n",strlen(name));
  root = create_node(strdup(stars),strdup(name),strdup(address));
  //print_node(root);
  //node = create_node(strdup(stars),strdup(name),strdup(address));
  
  while(!feof(fp))
    {
      fscanf(fp,"%[^\t]\t%[^\t]\t%[^\n]\n",stars,name,address);
      node = create_node(strdup(stars),strdup(name),strdup(address));
      root = tree_insert(node,root);
      //destroy_tree(node);
    }
  fclose(fp);
  //destroy_tree(node);
  return root;
}


BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  //printf("name: %s\n",root->name);
  if (root == NULL)
    return NULL;
  int compar = strcmp(name, root->name);
  if (compar == 0)
    {
      //printf("Got it: %s\n",root->name);
      return root;
    }
  if (compar < 0)
    return tree_search_name(name,root->left);
  return tree_search_name(name,root->right);
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
  free(root->stars);
  free(root->name);
  free(root->address);
  free(root);
  return;
}

