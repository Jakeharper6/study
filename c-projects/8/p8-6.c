#include<stdio.h>

int main(void)
{
    int i, num;
    int sum = 1;

    printf("请输入一个整数: ");
    scanf("%d", &num);
    if (num > 0)
    {
        for (i = 1; i <= num; i++)
        {
            sum *= i;
        }
    }
    printf("%d的阶乘为%d。\n", num, sum);

    return 0;
}

