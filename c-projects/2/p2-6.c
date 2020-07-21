/*编写一段程序，读取表示身高的整数，显示出标准体重的实数值。
标准体重根据公式(身高-100)X0.9进行计算，所得结果保留一位小数。
请输入您的身高：175
您的标准体重是67.5*/

#include <stdio.h>

int main(void)
{
    int heaght;

    printf("请输入您的身高："); scanf("%d", &heaght);
    printf("您的标准体重是%.1f\n",(double)(heaght - 100) * 0.9);

    return 0;
}