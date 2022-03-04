#include <stdio.h>
#include <stdlib.h>

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

void insert(Link_list *last,int value){
    Link_list *ptr=create(value);
    ptr->node=last->node;//let insert block point to last block point 
    last->node=ptr;//let last block point to current block
}

Link_list* deletes(Link_list *first,int value){
    Link_list *current,*previous,*ptr;
    current=first;
    previous=0;
    while (current!=0&&current->value!=value)
    { previous=current;
      current=current->node;       
    }
    if (current==0){
    printf("no element");//traversal完沒找到
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

    first=deletes(first,86);

    for (ptr=first;ptr!=NULL;ptr=ptr->node)
    {
     printf("%d\n",ptr->value) ;  
    }
    


    free(first);
    system("pause");
    return 0;
}