#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"

int main(int argc, char ** argv)
{
  BusinessNode * root = create_node("5.0", "root", "1 Union Street");
  root->left = create_node("3.5", "left","205 MacArthur Drive");
  root->right = create_node("4.0", "right", " 108 MacArthur Drive");
  root->left->right = create_node("1.5","left->right","89 Salisbury Street");
  print_tree(root);
  destroy_tree(root);
  return EXIT_SUCCESS;
}
