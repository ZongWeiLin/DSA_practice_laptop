#include<stdlib.h>
#include<stdio.h>

int main(){
    // int *i;
    //1-d array for malloc//
    // int size;
    // size=0;
    // printf("scanf size:");
    // scanf("%d",&size);

    // i=(int*)malloc(size*sizeof(int));
    
    // printf("輸入字元\n");

    // for(int j=0 ;j<size; j++){
    //     printf("i[%d]=",j);
    //     scanf("%d",i+j);
    // }

    // printf("輸出結果\n");

    // for(int j=0;j<size;j++){
    //     printf("i[%d]=%d\n",j,*(i+j));
    // }


    //2-d array for malloc//
    // int **arr;
    // arr=(int**)calloc(2,sizeof(int*));
    // for(int j=0;j<2;j++){
    //     arr[j]=(int*)calloc(3,sizeof(int));
    // }
    // for(int j=0;j<2;j++){
    //     for(int k=0;k<3;k++)printf("a[%d][%d]=%d\n",j,k,arr[j][k]);
    //     printf("\n");
    // }
    // for(int j=0;j<2;j++)free(arr[j]);
    // free(arr);


    //re-alloca test//
    int *arr;
    arr=(int*)calloc(2,sizeof(int));
    for(int j=0;j<2;j++)printf("a[%d]=%d\n",j,*(arr+j));
    int *arr1;
    arr1=(int*)realloc(arr,sizeof(int)*4);//re-allocate 4 int size arr
    for(int j=0;j<4;j++)printf("a[%d]=%d\n",j,*(arr+j));
    printf("arr位置:%p\n",arr);
    printf("arr1位置:%p\n",arr1);

    free(arr1);

    // i=(int*)malloc(sizeof(int));
    // i=(int*)malloc(1000*sizeof(int));//use malloc to require 1000 int spaces
    // i=(int*)calloc(1,sizeof(int));//use calloc to reset the value=0 ,and require 1 space
    // i=(int*)calloc(1000,sizeof(int));//require 1000 int space,and reset memory vaule=0
    // printf("%d\n",*i);
    // free(i);
    system("pause");
    return 0;
}