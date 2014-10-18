
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"
/*
  思路

1.canmove判断能否前进，能返回1，不能返回0
2.move，往指定方向前进
3.循环，do move while canmove1且canmove垂直方向0
4.循环结束意味着deadend，undo move，输出
5.调整方向(垂直方向），重新循环->recurse
6.直到回到起点（用.标记）

关于变量
int dir //1-East,-2-South,-1-West,2-North

现在的问题：
关于初始位置
*/
void print_directions(char ** maze, int w, int h)
{
        int col;
        int row = 0;
        int i;
        for (i=0;i<w,i++)
        {
                if (maze[0][i] == " ")
                        {
                                col = i;
                                i = w;
                        }
        }
        maze[row][col] = ".";
        print_direction_help(maze,col,row,-2,h,-1);
}

void print_direction_help(char ** maze, int col, int row, int dir,int h,int step)
{
        int penp;//calculate the penperdicular direction
        int i;
        if (dir == 1 || dir == -1)
        {
                penp = 2;
        }
        if (dir == -2 || dir == 2)
        {
                penp = 1;
        }
        do{
                move(&col,&row,dir);
                step++;
        }while (canmove(maze,col,row,dir,h)==1) && ((canmove(maze,col,row,penp,h) == 0) && (maze,col,row,-penp,h) == 0));
        if (canmove(maze,col,row,penp,h) == 1)
        {
                printf("%d %d",dir,step);
                print_direction_help(maze, col, row, penp,h,0);
        }
        
        else if (canmove(maze,col,row,-penp,h) == 1)
        {                
                printf("%d %d",dir,step);
                print_direction_help(maze, col, row, -penp,h,0);
        }
        else{
        
        if (dir == 1)
        {
                printf("E %d",step);
                col = col - step;
                printf("W %d",step);
                dir = -2;
        }        
        if (dir == -2)
        {
                printf("S %d",step);
                row = row - step
                printf("N %d",step);
                dir = -1;
        }        
        if (dir == -1)
        {
                printf("W %d",step);
                col = col + step;
                printf("E %d",step);
                dir = 2;
        }        
        if (dir == 2)
        {
                printf("N %d",step);
                row = row + step;
                printf("E %d",step);
                dir = 1;
        }
        }
        if (maze[row][col] == ".")
        {
                break;
        }
        print_direction_help(maze, col, row, dir,h,0);                        
}

int canmove(char ** maze, int col, int row, int dir, int w, int h)

{
        if ((row<=0)||(row>=h)||(col<=0)||(col>=w))
        {
                return 0;
        }
        if (dir == 1) && (maze[row][col+1] == " ")
        {        
                return 1;//East is good
        }

        if (dir == -2) && (maze[row+1][col] == " ")
        {        
                return 1;//South is good
        }

        if (dir == -1) && (maze[row][col-1] == " ")
        {        
                return 1;//West is good
        }

        if (dir == 2) && (maze[row-1][col] == " ") && (row != h)
        {        
                return 1;//North is good
        }
        return 0;//"X" in this direction
}

void move(int *col, int *row, int dir)
{
        if (dir == 1)
        {        
                *col++;//Move East
        }

        if (dir == -2)
        {        
                *rol++;//Move South
        }

        if (dir == -1)
        {        
                *col--;//Move West
        }

        if (dir == 2)
        {        
                *row--;//Move North
        }
}
