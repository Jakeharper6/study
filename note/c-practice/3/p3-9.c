//编写一段程序，计算出输入的三个整数中的最小值并显示。

#include <stdio.h>

int main(void)
{
    int a, b, c;

    puts("请输入三个整数：");
    printf("整数1："); scanf("%d", &a);
    printf("整数2："); scanf("%d", &b);
    printf("整数3："); scanf("%d", &c);

    int min1, min2;
     min1 = (a < b) ? a : b;
     min2 = (c < b) ? c: b;
     printf("最小值是:%d", (min1 < min2) ? min1 : min2);

    return 0;
}