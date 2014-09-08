#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int ind;
    int sum = 0;
    for(ind = 0; ind < len; ++ind){
        sum += array[ind];
    }
    return sum;
}

int arrayCountNegative(int * array, int len)
{
    int ind;
    int count = 0;
    for(ind = 0; ind < len; ++ind){
        if (array[ind] < 0){
            count++;
        }
    }
    return count;
}


int arrayIsIncreasing(int * array, int len)
{    
    int ind;
    int isInc = 1;
    if (len ==0){
        return 1;
    }else if (len == 1){
        return 1;
    }
    
    for(ind = 1; ind < len; ind++){
        if (array[ind-1] > array[ind]){
            isInc = 0;
	    ind = len;
        }
    }   
    return isInc;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    int ind;
    int x = -1;
    for(ind = 0; ind < len; ++ind){
        if (haystack[ind] == needle){
            x = ind;
        }
    }
    return x;
}

int arrayFindSmallest(int * array, int len)
{
    int ind;
    int minind = 0;
    int min = array[0];
    if (len == 0){
        return 0;
    }else if (len == 1){
        return 0;
    }
    
    for(ind = 1; ind < len; ind++){
         if (array[ind] < min){
           min = array[ind];
           minind = ind;
        }
    }
    return minind;
}
