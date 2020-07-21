//改写代码清单6-16的程序，将两次考试的分数存储在三维数组中。

/*
求4名学生在两次考试中3门课程的总分并显示（函数）
*/
#include <stdio.h>

/*--- 将4行3列矩阵a和b的和存储在c中 ---*/
void mat_add(const int a[4][3], const int b[4][3], int c[2][4][3])
{
    int x, y, z;

    for (x = 0; x < 2; x++)
        for (y = 0; y < 4; y++)
            for (z = 0; z < 3; z++) {
                c[x][y][z] = a[y][z] + b[y][z];
            }
}

/*--- 显示4行3列矩阵m ---*/
void mat_print(const int m[4][3])
{
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++)
            printf("%4d", m[i][j]);
        putchar('\n');
    }
}

//显示三维数组
void  triple_print(const int n[2][4][3])
{
    int e,f,g;

    for ( e = 0; e < 2; e++){
        for( f = 0; f< 4; f++)
            for(g = 0; g < 3; g++)
                printf("%4d",n[e][f][g]);
            putchar('\n');
    }
}

int main(void)
{
    int tensu1[4][3] = { {91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34} };
    int tensu2[4][3] = { {97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35} };
    int sum[2][4][3];            /* 总分 */

    mat_add(tensu1, tensu2, sum);                /* 求两次考试中成绩的总和 */

    puts("第一次考试的分数");  mat_print(tensu1);    /* 显示第一次考试的分数 */
    puts("第二次考试的分数");  mat_print(tensu2);    /* 显示第二次考试的分数 */
    puts("总分");        triple_print(sum);        /* 显示总分 */

    return 0;
}
