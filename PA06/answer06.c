
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void print_directions(char** maze, int w, int h)
{
  int i;
  int prex,prey;//previous location
  int x,y;//current location
  y = 1;
  for (i = 0; i<w;i++)
    {
      if (maze[i][1] == " ")
	{
	  x = i;
	}
    }
  makemove(maze,w,h,x,y,prex,prey);
 }


int makemove(char **maze,int w,int h, int x, int y, int prex, int prey)
{
  prex = x;
  prey = y;
  //record the last step 
  //in case reaching dead end
  if (x != w)
    {
      
      if (maze[x+1][y] == " ")
	{
	  printf("E 1");
	  makemove(maze,w,h,x++,y,prex,prey);      
	}
    }
  if (y != h)
    {
      if (maze[x][y+1] == " ")
	{
	  printf("S 1");
	  makemove(maze,w,h,x,y++,prex,prey);    
	}
    }
  if (x != 1)
    {
      if (maze[x-1][y] == " ")
	{
	  printf("W 1");
	  makemove(maze,w,h,x--,y,prex,prey);   
	}
    }
  if (y!= 1)
    {
      if (maze[x][y-1] == " ")
	{
	  printf("N 1"); 
	  makemove(maze,w,h,x,y--,prex,prey); 
	}
    }
  if (y == 2) && (maze[x][y-1] == " ")
		{
		  printf("N 1");
		  break;
		}
  if (y == h - 1) && (maze[x][y+1] == " ")
		{
		  printf("S 1");		  
		  makemove(maze,w,h,x,y--,prex,prey); 
		}
  printf("pre x and pre y not used");
}
