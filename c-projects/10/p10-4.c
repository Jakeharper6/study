
/*---编写set_idx函数，接收元素类型为int型，元素个数为n的数组，并为所有

元素赋上和下标相同的值。---*/

 

#include <stdio.h>

 

void set_idx (int *v, int n) {

	int idx;

	for(idx = 0; idx < n; idx++) {

		v[idx] = idx;

	} 

}

 

int main(void)

{

	int n,v[n],i;

	

	printf("请输入数组大小：");

	scanf("%d",&n);

	

	set_idx(v,n);

	

	for(i = 0; i < n; i++)

		printf("%d ",v[i]);

		

	return 0;

}
