//使用if语句替换代码清单3-15程序中的条件运算符，实现同样的功能。
/*
显示输入的两个整数的差并显示（条件运算符）
*/
#include <stdio.h>

int main(void)
{
    int n1, n2,x;

    puts("请输入两个整数：");
    printf("整数1："); scanf("%d", &n1);
    printf("整数2："); scanf("%d", &n2);

    x = n1 - n2;

    if(x >= 0)
       printf("它们的差是%d",x);
    else
       printf("它们的差是%d",-x);

    return 0;
}