#include <stdio.h>
#include <stdlib.h>

// struct aaa{
//     int  age;
//     int salary;
// }arr={1,2};//除了直接宣告也能在sturct後面宣告

// typedef const char* string;//const 使string變唯獨

// typedef struct account{
//     string name;
//     string id;
//     int age;
//     int salary;
// };

// void print(account i){
//     printf("account:%s,%s,%d,%d\n",i.name,i.id,i.age,i.salary);
// }


// int main (void)
// {
// struct aaa arr1;//沒有使用typedef 就必須多打struct
// account jam[]={
//     {"jasom","112233",15,20},{"sad","55222",41,78}
// };
// arr.age=10;
// arr.salary=18;

// print(jam[0]);
// print(jam[1]);

// system("pause");
// return 0;
// }



//struct with pointer//
// typedef const char* string;
// typedef struct  account
// {   string name;
//     string id;
//     int value;    
// };



// void withdraw(account* a,int ammount){
//     if(a->value<ammount){
//         puts("account no sufficient money");
//         return;
//     }
//     else
//     a->value-=ammount;
// }

// void deposit(account* a,int ammount){
//     if(ammount<0){
//         puts("不能存入負數");
//         return;
//     }
//     else
//     a->value+=ammount;//如果進來的是指標可以用->，其餘只能用
// }

// int main (void)
// {account newone={"james","11-55-44",200};
// account *ptr=&newone;
// withdraw(&newone,100);
// deposit(&newone,-200);
// printf("account information:%s,%s,%d\n",ptr->name,ptr->id,ptr->value);
// system("pause");
// return 0;
// }


//struct with object-oriented// 

typedef const char* string;
typedef struct  account
{   string name;
    string id;
    int value;
    void (*withdraw)(struct account*,int);//將函式包在struct裡面,類似OO的概念
    void (*deposit)(struct account*,int); //將函式包在struct裡面,類似OO的概念   
};



void withdraw(account *a,int ammount){
    if(a->value<ammount){
        puts("account no sufficient money");
        return;
    }
    else
    a->value-=ammount;
}

void deposit(account *a,int ammount){
    if(ammount<0){
        puts("不能存入負數");
        return;
    }
    else
    a->value+=ammount;
}

account* newaccount(string names,string idnetity,int ammount){
    account *ptr=(account*)malloc(sizeof(account));
    ptr->name=names;
    ptr->id=idnetity;
    ptr->value=ammount;
    ptr->deposit=deposit;//把函示指標傳給ptr
    ptr->withdraw=withdraw;//同上
    return ptr;
}

int main (void)
{
account *ptr=newaccount("james","11-44-55",600);
ptr->deposit(ptr,200);
printf("account information:%s,%s,%d\n",ptr->name,ptr->id,ptr->value);
free(ptr);
system("pause");
return 0;
}

