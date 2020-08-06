//编写一段程序，纵向显示练习5-8中得到的分布图。

#include <stdio.h>

#define NUMBER 15    /*人数上限*/

int main(void)
{
    int i, j;
    int num;              /*实际的人数*/
    int tensu[NUMBER];    /*学生的分数*/
    int bunpu[11] = {0};  /*分布图*/
    int n,t; 
    int max = 0;

    printf("请输入学生人数：");
    do {
        scanf("%d", &num);
        if (num < 1 || num > NUMBER)
            printf("请输入1-%d的数：", NUMBER);
    } while (num < 1 || num > NUMBER);
    
    printf("请输入%d人的分数。\n", num);

    for (i = 0; i < num; i++)
    {
        printf("%2d号:", i + 1);
        do {
            scanf("%d", &tensu[i]);
            if (tensu[i] < 0 || tensu[i] > 100)
                printf("请输入1-100的数：");
        } while (tensu[i] < 0 || tensu[i] > 100);
        bunpu[tensu[i] / 10]++;
    }
    
    for(n = 0; n <= 10; n++){
        if (bunpu[n] >= max)
        {
            max = bunpu[n];
        }
    }

    puts("\n---分布图---");
    t = max;
    for (j = 0; j < max; j++,t--)
    {
        for (n = 0; n <= 10; n++)
        {
            if (bunpu[n] >= t)
            {
                printf("%5s","*");
            }
            else
            {
                printf("%5s"," ");
            }
            
        }
        printf("\n");
    }
    
    for (n = 0; n <= 10; n++)
    {
        printf("%5s","-");
    }
    printf("\n");

    for (n = 0; n <= 10; n++)
    {
        printf("%5d", n * 10);
    }

    return 0;
}