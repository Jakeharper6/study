/*编写一段程序，输入三个整数，如果三个数都相等，则显示“三个值都相等”。
如果其中任意两个值相等，则显示“有两个值相等”。
如果上述两种情况都不满足，则显示“三个值各不相同”。*/
#include<stdio.h>

int main(void){
    int a, b, c;

    printf("请输入3个数：\n");
    printf("第一个数：");
    scanf("%d",&a);
    printf("第二个数：");
    scanf("%d",&b);
    printf("第三个数：");
    scanf("%d",&c);

    if (a == b || a == c)
    {
        if (b == c)
        {
            printf("三个值都相等");
        }
        else
        {
            printf("有两个值都相等");
        }
        
    }
    else if (b == c)
    {
        printf("有两个值都相等");
    }
    else
    {
        printf("三个值各不相同");
    }
    
    return 0;
}