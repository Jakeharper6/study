/*
    读入身高和体重，计算并显示它们的平均值
*/

#include <stdio.h>
#define ninzu 4


typedef struct {
    char  name[100];    /* 姓名 */
    int   height;     /* 身高 */
    int   weight;       /* 体重 */
} Student;
int main(void)
{

    FILE* fp;
    if ((fp = fopen("gaoji", "w")) == NULL)                /* 打开文件 */
        printf("\a文件打开失败。\n");
    else {
        int i;
        Student stu[] = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
        };
        puts("输入姓名，身高，体重");
        for (i = 0; i < ninzu; i++) {
            scanf("%s%d%d", stu[i].name, &stu[i].height, &stu[i].weight);
            fprintf(fp, "%s %d %d\n", stu[i].name, stu[i].height, stu[i].weight);
        }
        fclose(fp);
    }
        return 0;
    
}