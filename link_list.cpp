#include <stdio.h>
#include <stdlib.h>
typedef struct link_list
{   int value;
    link_list *next;
};

link_list* create (int value){
    link_list *ptr;
    if(value!=NULL){
        ptr=(link_list*)malloc(sizeof(link_list));//���n�Ŷ�
        ptr->value=value;
        ptr->next=NULL;//��next����null
        return ptr;
    }
}

void series (int value,link_list *last){
    link_list *ptr=create(value);//��_�Ӥ��e���ؤ@��link list
    last->next=ptr;//��e�@�Ӫ�pointer����n�ꪺlink list
}

int main(void)
{   link_list *ptr,*first;
    first=create(10);
    ptr=first;//�]��l��m��link_list�Ĥ@��
    
    //��for loop�� link-list
    for(int i=1;i<5;i++,ptr=ptr->next){
        series(i,ptr);//�C���꧹�n����Щ��Ჾ�@��
    }
    //��link-list�F��L�X��
    for(ptr=first;ptr!=NULL;ptr=ptr->next){//���Ы���NULL�ɡA�N��w�g�쩳
        printf("%d->",ptr->value);
    }

    printf("\n");
    free(first);
    system("pause");
    return 0;
}