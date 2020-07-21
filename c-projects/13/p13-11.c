#include <stdio.h>

int main(void)
{
    FILE* fp;
    double v[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("v[%d]=", i);
        scanf("%lf", &v[i]);
    }

    /* 写入操作 */
    if ((fp = fopen("PI.bin", "wb")) == NULL)        /* 打开文件 */
        printf("\a文件打开失败。\n");
    else {
        fwrite(&v, sizeof(double), 10, fp);            
        fclose(fp);
    }                                                /* 关闭文件 */

    /* 读取操作 */
    if ((fp = fopen("PI.bin", "rb")) == NULL)        /* 打开文件 */
        printf("\a文件打开失败。\n");
    else {
        fread(&v, sizeof(double), 10, fp);
        for (i = 0; i < 10; i++) {
            printf("v[%d]=%.2f\n", i,v[i]);
        }


        fclose(fp);                                    /* 关闭文件 */
    }

    return 0;
}