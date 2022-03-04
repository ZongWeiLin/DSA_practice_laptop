#include <stdio.h>
#include <stdlib.h>
typedef struct link_list
{   int value;
    link_list *next;
};

link_list* create (int value){
    link_list *ptr;
    if(value!=NULL){
        ptr=(link_list*)malloc(sizeof(link_list));//先要空間
        ptr->value=value;
        ptr->next=NULL;//把next指到null
        return ptr;
    }
}

void series (int value,link_list *last){
    link_list *ptr=create(value);//串起來之前先建一個link list
    last->next=ptr;//把前一個的pointer指到要串的link list
}

int main(void)
{   link_list *ptr,*first;
    first=create(10);
    ptr=first;//設初始位置為link_list第一個
    
    //用for loop串 link-list
    for(int i=1;i<5;i++,ptr=ptr->next){
        series(i,ptr);//每次串完要把指標往後移一格
    }
    //把link-list東西印出來
    for(ptr=first;ptr!=NULL;ptr=ptr->next){//指標指到NULL時，代表已經到底
        printf("%d->",ptr->value);
    }

    printf("\n");
    free(first);
    system("pause");
    return 0;
}