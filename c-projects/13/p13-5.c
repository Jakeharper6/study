/*
    显示程序上一次运行时的日期和时间
*/

#include <time.h>
#include <stdio.h>

char data_file[] = "datetime.dat";                /* 文件名 */

/*--- 取得并显示上一次运行时的日期和时间 ---*/
void get_data(void)
{
    FILE* fp;
    
    if ((fp = fopen(data_file, "r")) == NULL)                /* 打开文件 */
    {printf("本程序第一次运行。\n");

}
    else {
        int year, month, day, h, m, s;
        char mood[120];

        fscanf(fp, "%d%d%d%d%d%d%s", &year, &month, &day, &h, &m, &s,mood);
        printf("上一次运行是在%d年%d月%d日%d时%d分%d秒,心情%s\n",
            year, month, day, h, m, s,mood);
        fclose(fp);                                            /* 关闭文件 */
    }
}

/*--- 写入本次运行时的日期和时间 ---*/
void put_data(void)
{
    FILE* fp;
    char mood[120];
    time_t current = time(NULL);                /* 当前日历时间 */
    struct tm* timer = localtime(&current);        /* 分解时间*/

    if ((fp = fopen(data_file, "w")) == NULL)                /* 打开文件 */
        printf("\a文件打开失败。\n");
    else {
        printf("当前的心情是:");
        scanf("%s", mood);
        fprintf(fp, "%d %d %d %d %d %d %s\n",
            timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday,
            timer->tm_hour, timer->tm_min, timer->tm_sec,mood);
        fclose(fp);                                            /* 关闭文件 */
    }
}

int main(void)
{
    get_data();            /* 取得并显示上一次运行时的日期和时间 */

    put_data();            /* 写入本次运行时的日期和时间 */

    return 0;
}