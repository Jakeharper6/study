//创建一个函数，连续发10次响铃。void alert(int n) { /* ... ★/ }

#include <stdio.h>

void alert(int n) {
    while (n-- > 0)
    {
        putchar('\a');
    }
}

int main() {
    int x;
    printf("请输入要发出响铃的次数:");
    scanf("%d", &x);
    alert (x);
}