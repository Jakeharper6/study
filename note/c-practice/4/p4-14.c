/*编写一段程序，根据输入的整数，循环显示1234567890，显示的位数和输入的整数值相同。
123456789012345678901234*/

#include <stdio.h>

int main(void)
{
    int no;
    int i;
    printf("请输入一个整数:");
    scanf("%d", &no);
    for (i = 1; i <=no; i++) {
        printf("%d",i%10);

    }
    
}