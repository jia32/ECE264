#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "answer09.h"

int main(int argc, char ** argv)
{
  BusinessNode * root = create_node("5.0", "Wiley", "107 Union Street");
  root->left = create_node("3.5", "Earhart","205 MacArthur Drive");
  root ->right = create_node("4.0", "Hillenbrand", " 108 MacArthur Drive");
  root->left->right = create_node("1.5","Ford","89 Salisbury Street");
  print_tree(root);
  return EXIT_SUCCESS;
}
