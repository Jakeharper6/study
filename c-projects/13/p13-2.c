/*
    打开文件。
*/

#include <stdio.h>

int main(void)
{
    char s[128];
    FILE* fp;
    printf("请输入你要打开的文件:");
    scanf("%s", s);
    fp = fopen("*s", "w");                        /* 打开文件 */
    return 0;
}