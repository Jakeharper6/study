//编写一段程序，为double型数组的所有元素分配静态存储期，并确认它们都被初始化为0.0

#include <stdio.h>
#define number 3


int main() 
{
    int i;
    static double x[number];
    for (i = 0; i < number; i++) 
    {
        printf("v[%d]=%.1f", i, x[i]);
        putchar('\n');
    }
}