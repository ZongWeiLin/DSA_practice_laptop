#include <stdio.h>
#include <stdlib.h>


//嵌入式系統面試第12個//
int main(void)
{   unsigned int a=6;
    int b=-20;
    if(a+b>6)//因為b被強制轉型成unsigned int,因為-數的字首為1xb,所以才會變很大的數字
    printf("a>6\n");
    else
    printf("a<6\n");    
    system("pause");
    return 0;
}