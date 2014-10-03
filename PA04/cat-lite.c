#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int main(int argc, char * * argv)
{
  int showHelp = FALSE;
  int badSwitch = FALSE;
  int showReadme = FALSE;
  int ind = 1;
  for ( ; ind < argc; ++ind)
    {
      if(strcmp(argv[ind], "--help") ==0)
	{
	  showHelp = TRUE; 
	}
      else if(strcmp(argv[ind],"-") ==0)
	{
          stdin
	}
      else if(strcmp(argv[ind],"README" ==0)
	{
	  printf(stdout,fgetc(argv[ind]);
	}
      
      else if (fgetc(strcmp[ind] == -1)
	{
	  printf("cat cannot open %s", argv[ind]);
        }
    }


  if (showHelp)
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
  return EXIT_SUCCESS;
}
