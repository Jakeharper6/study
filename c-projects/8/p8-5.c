//请在程序中定义表示性别、季节等的枚举类型，并有效使用它们。

#include <stdio.h>
enum seasons {Spring, Summer, Autumn, Winter, Invalid};

void spring(void)
{
    puts("Spring");
}

void summer(void)
{
    puts("Summer");
}

void autumn(void)
{
    puts("Autumn");
}

void winter(void)
{
    puts("Winter");
}

enum seasons sel(void)
{
    int tmp;
    do {
        printf("0……春天 1……夏天 2……秋天 3……冬天 4……结束：");
        scanf("%d", &tmp);
    } while (tmp < Spring || tmp > Invalid);
    return (enum seasons)tmp;
}

int main(void)
{
    enum seasons selected;
    do {
        switch (selected = sel()) {
        case Spring: spring(); break;
        case Summer: summer(); break;
        case Autumn: autumn(); break;
        case Winter: winter(); break;
        case Invalid: break; 
        }
    } while (selected != Invalid);
    return 0;
}