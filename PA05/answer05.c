#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partitionAll(int);
void partitionOdd(int);
void partitionEven(int);
void partitionOddAndEven(int);
void partitionPrime(int);
void partitionIncreasing(int);
void partitionDecreasing(int);

void partitionAll_helper(int,int*,int);
void partitionOdd_helper(int,int*,int);
void partitionEven_helper(int,int*,int);
void partitionOddAndEven_helper(int,int*,int);
void partitionPrime_helper(int,int*,int);
void partitionIncreasing_helper(int,int*,int);
void partitionDecreasing_helper(int,int*,int);

int main(int argc, const char * argv[])
{
  int n;
  if (argc < 2)
    {
      printf("need one positive interger.\n");
      return EXIT_FAILURE;
    }
  n = strtol(argv[2],NULL,0);
  if (strcmp(argv[1],"All") == 0)
    {
      partitionAll(n);
    }
  if (strcmp(argv[1],"Odd") == 0)
    {
      partitionOdd(n);
    }
    if (strcmp(argv[1],"Even") == 0)
    {
      partitionEven(n);
    }
    if (strcmp(argv[1],"Decreasing") == 0)
    {
      partitionDecreasing(n);
    }
    if (strcmp(argv[1],"Increasing") == 0)
    {
      partitionIncreasing(n);
    }
    if (strcmp(argv[1],"Prime") == 0)
    {
      partitionPrime(n);
    }
    if (strcmp(argv[1],"OAE") == 0)
    {
      partitionOddAndEven(n);
    }
  return EXIT_SUCCESS;
}


void partitionAll(int value)
{
  int * arr;
  arr = malloc (sizeof(int)*value);
  partitionAll_helper(value,arr,0);
  free(arr);
}

void partitionOdd(int value)
{
  int * arr;
  arr = malloc (sizeof(int)*value);
  partitionOdd_helper(value,arr,0);
  free(arr);
}

void partitionEven(int value)
{
  int * arr;
  arr = malloc (sizeof(int)*value);
  partitionEven_helper(value,arr,0);
  free(arr);
}

void partitionIncreasing(int value)
{
  int * arr;
  arr = malloc (sizeof(int)*value);
  partitionIncreasing_helper(value,arr,0);
  free(arr);
}

void partitionDecreasing(int value)
{
  int * arr;
  arr = malloc (sizeof(int)*value);
  partitionDecreasing_helper(value,arr,0);
  free(arr);
}

void partitionOddAndEven(int value)
{
  int * arr;
  arr = malloc (sizeof(int)*value);
  partitionOddAndEven_helper(value,arr,0);
  free(arr);
}

void partitionPrime(int value)
{
  int * arr;
  arr = malloc (sizeof(int)*value);
  partitionPrime_helper(value,arr,0);
  free(arr);
}


void partitionAll_helper(int n ,int * arr, int ind)
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
        partitionAll_helper(n-i,arr,ind); 
    }
}


void partitionOdd_helper(int n ,int * arr, int ind)
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
	partitionOdd_helper(n-i,arr,ind);  
    }
}

void partitionEven_helper(int n ,int * arr, int ind)
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
	partitionEven_helper(n-i,arr,ind);  
    }
}



void partitionIncreasing_helper(int n ,int * arr, int ind)
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
	    partitionIncreasing_helper(n-i,arr,ind);  
	  }

    }
}

void partitionDecreasing_helper(int n ,int * arr, int ind)
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
	    partitionDecreasing_helper(n-i,arr,ind);  
	  }
    }
}

void partitionPrime_helper(int n ,int * arr, int ind)
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
	if (n==2)
	  {
	    partitionPrime_helper(n-i,arr,ind);  
	  }
	int k;
	for (k = 3;k<n;k++)
	  {
	    if (n%k != 0)
	      {
		partitionPrime_helper(n-i,arr,ind);  
	      }	  
	  }
    }
}

void partitionOddAndEven_helper(int n, int *arr, int ind)
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
    
  for (i = 1; i<=n; i++)
    {
      arr[ind] = i;
      //printf("\n%d,%d\n",arr[ind-1],arr[ind]);
      if ((arr[ind-1] %2 != arr[ind]%2) || (arr[ind-1]==0))
       {
	 partitionOddAndEven_helper(n-i,arr,ind);
       }
    } 
}
