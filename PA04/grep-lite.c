#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int main(int argc, char * * argv)
{
  int ind = 1;
  int line = 1;
  int status = 1;
  char* pattern = argv[argc-1];
  char*buff;
  for( ; ind < argc; ++ind)
    {
      if (strcmp(argv[ind],"--help")  == 0)
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
		   "if any error occurs, then the exit status is 2.");
		   return EXIT_SUCCESS;
	  }
      
      else  if (strstr(argv[argc-1],"-") == argv[argc-1])
	{  
	  printf("Pattern could not start with -, try another pattern\n");
	  return 2;
	}
    for( ; ind < argc - 1; ++ind)
      {
	if (strcmp (argv[ind],"-v") ==0)
	  {	    
	    buff = malloc(sizeof(char)*2000);
	    while (!feof(stdin))
	      {
		if (strstr(buff,pattern) == NULL)
		  {
		    printf("%s",buff);
		    status = 1;
		  }
		else
		  {
		    status =  0;
		  }
	      }
	    free(buff);
	  }
	else  if (strcmp (argv[ind],"-n") ==0)
	  {
	    
	    buff = malloc(sizeof(char)*2000);
	    while (!feof(stdin))
	      {
		  fgets(buff,2000,stdin);
		  line++;
		  if (strstr(buff,pattern) == NULL)
		    {
		      status= 1;
		    }
		  else
		    {
		      printf("%d: %s",line,buff);
		      status = 0;
		    }
	      }
	    free(buff);
	  }
	else if (strcmp (argv[ind],"-q") ==0)
	  {
	    
	    buff = malloc(sizeof(char)*2000);
	    while (!feof(stdin))
	      {
		if (strstr(buff,pattern) == NULL)
		  { 
		    status = 1;
		  }
		else
		  {
		    status =  0;
		  }
	      }
	    free(buff);
	  }
	else
	  {
	    buff = malloc(sizeof(char)*2000);
	    while (!feof(stdin))
	      {
		fgets(buff,2000,stdin);
		if (strstr(buff,pattern) == NULL)
		  {
		    status = 1;
		  }
		else
		  {
		    printf("%s",buff);
		    status= 0;
		  }
	      }
	    free(buff);
	  }
	    
      }
    }


  return status;
}
