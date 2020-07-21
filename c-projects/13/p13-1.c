/*
    打开与关闭文件
*/

#include <stdio.h>

int main(void)
{
    char s[128];
    FILE* fp;
    printf("请输入你要打开的文件");
    scanf("%s", s);
    fp = fopen("*s", "r");                        /* 打开文件 */

    if (fp == NULL)
        printf("该文件不存在\n");
    else {
        printf("该文件存在\n");
        fclose(fp);                                /* 关闭文件 */
    }

    return 0;
}