#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"
/*思路

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
void move(int *, int *, int );


void print_direction_helper(char ** maze, int w, int h,int row, int col)
{
  int step = 0;
  int dir = 1;
  do{
    move(maze,&row,&col,&step);
  }while((canMove(dir))&&(!canMove(penp)));
  printmove(dir,step);
  print_direction_helper(maze,w,h,r,c);
  //undo
  printmove(dir,step);
}



void move(char ** maze, int * row, int *col, int *step)
{
  if(maze[row][col] == ' ')
    {
      step++;
      col++;
      move(maze,row,col,step);
    }
  return;
}

void printmove(int dir, int step)
{
  if (dir == 
}
