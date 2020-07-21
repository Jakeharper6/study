//使用代码清单6-3中的sgr函数创建另一个函数，返回int型整数的四次幂。int pow4(int x){/*...*/}

#include <stdio.h>

int pow4(int x)
{
    return x * x * x * x;
}


int main(void)
{
    int no;

    puts("请输入一个整数。");
    printf("整数x:"); scanf("%d", &no);

    printf("x的四次幂是%d。\n", pow4(no));

    return 0;
}
