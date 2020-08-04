/*
递增显示从1到输入的正整数为止的各个整数
从1开始递增。
输入的值小于0的时候不换行。
*/
#include <stdio.h>

int main(void)
{
    int i, no;

    printf("请输入一个正整数：");
    scanf("%d", &no);

    i = 1;
    if(i <= no){
        while (i <= no){
        printf("%d ", i++);
    }
    }
    
    else printf("不在取值范围内");
    

    return 0;
}