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

        for (i=0;i<w;i++)
        {
                if (maze[0][i] == ' ')
                        {
                                col = i;
                                i = w;
                        }
        }
	
        //maze[row][col] = ".";
        
        for (i=0;i<w;i++)
        {
                if (maze[h][i] == ' ')
                        {
                                maze[h+1][i] = 'X';
                                i = w;
                        }
        }
        move(maze,col,row,2);
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
        if (maze[row][col+1] == ' ' && from != -1)
        {
	  printf("E 1");
	  move(maze,row,col++,-1);
	  printf("W 1");
        }
	
	
        if (maze[row][col-1] == ' ' && from != 1)
	  {
	    printf("W 1");
	    move(maze,row,col--,1);
	    printf("E 1");
        }
	
        if (maze[row+1][col] == ' ' && from != 2)
	  {
	    printf("S 1");
	    move(maze,row++,col,2);
	    printf("N 1");
	  }
	
        if (maze[row-1][col] == ' ' && from != -2)
	  {
	    printf("N 1");
	    move(maze,row--,col,-2);
	    printf("S 1");
        }
}
