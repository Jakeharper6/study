/*编写如下函数，删除字符串str内的所有数字字符。
void del_digit(char *str)
例如，如果接收"AB1C9",就返回"ABC"。注意不要使用下标运算符。*/

#include<stdio.h>
#define Number 5

void del_digit(char *str){
    char *p = str;
    while (*str != 0)
    {   
        if ((*p >= '0') && (*p <= '9'))
        {
            p++;
        }
        else
        {
            *str = *p;
            p++;
            str++;
        }
    }
    *str = 0;
}

int main(void){
    char s[Number];
    scanf("%s",s);

    del_digit(s);

    printf("%s",s);

    return 0;
}