/*编写一段程序，输入一个整数值，显示该整数值以下的所有奇数。
整数值:15
1 3 5 7 9 11 13 15
*/

#include<stdio.h>

int main(void){

    int no,i;

    printf("输入一个正整数:");
    scanf("%d",&no);

    printf("整数值:%d\n",no);

    for (i = 1; i <= no; i += 2)
    {
        printf("%d ",i);
    }
    

    return 0;
}