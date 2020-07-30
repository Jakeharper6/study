/*如果在int型变量的声明中为变量赋一个实数值的初始值(如3.14或5.7等)会怎样呢?
请试着生成程序并确认。*/

#include <stdio.h>

int main(void) 
{
    int vx = 3.14;
    int vy = vx + 5.7;

    printf("vx的值是%d。\n", vx);
    printf("vy的值是%d。\n", vy);

    return 0;
}

//int整数