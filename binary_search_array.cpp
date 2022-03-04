#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *a,int searchnum,int left,int right)
{if(left<=right){
    int middle=(left+right)/2;
    if(searchnum==a[middle])return middle;
    if(searchnum>a[middle])return binarysearch(a,searchnum,middle+1,right);//value>middle,search right side
    else if(searchnum<a[middle])return binarysearch(a,searchnum,left,middle-1);//value<middle,search left side
 }       
return -1;
}


int main(void)
{   int arr[]={1,3,5,7,9};
    int index;
    
    printf("\n");
    index=binarysearch(&arr[0],7,0,4);
    printf("%d\n",index);

    system("pause");
    return 0;
}