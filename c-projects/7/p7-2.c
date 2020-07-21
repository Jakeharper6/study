#include <stdio.h>
#include<math.h>
int main() {
    unsigned int number;
    int x;
    int i;
    int number1;
    
    printf("请输入初始值:" );
    scanf("%d", &number);
    number1 = number;
    printf("左移多少位:");
    scanf("%d", &x);
    number <<= x;
    printf("左移后的值:%d",number);
    putchar('\n');
    for (i = 0; i < x; i++) {
        number1 *= 2;
    }
    printf("乘以2的指数幂的值:%d", number1);

}