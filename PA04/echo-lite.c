#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{  
  int val;
  while (scanf(fptr, "%s", &val) ==1)
    {
      printf("val is %d\n", val);
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}
