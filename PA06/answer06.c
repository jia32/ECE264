#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void move(char**,int,int,int,int);

void print_directions(char ** maze, int w, int h)
{
        int col;
        int row = 0;
        int i;
        for (i=0;i<w;i++)
	  {
	    if (maze[0][i] == ' ')
	      {
		col = i;
		i = w;
	      }
	  }
	
	printf("Entrance: row  %d, col %d,h %d\n",row,col,h-1);
	maze[row][col] = '.';
        row = 1;

	printf("S 1\n");
        move(maze,row,col,2,h-1);
	return;
}

//from is the veriable that record the direction where you come from
//and  1-east,-1-west,-2-south,2-north


void move(char ** maze, int row, int col, int from,int h)
{
  /*
  if (maze[row-1][col] == '.' && from == -2)
    {
      return;
    }
  */
  printf("row  %d, col %d, from %d\n",row,col,from);

  if (maze[row][col+1] == ' ' && from != 1) //Heading East for 1 unit
    {
      printf("E 1\n");
      move(maze,row,col+1,-1,h);
      printf("W 1\n");
    }

  if (maze[row][col-1] == ' ' && from != -1) //Heading West for 1 unit
    {
      printf("W 1\n");
      move(maze,row,col-1,1,h);
      printf("E 1\n");
    }

  if (maze[row+1][col] == ' ' && from != -2 && row+1 != h) //Heading South for 1 unit
    {
      printf("S 1\n");
      move(maze,row+1,col,2,h);
      printf("N 1\n");
    }
   else if (maze[row+1][col] == ' ' && from != -2 && row+1 == h)
    {
      printf("S 1\nN 1\n");
      maze[row+1][col] = '.';
      move(maze,row,col,-2,h);
    }

  if (maze[row-1][col] == ' ' && from != 2)//Heading North for 1 unit
    {
      printf("N 1\n");
      move(maze,row-1,col,-2,h);
      printf("S 1\n");
    }
}
