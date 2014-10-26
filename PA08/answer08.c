#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

List * List_createNode(const char * str)
{

}
void List_destroy(List * list)
{
}
int List_length(List * list)
{
}
List * List_merge(List * lhs, List * rhs,
		  int (*compar)(const char *, const char*))
{
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{
}
