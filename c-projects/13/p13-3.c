/*
    读入身高和体重，计算并显示它们的平均值
*/

#include <stdio.h>

typedef struct {
    char  name[100];    /* 姓名 */
    double  height;            /* 身高 */
    double weight;            /* 体重 */
} Student;
void swap_Student(Student* x, Student* y)
{
    Student temp = *x;
    *x = *y;
    *y = temp;
}
void sort_by_height(Student a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--)
            if (a[j - 1].height > a[j].height)
                swap_Student(&a[j - 1], &a[j]);
    }
}


int main(void)
{
    FILE* fp;
    int    ninzu = 0;            /* 人数 */
    char   name[100];            /* 姓名 */
    double height, weight;        /* 身高，体重 */
    double hsum = 0;            /* 身高合计 */
    double wsum = 0;            /* 体重合计 */
    int i = 0;
    Student stu[] = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
    };
    if ((fp = fopen("hw.dat", "r")) == NULL)                /* 打开文件 */
        printf("\a文件打开失败。\n");
    else {
        while (fscanf(fp, "%s%lf%lf", stu[i].name, &stu[i].height, &stu[i].weight) == 3) {
            
            hsum +=stu[ninzu].height;
            wsum +=stu[ninzu].weight;
            i++;
            ninzu++;
        };
        
        sort_by_height(stu, i);
        for (i = 0; i < ninzu; i++) {
            
            printf("%-10s %5.1f %5.1f\n",stu[i].name,stu[i].height, stu[i].weight);
        }
        
        printf("----------------------\n");
        printf("平均       %5.1f %5.1f\n", hsum / ninzu, wsum / ninzu);
        fclose(fp);                                            /* 关闭文件 */
    }

    return 0;
}