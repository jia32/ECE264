
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void print_directions(char** maze, int w, int h)
{
  int i;
  int prex,prey;//previous location
  int x,y;//current location
  int dir;//1-right, 2-down, 3-left,4-up
  y = 0
  for (i = 0; i<w;i++)
    {
      if (maze[i][1] == " ")
	{
	  x = i;
	}
    }
  makemove(maze,x,y);
 }


int makemove(char **maze,int x, int y)
{
  if (
  if (maze[x+1][y] == " ")
    {
      printf("E 1");
      makemove(maze,x++,y);      
    }
  if (maze[x][y+1] == " ")
    {
      printf("S 1");
      makemove(maze,x,y++);         
    }

  if (maze[x-1][y] == " ")
    {
      printf("W 1");
      makemove(maze,x--,y);
    }

  if (maze[x][y-1] == " ")
    {
      makemove(maze,x,y--);   
      printf("N 1"); 
    }
  
}
