//编写一段程序，像下面那样读取一个整数并显示该整数减去6之后的结果。

#include <stdio.h>

int main(void){
    
    int no;

    printf("输入一个整数:");
    scanf("%d",&no);

    printf("整数减去6的结果是%d",no - 6);

    return 0;
}