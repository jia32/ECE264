#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"

int main(int argc, char ** argv)
{
  
  BusinessNode * root = create_node(strdup("5.0"),strdup("root"), strdup("1 Union Street"));
  //root->left = create_node("3.5", "left","205 MacArthur Drive");
  //root->right = create_node("4.0", "right", " 108 MacArthur Drive");
  //root->left->right = create_node("1.5","left->right","89 Salisbury Street");
  print_tree(root);
  BusinessNode * test = create_node(strdup("3.0"),strdup("insert"),strdup("898 Drive"));
  print_tree(test);
  printf("-----Insert a node-----\n");
  root = tree_insert(test,root);  
  print_tree(root);

  //root = tree_search_name("left->right",root);

  //print_node(root);

  destroy_tree(root);
  //destroy_tree(test);

  /*
  BusinessNode * root = load_tree_from_file(argv[1]);
  root = tree_search_name("Starbucks",root);
  print_tree(root);
  destroy_tree(root);
  */  
  return EXIT_SUCCESS;
}
