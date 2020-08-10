//不使用下标运算符，编写如下函数，返回字符串s中字符c的个数(若不存在,则为0)。
#include<stdio.h>
#include<string.h>

int str_chnum(const char *s, char c){
    int n = 0;
    while (*s != 0)
    {
        if (*s == c)
        {
            n++;
        }
        s++;
    }
    return n;
}

int main(void){
    char *s = "1c343c3541asdcsxvcadq";

    printf("%d",str_chnum(s,'c'));
}