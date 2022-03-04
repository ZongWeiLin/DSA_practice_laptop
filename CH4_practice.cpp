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
    printf("no element");//traversal���S���
    return first;
    }
    else if(current==first){//case 1
    first=current->node;//�n�R��node���b�Ĥ@��,������first���Ჾ�@��
    free(current);
    return first;//�nreturn first�^�h,���Mmain��first�P�R��node���᪺first���P
    }
    else{//case 2
    previous->node=current->node;//�n�R���b����,��e�@�Ӫ�pointer,���Vcurrent�����U�@��
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