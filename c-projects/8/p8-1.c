//请定义一个函数式宏diff(x,y)，返回x、y二值之差。

#include<stdio.h>

#define diff(x,y) ((x)-(y))

int main(void)
{
    int a, b;

    printf("请输入两个数:\n");
    printf("1:");scanf("%d",&a);
    printf("2:");scanf("%d",&b);

    printf("两数之差为:%d",diff(a,b));

    return 0;
}