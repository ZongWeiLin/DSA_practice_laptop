#include <stdio.h>
#include <stdlib.h>
#define max_stack_size 14


//define a struct to represent movement//
typedef struct Move
{int vert;
 int heri;
};

enum dircet {up_left,up,up_right,left,right,down_left,down,down_right};
Move move[8];

//define move direction//
void define_direct(){
    move[up_left].heri=-1;move[up_left].vert=-1;    //0 1 2//
    move[up].heri=0;move[up].vert=-1;               //3   4//
    move[up_right].heri=1;move[up_right].vert=-1;   //5 6 7//
    move[left].heri=-1;move[left].vert=0;
    move[right].heri=1;move[right].vert=0;
    move[down_left].heri=-1;move[down_left].vert=1;
    move[down].heri=0;move[down].vert=1;
    move[down_right].heri=1,move[down_right].vert=1;
}

//define stack to store previous step//
typedef struct Stack
{   int row;
    int col;
    int dir;
};

Stack stack[16];

int top=-1;

void push (int col,int row,int dir){
    if(top!=max_stack_size-1){
        top++;
        stack[top].col=col;
        stack[top].row=row;
        stack[top].dir=dir;
    }
    else
    printf("stack is full\n");
}

Stack pop(){
    if(top!=-1)
        return stack[top--];
    else
    printf("stack empty\n");
}


int main(void)
{   define_direct();
    int map[5][5]={{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,1,1,0,1},{1,1,1,1,1}};
    int mark[5][5];
    Stack now_position;
    Stack next_position;
    int found,dir,row,col;
    int exit_col,exit_row;
    //initial exit point
    exit_col=3;exit_row=3;

    //initial start position//
    top=0;mark[1][1]=1;
    stack[0].row=1;stack[0].col=1;stack[0].dir=0;
    

    //printf  map//
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("  %d  ",map[i][j]);
        }
        printf("\n");
    }

    while (top>-1&&!found)
    {   now_position=pop();
        row=now_position.row;col=now_position.col;dir=now_position.dir;
        while(dir<8 &&found!=1)//because dir just have 8 ways,if dir >8 means no dir,jump out the while loop,and go back 
        {   next_position.row=row+move[dir].vert;
            next_position.col=col+move[dir].heri;
            if(next_position.col==exit_col&&next_position.row==exit_row)
            found=true;
            else{
                if(map[next_position.row][next_position.col]==0&&mark[next_position.row][next_position.col]!=1){
                now_position.row=row;now_position.col=col;now_position.dir=dir;//push now position and dir
                push(col,row,dir);
                mark[next_position.row][next_position.col]=1;//標示已走過路徑
                row=next_position.row;col=next_position.col;//move to next point
                dir=0;//because move to next point,so reset dir
                }
                else
                dir++;//change direction
            }
            
        }//find dir
    }

    if(found){
        printf("path:\n");
        for(int i=0;i<=top;i++){
            printf("row:%d,col:%d\n",stack[i].row,stack[i].col);
        }
        printf("row:%d,col:%d\n",row,col);
        printf("row:%d,col:%d\n",exit_row,exit_col);
    }
    



    system("pause");
    return 0;
}