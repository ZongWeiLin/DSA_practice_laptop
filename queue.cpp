#include <stdio.h>
#include <stdlib.h>
#define max_size 100

typedef struct Queue
{   int value;
};


// Queue with array//
// Queue queue[max_size];
// int front=-1,rear=-1;//front指前面,rear指尾端

// void insert (int value){
//     if(rear<max_size-1){
//         rear++;
//         queue[rear].value=value;
//     }
//     else
//     printf("queue is full\n");
    
// }

// int deletes (){
//     if(front!=rear){
//         front++;
//         return queue[front].value;
//     }
//     else{
//         printf("queue is empty\n");
//         front=-1,rear=-1;//reset queue to head//
//         }
// } 



// int main(void)
// {   for(int i=0;i<101;i++){
//     insert(i);}
//     for(int i=0;i<10;i++){
//         printf("%d\n",deletes());
//     }


//     system("pause");
//     return 0;
// }

//Circular Queue with array//
//In circular Queue,must waste a space for determine if queue is full or not//

Queue queue[8];

int front=7,rear=7;

void add(int value){
    if(front!=(rear+1)%8)//rear+1=front means queue is full
    {
    rear=(rear+1)%8;
    queue[rear].value=value;
    }
    else 
    printf("Queue is full\n");
}

int deletes (){
    if(front!=rear)//front = rear means queue is empty
    {
    front=(front+1)%8;
    return queue[front].value;
    queue[front].value=NULL;}
    else
    printf("Queue is empty\n");
}



int main(void)
{   for(int i=0;i<6;i++){
    add(i);}
    for(int i=0;i<8;i++){
    printf("%d\n",deletes());    
    }
    printf("rear=%d\n",rear);
    printf("front=%d\n",front);
    system("pause");
    return 0;
}