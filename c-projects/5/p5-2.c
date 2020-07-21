//对代码清单5-3中的程序进行修改，从头顺次为数组中的元素赋值5、4、3、2、1

#include <stdio.h> 
 
int main(void)
{
	int i;
	int v[5];
	
	for(i=5;i>0;i--){
		v[5-i]=i;
		printf("v[%d] = %d\n",5-i,v[5-i]);
	}
	return 0;
}
