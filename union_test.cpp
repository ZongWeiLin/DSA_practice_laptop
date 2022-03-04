#include <stdio.h>
#include <stdlib.h>

//enum-practice//

// enum Action{
//     // stop,right,left,up,down
//     stop=2,right,left,up,down//let stop=2,and right=3(由stop開始算)
//     // stop=1,right=4,left=3,up=2,down=5//也能直接在列舉給值
// };

// void play(Action action){
// switch (action)
// {
// case stop:
// puts("停止\n");
//     break;
// case right:
// puts("右\n");
//     break;
// case left:
// puts("左\n");
//     break;
// case up:
// puts("上\n");
//     break;
// case down:
// puts("下\n");
//     break;
// default:
// puts("無此動作");
//     break;
// }
// }



// int main(void)
// {   play(stop);
//     printf("%d\n",stop);
//     printf("%d\n",right);

//     system("pause");
//     return 0;
// }

//union-test//
enum  datatype{CHAR,INT} type;
typedef struct 
{   union value
    {
    int ivalue;
    char cvalue;
    }value;//使用Union,value的data就被放在同一個memoryspace

    datatype type;    
}Head;

// typedef struct 
// {   
//     int ivalue;
//     char cvalue;//一般使用structure的case,ivalue,cvalue,被放在不同的memory space

//     datatype type;    
// }Head;

void readint (Head *v,int a){
    v->value.ivalue=a;
    v->type =INT;
}

void readchar (Head *v,char a){
    v->value.cvalue=a;
    v->type = CHAR;
}


void print(Head *v){
    switch (v->type)
    {
    case INT:
        printf("%d\n",v->value.ivalue);
        break;
    case CHAR:
        printf("%c\n",v->value.cvalue);
        break;
    default:
         printf("沒有此資料");
        break;
    }
}

int main(void)
{   Head data;
    readint(&data,10);
    print(&data);
    readchar(&data,'A');
    print(&data);
    system("pause");
    return 0;
}


