/*编写如下函数，将字符串s中的数字字符全部删除。
void del_digit(char s[])
例如传入"AB1C9“则返回"ABC"。*/

#include<stdio.h>
#define Number 20

void del_digit(char s[]){
    int n = 0;
    int j = 0;
    while (s[n] != 0)
    {
        if (s[n] <= '0' || s[n] >= '9')
        {
            s[j] = s[n];
            j++;
        }
        n++;
    }
    s[j] = 0;

    printf("%s",s);
}

int main(void){
    char a[Number];
    printf("输入一串字符：\n");
    scanf("%s",a);

    printf("去除数字结果如下\n");
    del_digit(a);

    return 0;
}