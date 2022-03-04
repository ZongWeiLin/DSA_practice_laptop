#include <stdio.h>
#include <stdlib.h>

//把2維陣列傳至function//

//method1//

// void print (int **v,int length, int width){
//     for(int i=0;i<length;i++){
//         for(int j=0;j<width;j++)
//         printf("%d",v[i][j]);
//     printf("\n");
//     }

// }



// int main(void)
// {
//     int arr[2][3]={{1,2,3},{1,2,3}};
//     int *ptr[2]={arr[0],arr[1]};//transfer pointer of arr[0] and arr[1]
//     print(ptr,2,3);

//     system("pause");
//     return 0;
// }

//method2//

// void print (int *v,int length, int width){
//     for(int i=0;i<length;i++){
//         for(int j=0;j<width;j++)
//         printf("%d",*(v+width*i+j));
//     printf("\n");
//     }

// }



// int main(void)
// {
//     int arr[2][3]={{1,2,3},{1,2,3}};
//     print((int*)arr,2,3);

//     system("pause");
//     return 0;
// }

//用function dynamic開2d-array//
int** make2dArray(int column,int rows)
{
    int **x,i;
    x=(int**)calloc(column,sizeof(int*));
    for(i=0;i<column;i++)x[i]=(int*)calloc(rows,sizeof(int));
    return x;//回傳column的指標
}


int main(){
    int **arr;
    arr=make2dArray(2,3);
    for(int i=0;i<2;i++){
        for (int j = 0; j < 3; j++)
        {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;

}