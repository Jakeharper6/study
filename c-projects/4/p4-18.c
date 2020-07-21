/*编写一段程序，输入一个整数值，显示该整数个'*'。每显示5个就进行换行。
显示多少个*:12
*****
*****
**
*/

#include <stdio.h>

int main(){

    int n;
    printf("输入一个正整数： ");scanf("%d",&n);

    int a=n/5;
    int b=n%5;
    while (a-- > 0)
    {
        printf("*****\n");
    }

    for (int i = 1; i <= b; i++)
        {
            putchar('*');
        }

    printf("\n");

    return 0;

}