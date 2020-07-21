/*现定义如下函数式宏，其功能为返回x、y中的较大值。
#define max(x,y) (((x)>(y))?(x):(y))
而下面两个使用了该宏的表达式的功能为计算a、b、c、d中的最大值。
max(max(a, b), max(c, d))
max(max(max(a, b), c), d)
请显示并观察它们是如何展开的。*/

#include<stdio.h>

#define max(x,y) (((x)>(y))?(x):(y))

int main(void)
{
    int a,b,c,d;

    printf("请输入四个数:\n");
    printf("1:");scanf("%d",&a);
    printf("2:");scanf("%d",&b);
    printf("3:");scanf("%d",&c);
    printf("4:");scanf("%d",&d);


    printf("最大值是:%d",max(max(a, b), max(c, d)));
    putchar('\n');
    printf("最大值是%d", max(max(max(a, b), c), d));


    return 0;
}