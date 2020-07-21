//编写一段程序，读取两个整数，然后输出它们的和以及积。

#include<stdio.h>

int main(void){

    int a,b;

    puts("输入两个整数");

    printf("整数1:");scanf("%d",&a);
    printf("整数2:");scanf("%d",&b);

    printf("它们的和是%d\n它们的积是%d\n",a+b,a*b);

    return 0;
}