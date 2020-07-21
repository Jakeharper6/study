#include <stdio.h>
// 显示unsigned类型的值最大值，同时验证最大值+1是0.
int main() {
    unsigned a = 0;
    while (++a > 0);
        printf("%u", a - 1);
        putchar('\n');
        printf("%u", a);
}