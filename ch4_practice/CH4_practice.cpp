#include <stdio.h>
#include <stdlib.h>

//link list�Ĥ@�ةw�q�覡//
typedef struct list *listnode;//��type define���ЩMlist
struct list//�]���e���w�btypedefine�F,�ҥH���Φbtypedefine�@��
{   int value;
    listnode link;
};

//�ĤG�ؤ覡//
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
    ptr->node=previos->node;//���ninsert��block����,�e�@��block�����I 
    previos->node=ptr;//��e�@��block�����I,�令���V�ninsert��block
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
    while (current!=0&&current->value!=value)//traverse ���link-list
    { previous=current;
      current=current->node;       
    }
    if (current==0){
    printf("no element\n");//traversal���S���
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