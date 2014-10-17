
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void print_directions(char** maze, int w, int h)
{
  int i;
  int prex,prey;//previous location
  int col,row;//current location
  int dir; //1-right,2-down,3-left,4-up
  col = 0;
  for (i = 0; i<w;i++)
    {
      if (maze[0][i] == " ")
	{
	  row = i;
	}
    }
  printf("S 1");
  col++;
 }

int canmove(maze, col, row, dir)
{
  
}
  int move(maze, col, row)
{
}
