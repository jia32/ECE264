#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void partitionAll(int,int*,int);
void partitionOdd(int,int*,int);
void partitionEven(int,int*,int);
//void partitionOddAndEven(int,int*,int);
void partitionPrime(int,int*,int);
void partitionIncreasing(int,int*,int);
void partitionDecreasing(int,int*,int);

int main(int argc, const char * argv[])
{
  int n;
  int * arr;
  if (argc < 2)
    {
      printf("need one positive interger.\n");
      return EXIT_FAILURE;
    }
  n = strtol(argv[2],NULL,0);
  arr = malloc(sizeof(int)*n);
  if (strcmp(argv[1],"All") == 0)
    {
      partitionAll(n,arr,0);
    }
  if (strcmp(argv[1],"Odd") == 0)
    {
      partitionOdd(n,arr,0);
    }
    if (strcmp(argv[1],"Even") == 0)
    {
      partitionEven(n,arr,0);
    }
    if (strcmp(argv[1],"Decreasing") == 0)
    {
      partitionDecreasing(n,arr,0);
    }
    if (strcmp(argv[1],"Increasing") == 0)
    {
      partitionIncreasing(n,arr,0);
    }
    if (strcmp(argv[1],"Prime") == 0)
    {
      partitionPrime(n,arr,0);
    }
  return EXIT_SUCCESS;
}


void partitionAll(int n ,int * arr, int ind)
{
    ind++; 
    int i;
    int j;
    if (n==0)
    {
      for (j=1; j < ind - 1; j++)
        {
            printf ("%d + ",arr[j]);
        }
        printf("%d\n",arr[ind-1]);
    }
    for (i = 1; i<= n; i++) 
    {
        arr[ind] = i;
        partitionAll(n-i,arr,ind); 
    }
}


void partitionOdd(int n ,int * arr, int ind)
{
    ind++; 
    int i;
    int j;
    if (n==0)
    {
      for (j=1; j < ind - 1; j++)
        {
	      printf ("%d + ",arr[j]);
	}
        printf("%d\n",arr[ind-1]);
    }
    for (i = 1; i<= n; i+=2) 
    {
        arr[ind] = i;
	partitionOdd(n-i,arr,ind);  
    }
}

void partitionEven(int n ,int * arr, int ind)
{
    ind++; 
    int i;
    int j;
    if (n==0)
    {
      for (j=1; j < ind - 1; j++)
        {
	      printf ("%d + ",arr[j]);
	}
        printf("%d\n",arr[ind-1]);
    }
    for (i = 2; i<= n; i+=2) 
    {
        arr[ind] = i;
	partitionEven(n-i,arr,ind);  
    }
}

void partitionIncreasing(int n ,int * arr, int ind)
{
    ind++; 
    int i;
    int j;
    if (n==0)
    {
      for (j=1; j < ind - 1; j++)
        {
	      printf ("%d + ",arr[j]);
	}
        printf("%d\n",arr[ind-1]);
    }
    for (i = 1; i<= n; i++) 
    {
        arr[ind] = i;
	if (arr[ind - 1] < arr[ind])
	  {
	    partitionIncreasing(n-i,arr,ind);  
	  }

    }
}

void partitionDecreasing(int n ,int * arr, int ind)
{
    ind++; 
    int i;
    int j;
    if (n==0)
    {
      for (j=1; j < ind - 1; j++)
        {
	      printf ("%d + ",arr[j]);
	}
        printf("%d\n",arr[ind-1]);
    }
    for (i = 1; i<= n; i++) 
    {
        arr[ind] = i;
	if(((n-i) <= i) && (arr[ind - 1] != i))
	  {
	    partitionDecreasing(n-i,arr,ind);  
	  }
    }
}


void partitionPrime(int n ,int * arr, int ind)
{
    ind++; 
    int i;
    int j;
    if (n==0)
    {
      for (j=1; j < ind - 1; j++)
        {
	      printf ("%d + ",arr[j]);
	}
        printf("%d\n",arr[ind-1]);
    }

    for (i = 1; i<= n; i++) 
    {
        arr[ind] = i;
	partitionPrime(n-i,arr,ind);  
    }
}
