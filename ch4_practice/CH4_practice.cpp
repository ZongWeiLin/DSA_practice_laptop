#include <stdio.h>
#include <stdlib.h>

//link list第一種定義方式//
typedef struct list *listnode;//先type define指標和list
struct list//因為前面已淨typedefine了,所以不用在typedefine一次
{   int value;
    listnode link;
};

//第二種方式//
typedef struct Link_list
{   int value;
    Link_list *node;
};

Link_list* create (int value){
    Link_list *ptr;
    ptr=(Link_list*)malloc(sizeof(Link_list));
    ptr->value=value;
    ptr->node=NULL;
    return ptr;
}

void series (Link_list *last,int value){
    Link_list *ptr=create(value);
    last->node=ptr;//let last bloack point to current
}

void insert(Link_list *previos,int value){
    Link_list *ptr=create(value);
    if(previos!=0){
    ptr->node=previos->node;//讓要insert的block指到,前一個block指的點 
    previos->node=ptr;//把前一個block指的點,改成指向要insert的block
    }
    else{
        ptr->node=NULL;
        previos=ptr;
    }
}

Link_list* deletes(Link_list *first,int value){
    Link_list *current,*previous,*ptr;
    current=first;
    previous=0;
    while (current!=0&&current->value!=value)//traverse 整個link-list
    { previous=current;
      current=current->node;       
    }
    if (current==0){
    printf("no element\n");//traversal完沒找到
    return first;
    }
    else if(current==first){//case 1
    first=current->node;//要刪除node的在第一個,直接把first往後移一格
    free(current);
    return first;//要return first回去,不然main的first與刪掉node之後的first不同
    }
    else{//case 2
    previous->node=current->node;//要刪的在中間,把前一個的pointer,指向current指的下一個
    free(current);
    return first;
    } 
    }

void printlist (Link_list *first){
    for(;first!=NULL;first=first->node){
        printf("%4d",first->value);
    }
    printf("\n");
}



int main(void)
{   Link_list *first,*ptr;
    first=create(10);
    series(first,20);
    insert(first,86);
    insert(first,45);
    for (ptr=first;ptr!=NULL;ptr=ptr->node)
    {
     printf("%d\n",ptr->value) ;  
    }

    first=deletes(first,20);

    for (ptr=first;ptr!=NULL;ptr=ptr->node)
    {
     printf("%d\n",ptr->value) ;  
    }

    printlist(first);

    free(first);
    system("pause");
    return 0;
}