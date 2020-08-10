/*不使用下标运算符，编写如下函数，若字符串S中含有字符C(若含有多个，以先出现的为准)，
则返回指向该字符的指针，否则返回空指针。
char *strchr(const char *s, int c)*/
#include<stdio.h>
#define Number 5 

char *str_chr(char *s, char c){
    char *p;
    while (*s != 0)
    {   
        if (*s == c)
        {
            p = s;
            return p;
        }    
        s++;
    }
    return 0;
}

int main(void){
    char s[Number];
    scanf("%s",s);
    char c = 'c';
    
    printf("%s",str_chr(s,c));
}