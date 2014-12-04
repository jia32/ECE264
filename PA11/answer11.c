#include <stdio.h>
#include <answer11.h>
HuffNode * HuffNode_create(int value)
{
  HuffNode * root;
  root->value = value;
  root->left = NULL;
  root->right = NULL;
  return root;
}

void HuffNode_destroy(HuffNode * tree)
{
  if (tree == NULL)
    return;
  HuffNode_destroy(tree->left);
  HuffNode_destroy(tree->right);
  free(root);
}

Stack * Stack_create()
{
  Stack * root = NULL;
  root->head = NULL;
  root->head->tree = NULL;
  root->head->next = NULL;
  return root;
}

void Stack_destroy(Stack * stack);
{
  if(stack == NULL)
    return;
  StackNode * itr = stack->head;
  while (itr != NULL)
    {
      StackNode * next = itr->next;
      HuffNode_destory(itr->tree);
      itr = next;
    }
  free(stack);
}

int Stack_isEmpty(Stack * stack)
{
  StackNode * node = stack->head;
  if (node == NULL)
    return 1;
  return 0;
}

HuffNode * Stack_popFront(Stack * stack)
{
  if(stack->head == NULL)
    {
      printf("Error: NULL stack head.\n");
      return NULL;
    }
  StackNode * node = stack->head;
  stack->head = node->next;
  HuffNode * tree = node->tree;
  free(node);
  return tree;
}

void Stack_pushFront(Stack * stack, HuffNode * tree)
{
  StackNode * node = malloc(sizeof(StackNode));
  node->tree = tree;
  node->next = stack->head;
}

void Stack_popPopCombinePush(Stack * stack)
{
  HuffNode * right = Stack_popFront(stack);
  HuffNode * left = HuffNode_create(stack);
  
  HuffNode * root = HuffNode_create(NULL);
  root->left = left;
  root->right = right;

  Stack_pushFront(stack, root);
}

//HuffNode * HuffTree_readTextHeader(FILE * fp);
//HuffNode * HuffTree_readBinaryHeader(FILE * fp);

