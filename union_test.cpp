#include <stdio.h>
#include <stdlib.h>

//enum-practice//

// enum Action{
//     // stop,right,left,up,down
//     stop=2,right,left,up,down//let stop=2,and right=3(��stop�}�l��)
//     // stop=1,right=4,left=3,up=2,down=5//�]�ઽ���b�C�|����
// };

// void play(Action action){
// switch (action)
// {
// case stop:
// puts("����\n");
//     break;
// case right:
// puts("�k\n");
//     break;
// case left:
// puts("��\n");
//     break;
// case up:
// puts("�W\n");
//     break;
// case down:
// puts("�U\n");
//     break;
// default:
// puts("�L���ʧ@");
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
    }value;//�ϥ�Union,value��data�N�Q��b�P�@��memoryspace

    datatype type;    
}Head;

// typedef struct 
// {   
//     int ivalue;
//     char cvalue;//�@��ϥ�structure��case,ivalue,cvalue,�Q��b���P��memory space

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
         printf("�S�������");
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


