#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"
//It moves 1 unit at a time.
//Which means it prints out 'direction 1' all the time
//Based on Readme, I suppose this is acceptable for this homework
//And my path overlaps
void move(char**,int,int,int,int); // my recursive function

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
	//For testing
	//printf("Entrance: row  %d, col %d,h %d\n",row,col,h-1);
	
	maze[row][col] = '.'; // Mark the Entrance as '.'
        row = 1;
	printf("S 1\n"); //Move South for 1 Unit automaticly
        move(maze,row,col,2,h-1);
	return;
}

//from is the veriable that record the direction where you come from
//and  1-east,-1-west,-2-south,2-north

void move(char ** maze, int row, int col, int from,int h)
{
  //For testing
  //printf("row  %d, col %d, from %d\n",row,col,from);

  if (maze[row][col+1] == ' ' && from != 1) //Heading East for 1 unit
    {
      printf("E 1\n");
      move(maze,row,col+1,-1,h);
      printf("W 1\n");
    }

  if (maze[row+1][col] == ' ' && from != -2 && row+1 != h) //Heading South for 1 unit
    {
      printf("S 1\n");
      move(maze,row+1,col,2,h);
      printf("N 1\n");
    }
  else if (maze[row+1][col] == ' ' && row+1 == h) //Hit the Exit
    {
      printf("S 1\nN 1\n");
      maze[row+1][col] = '.'; // Mark the Exit as '.'
      move(maze,row,col,-2,h);
    }

  if (maze[row][col-1] == ' ' && from != -1) //Heading West for 1 unit
    {
      printf("W 1\n");
      move(maze,row,col-1,1,h);
      printf("E 1\n");
    }


  if (maze[row-1][col] == ' ' && from != 2)//Heading North for 1 unit
    {
      printf("N 1\n");
      move(maze,row-1,col,-2,h);
      printf("S 1\n");
    }
}
