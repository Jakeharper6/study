/*如何让下述初始化賦值得到的字符串s变成空字符串?请编写程序实现。
char s[]="ABC";*/

#include <stdio.h>

int main(void)
{
    char s[] = "\0ABC";

    printf("字符串str为\"%s\"。\n", s);

    return 0;
}