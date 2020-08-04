//编写一段程序，读取两个整数的值，然后计算出它们之间所有整数的和。

#include<stdio.h>

int main(){
    
    int a,b;
    int x = 0;

    puts("请输入两个整数");
    printf("整数A:");scanf("%d",&a);
    printf("整数B:");scanf("%d",&b);
    do{
       x += a ;
       a ++;
    }while(a <= b );

    printf("它们之间所有整数的和为%d",x);

    return 0;
}