/*编写如下函数，逆向显示字符串s的字符。
void rev_string(char s[])
例如，若s中接收的是"SEC",则将其数组更新为“CES”。*/

#include<stdio.h>

#define Number 20

void put_stringr(char s[]){
    int n = 0;
    while (s[n] != 0)
    {
        n++;
    }
    
    int j = 0;
    int t;
    for (int i = 0; i < n / 2; i++)
    {
        t = s[j];
        s[j] = s[n - 1 - i];
        s[n - 1 - i] = t;
        j++;
    }

    printf("%s",s);
}

int main(void){
    char a[Number];

    printf("输入一串字符：\n");
    scanf("%s",a);

    printf("倒序更新如下：\n");
    put_stringr(a);

    return 0;
}