/*编写一段程序输入两个整数，如果它们的差值小于等于10,
则显示“它们的差小于等于10”。否则，显示“它们的差大于等于11”。
请使用逻辑或运算符。*/
#include<stdio.h>

int main(void){
    int a, b;
    int dis;

    printf("请输入2个整数：\n");

    printf("第一个数：");
    scanf("%d",&a);
    printf("第二个数：");
    scanf("%d",&b);

    dis = a - b;

    if (dis < -10 || dis > 10)
    {
        printf("它们的差大于等于11");
    }else
    {
        printf("它们的差小于等于10");
    }
    
    return 0;
}