#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void move(char**,int,int,int);

void print_directions(char ** maze, int w, int h)
{
        int col;
        int row = 0;
        int i;
	//int j;
        for (i=0;i<w;i++)
	  {
	    if (maze[0][i] == ' ')
	      {
		col = i;
		i = w;
	      }
	  }
	
	printf("Entrance: row  %d, col %d\n",row,col);
	maze[row][col] = '.';
        row = 1;
	/*
	  for (j=0;j<w;i++)
	  {
	  if (maze[h][j] == ' ')
	  {
	  maze[h+1][j] = 'X';
	  i = w;
	  }
	  }*/
        move(maze,row,col,2);
	return;
}

//from is the veriable that record the direction where you come from
//and  1-east,-1-west,-2-south,2-north


void move(char ** maze, int row, int col, int from)
{
  /*
  if (maze[row-1][col] == '.' && from == -2)
    {
      return;
    }
  */
  //printf("row  %d, col %d, from %d\n",row,col,from);
  
  if (maze[row][col+1] == ' ' && from != 1)
    {
      printf("E 1\n");
      move(maze,row,col+1,-1);
      printf("W 1\n");
    }

  if (maze[row][col-1] == ' ' && from != -1)
    {
      printf("W 1\n");
      move(maze,row,col-1,1);
      printf("E 1\n");
    }

  if (maze[row+1][col] == ' ' && from != -2)
    {
      printf("S 1\n");
      move(maze,row+1,col,2);
      printf("N 1\n");
    }
  
  if (maze[row-1][col] == ' ' && from != 2)
    {
      printf("N 1\n");
      move(maze,row-1,col,-2);
      printf("S 1\n");
    }
}
