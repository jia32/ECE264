#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int main(int argc, char * * argv)
{
  int showHelp = FALSE;
  int invert = FALSE;
  int linenumber = FALSE;
  int quiet = FALSE;
  int ind = 1;
  
  for( ; ind < argc; ++ind)
    {
      if (strcmp(argv[ind],"--help")==0)
	{
	  showHelp = TRUE;
	}
      else if (strcmp(argv[ind], "-v" ==0)
	{
	  
	}
      else if(strcmp(argv[ind], "-n" ==0)
	{
	  
	}
      else if(strcmp(argv[ind],"-q" ==0)
	{
	  
	}
    }
  if (showHelp)
    {
      printf("Usage: grep-lite [OPTION]... PATTERN\n"
	     "Search for PATTERN in standard input. PATTERN is a\n"
	     "string. grep-lite will search standard input line by\n"
	     "line, and (by default) print out those lines which\n"
	     "contain pattern as a substring.\n\n"
	     "-v, --invert-match     print non-matching lines\n"
	     "-n, --line-number      print line numbers with output\n"
	     "-q, --quiet            suppress all output\n\n"
	     "Exit status is 0 if any line is selected, 1 otherwise;\n"
	     "if any error occurs, then the exit status is 2."
	     return EXIT_SUCESS;
    }
	return 2;

}
