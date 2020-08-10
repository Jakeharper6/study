/*不使用下标运算符，编写如下函数，显示字符串s。
void put_string(const char *s)*/
#include<stdio.h>

void put_string(const char *s){
	while(*s != 0){
		printf("%c",*s);
        s++;
	}
}

int main(void)
{
	char *str = "ABC";
	
    put_string(str);
    return 0;
}