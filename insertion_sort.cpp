#include <stdio.h>
#include <stdlib.h>
#define Swap(x,y,t)((t)=(x),(x)=(y),(y)=(t))


//for loop solution//
int main(void)
{
    
    int arr[5]={1,5,13,7,1};
    int index,temp;
    for(int i=0;i<5;i++){
        for(int j=i;j<5;j++){
            if(j==i)index=i;//��l�̤p��������
            if(arr[i]>arr[j])index=j;//�����l�p��,�N��index��s
        }
        Swap(arr[i],arr[index],temp);//��̤p�ȸ�̥��䪺����
    }

    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
        printf(" ");
    }


    system("pause");
    return 0;
}