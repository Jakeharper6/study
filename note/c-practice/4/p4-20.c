//编写一段程序，为九九乘法表增加横纵标题
#include <stdio.h>

int main(void)
{
    int i, j;
    printf(" |");
    for (i = 1; i < 10; i++) {
        printf("%3d", i);
    }
    putchar('\n');
    for (i = 1; i < 30; i++) {
        putchar('-');
    }
    putchar('\n');


    for (i = 1; i <= 9; i++) {
        printf("%d|", i);
        for (j = 1; j <= 9; j++)
            printf("%3d", i * j);
        putchar('\n');


    }
}