/*
    显示文件内容
*/

#include <stdio.h>

int main(void)
{
    int  ch;
    int cnt = 0;
    FILE* fp;
    char fname[FILENAME_MAX];        /* 文件名 */

    printf("文件名：");
    scanf("%s", fname);

    if ((fp = fopen(fname, "r")) == NULL)                    /* 打开文件 */
        printf("\a文件打开失败。\n");
    else {
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
            if (ch >' ') {
                cnt++;
        }    
        }
        printf("字符数：%d", cnt);
        fclose(fp);                                            /* 关闭文件 */
    }

    return 0;
}