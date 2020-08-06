/*写如下函数，若字符串s中含有字符c(若含有多个，以先出现的为准)，
则返回该元素的下标值，否则返回-1。
int str_char(const char s[],int c)*/

#include<stdio.h>

#define Number 5

int str_char(char s[])
{
    int i;

    for (int i = 0; i < Number; i++)
    {
        if (s[i] == 'c')
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    char a[Number];

    printf("请输入一串字符:\n");
    scanf("%s",a);

    printf("%d",str_char(a));

    return 0;
}