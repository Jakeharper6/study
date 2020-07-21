//改写代码清单5-13的程序，将两次考试的分数存储在三维数组tensu中。

#include <stdio.h>

int main(void)
{
    int x, y, z;
    int tensu[2][4][3] = { { {91, 63, 78}, {67, 72, 46},{89, 34, 53}, {32, 54, 34} } ,{ {97, 67, 82}, { 73, 43, 46 }, { 97, 56, 21 }, { 85, 46, 35 } } };


    for (x = 0; x < 2; x++) {
        for (y = 0; y < 4; y++) {
            for (z = 0; z < 3; z++) {
                printf("%4d", tensu[x][y][z]);
            
            }
            putchar('\n');
        }
    }    
    return 0;


}