//创建一个程序，计算标准输入中出现的行数。

#include<stdio.h>

int main()
{
    int ch, i;

    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')    
            i++;
    }
    
     printf("%d", i);
}