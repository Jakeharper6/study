/*编写如下函数，返回字符串s中字符c的个数(没有则返回0)。
int str_chnum(const char s[],int c)*/

#include<stdio.h>

#define Number 5

int str_char(char s[])
{
    int i;
    int x = 0;

    for (i = 0; i < Number; i++)
    {
        if (s[i] == 'c')
            x ++;
    }

    return x;
}

int main(void)
{
    char a[Number];

    printf("请输入一串字符:\n");
    scanf("%s",a);

    printf("有%d个c",str_char(a));

    return 0;
}