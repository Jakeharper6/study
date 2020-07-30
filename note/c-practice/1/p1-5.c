//编写一段程序，像下面那样读取一个整数并显示该整数加上12之后的结果。

#include <stdio.h>

int main(void){
    
    int no;

    printf("输入一个整数:");
    scanf("%d",&no);

    printf("整数加上12的结果是%d",no + 12);

    return 0;
}