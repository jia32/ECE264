#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"

int main(int argc, char ** argv)
{/*
  //BusinessNode * root = create_node(strdup("5.0"),strdup("a"), strdup("1 Union Street"));
  //root->left = create_node(strdup("3.5"),strdup( "c"),strdup("205 MacArthur Drive"));
  //root->right = create_node(strdup("4.0"), strdup("g"), strdup("108 MacArthur Drive"));
  //root->left->right = create_node(strdup("1.5"),strdup("left->right"),strdup("89 Salisbury Street"));
  //print_tree(root);
  BusinessNode * root = NULL;
  BusinessNode * test = create_node(strdup("3.0"),strdup("d"),strdup("898 Drive"));
  //BusinessNode * test = NULL;
  //print_tree(test);
  //printf("-----Insert a node-----\n");
  root = tree_insert(test,root);  
  //printf("==================\n");
  print_tree(root);
 
  //root = tree_search_name("c",root);

  //print_node(root);
  //destroy_tree(test);
  destroy_tree(root);
  */  

  
  BusinessNode * root = load_tree_from_file(argv[1]);
  
  BusinessNode * node = tree_search_name("Pine Cone Restaurant",root);
  print_node(node);
  node = tree_search_name("Culver's",root);
  print_node(node);
  node = tree_search_name("Air Quality Systems",root);
  print_node(node);
  
  //destroy_tree(node);
  destroy_tree(root);
  /*
   
  FILE *fp = NULL;
  fp = fopen(argv[1],"rb");
  if (fp == NULL)//check valid
    {
      printf("File error\n");
      return EXIT_FAILURE;
    }
  char *stars = malloc(sizeof(char)*500);
  char *names = malloc(sizeof(char)*1000);
  char *address = malloc(sizeof(char)*1000);
  while (!feof(fp))  
     {   
	fscanf(fp,"%[^\t]\t%[^\t]\t%[^\n]\n", stars,names,address);
	printf(":%s\t%s\t%s\n",stars,names,address);
      }
  fclose(fp);
  */
  return EXIT_SUCCESS;
}
