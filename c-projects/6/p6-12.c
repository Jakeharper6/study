/*创建一个函数，将4行3列矩阵a和3行4列矩阵b的乘积，存储在3行3列矩阵c中。
void mat_mul(const int a[4][3],const int b[3][4],int c[3][3])*/

#include <stdio.h>

void mat_mul(const int a[4][3], const int b[3][4], int c[3][3])
{
    int i, j, k;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int a[4][3];
    int b[3][4];
    int i, j, k, x, y, c[3][3];
    printf("输入4*3 个数 以空格隔开：\n");
    for (i = 0; i < 4; i++)
        for (k = 0; k < 3; k++)
            scanf("%d", &a[i][k]);
    printf("输入3*4 个数 以空格隔开：\n");
    for (i = 0; i < 3; i++)
        for (k = 0; k < 4; k++)
            scanf("%d", &b[i][k]);

    mat_mul(a, b, c);

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
            printf("%d\t", c[x][y]);
        printf("\n");
    }
    return 0;
}