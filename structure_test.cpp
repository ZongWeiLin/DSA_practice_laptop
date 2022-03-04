#include <stdio.h>
#include <stdlib.h>

// struct aaa{
//     int  age;
//     int salary;
// }arr={1,2};//���F�����ŧi�]��bsturct�᭱�ŧi

// typedef const char* string;//const ��string�ܰ߿W

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
// struct aaa arr1;//�S���ϥ�typedef �N�����h��struct
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
//         puts("����s�J�t��");
//         return;
//     }
//     else
//     a->value+=ammount;//�p�G�i�Ӫ��O���Хi�H��->�A��l�u���
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
    void (*withdraw)(struct account*,int);//�N�禡�]�bstruct�̭�,����OO������
    void (*deposit)(struct account*,int); //�N�禡�]�bstruct�̭�,����OO������   
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
        puts("����s�J�t��");
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
    ptr->deposit=deposit;//���ܫ��жǵ�ptr
    ptr->withdraw=withdraw;//�P�W
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

