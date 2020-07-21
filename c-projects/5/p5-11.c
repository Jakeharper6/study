//编写一段程序，输入6名学生2门课程(语文、数学)的分数，显示各门课程的总分和平均分，以及各个学生的总分和平均分。

#include <stdio.h>

#define stu 6

#define lesson 2

int main(void)

{

    int a, b;

    double la[stu][lesson], sum0, sum1 = 0, sum2 = 0;

    //sum0为各学生总成绩，sum1为语文总成绩， sum2为数学总成绩。

    for (a = 0; a < stu; a++)
    {

        sum0 = 0;

        for (b = 0; b < lesson; b++)
        {

            do
            {

                printf("请输入第%d名学生第%d门成绩。", a + 1, b + 1);

                scanf("%lf", &la[a][b]);

                if (b == 0)

                    sum1 += la[a][b];

                else

                    sum2 += la[a][b];

                if (la[a][b] > 100 || la[a][b] < 0)
                {

                    printf("您输入的值过大，请重新输入。");
                }

            } while (la[a][b] > 100 || la[a][b] < 0);

            sum0 += la[a][b];
        }

        printf("第%d名学生的总分为%f,平均分为%f\n", a + 1, sum0, sum0 / lesson);
    }

    printf("语文成绩的总分为%f,平均分为%f,数学成绩的总分为%f,平均分为%f\n", sum1, sum1 / stu, sum2, sum2 / stu);

    return 0;
}
