#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int main(int argc, char * * argv)
{
  int ind = 1; 
  for ( ; ind < argc; ++ind)
    {
      if(strcmp(argv[ind], "--help") ==0)
	{
	  	    printf("Usage: cat-lite [--help] [FILE]...\n"
		   "With no FILE, or when FILE is -, read standard input.\n\n"
		   "Examples:\n"
		   "cat-lite README   Print the file README to standard output.\n"
		   "cat-lite f - g    Print f's contents, then standard input, \n"
		   "                  then g's contents.\n"
		   "cat-lite          Copy standard input to standard output.\n");
	    return EXIT_SUCCESS; 
	}
    }
  FILE *fptr;
 
  for (ind = 1; ind < argc;++ind)
    {
      if(*argv[ind] != '-')
	{
	  fptr = fopen(argv[ind],"r");
	  if(fptr == NULL)
	    {
	      fprintf(stderr,"cat cannot open %s\n",argv[ind]);
	      return EXIT_FAILURE; 
	    }
	  while (!feof(fptr))
	    {  
	      int c = fgetc(fptr);
	      if (c!=EOF)
		{
		  putchar(c); 
		}
	    }
	  fclose(fptr);
	}
      else
	{
	  while (!feof(stdin))
	    {  
	      int c = fgetc(stdin);
	      if (c!=EOF)
		{
		  putchar(c); 
		} 
	    }
	}
    }
  return EXIT_SUCCESS;
}
