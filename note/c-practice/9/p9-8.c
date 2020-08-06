/*编写如下函数，实现字符串的逆向输出。
void put_stringr(const char s[])
例如，将"SEC* 显示为"CES"。*/
#include<stdio.h>

#define Number 20

void put_stringr(char s[]){
    int n = 0;
    while (s[n] != 0)
    {
        n++;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%c",s[n - 1 - i]);
    }

}

int main(void){
    char a[Number];

    printf("输入一串字符：\n");
    scanf("%s",a);

    printf("倒序显示如下：\n");
    put_stringr(a);

    return 0;
}