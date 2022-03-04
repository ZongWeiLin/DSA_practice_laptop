#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//stack in static allocation//
// typedef struct element{
//     int key;//stack value
// };
// element stack[MAX];
// int top=-1;//top<0,stack is empty

// void push(int value){
//     if (top<MAX)
//     {top++;
//     stack[top].key=value;    }
//     else
//     {printf("stack is full\n");//if top exceed the stack size
//      exit(EXIT_FAILURE);} 
// }

// int pop (){
//     int temp;
//     if(top>=0){
//         temp=stack[top].key;
//         stack[top].key=NULL;
//         top--;
//         return temp;
//     }
//     else
//     {printf("stack is empty\n");
//      exit(EXIT_FAILURE);}
// }


// int main(void)
// {   int temp;
//     for(int i=0;i<10;i++){
//     push(i);}
//     for(int i=0;i<10;i++){
//     temp=pop();}

//     system("pause");
//     return 0;
// }

//stack with dynamic allocation//

typedef struct element{
    int key;//stack value
};

element *stack_dynamic=(element*)malloc(sizeof(element));
int cap=1;
int top=-1;

void stackfull(){
    stack_dynamic=(element*)realloc(stack_dynamic,2*cap*sizeof(element));//if stack is full reallocate 2 times original space
    cap*=2;
}

void push (int value){
    if(top<cap-1){
        top++;
        stack_dynamic[top].key=value;
    }
    else{
        stackfull();//if stack exceed then reallocate space ,and re-push data
        push(value);
    }
}

element pop(){
    element temp;
    if(top<0){
        printf("stack is empty");
    }
    else {
        temp=stack_dynamic[top];
        top--;
        return temp;
    }
}



int main(void)
{   for(int i=0;i<10;i++){
    push(i);}
    for(int i=0;i<10;i++){
        printf("|%d|\n",pop().key);
    }
    printf("--\n");
    free(stack_dynamic);
    system("pause");
    return 0;
}

