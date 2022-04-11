#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{
    int value;
    link_list *node;
};

link_list* create_link_list(int value){
    link_list *ptr;
    ptr=(link_list*)malloc(sizeof(link_list));
    ptr->value=value;
    ptr->node=NULL;
    return ptr;
}



int main(void)
{

    system("pause");
    return 0;
}