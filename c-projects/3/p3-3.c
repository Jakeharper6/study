//编写一段程序，输入一个整数值，显示出它的绝对值。

#include<stdio.h>

int main(void){

    int a;

    puts("请输入一个整数");
    
    printf("整数A:");scanf("%d",&a);
    
    if (a >= 0)
       printf("其绝对值为%d\n",a);
    else
       printf("其绝对值为%d\n",0 -a);

    return 0;
}