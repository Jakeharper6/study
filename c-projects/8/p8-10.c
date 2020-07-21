/*改写代码清单8-10的程序，将数字字符的出现次数用并排的*表示。
注意和代码清单5-12以及练习5-9的显示一样。*/


#include <stdio.h>

int main(void)
{
    int i, ch,j;
    int cnt[10] = { 0 };

    while ((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '9')
            cnt[ch - '0']++;

    }
    puts("数字字符的出现次数");
    for (i = 0; i < 10; i++) {
        printf("'%d':", i);
        for (j = 0; j < cnt[i]; j++) {
            putchar('*');
            
        }putchar('\n');
    }
    return 0;
}