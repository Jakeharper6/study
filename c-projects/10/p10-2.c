
/*---将 *y 年 *m 月 *d 日的日期，修改为其前一天或后一天的日期。---*/

 

/*---本程序思路应该先思考特殊时期并做特殊处理，如月初和月末则需要额外对日期和月份同时做特殊处理。---*/ 

 

#include <stdio.h>

 

int years(int *y) {		//返回闰年 

	int i = 0;

	if ((*y) % 400 == 0 || ((*y) % 100 != 0 && (*y) % 4 == 0))

		i = 1;

	return i;

}

 

int day(int y, int m) {			//返回各月份的天数。 

	int i = 0;

	switch (m) {

		case 4: 

		case 6:

		case 8:

		case 11: i = 30; break;

		case 2: if (years(y)) i = 29;	else i = 28; break;

		default : i = 31; break;

	}

	return i;

}

 

void decrement_date(int *y, int *m, int *d) {

	(*d)--;			//先对日期减一 

	if(!(*d)) {			//如果减一天为0，则为月初，做特殊处理。 

		(*d) = day(*y, --(*m));

	}

		if(!(*m)) {		//对年初和月初做特殊处理。 

			(*y)--;

			(*m) = 12;

		}

}

 

void increment_date(int *y, int *m, int *d) {

	(*d)++;

	if((*d) > day(*y, *m)) {		//对月末的日期做特别处理。 

		*d = 1;

		(*m)++;

	}

	if (*m > 12) {				//对年末的月份和月末日期做特别处理。 

		(*y)++;

		(*m) = 1;

	}

}

 

int main(void)

{

	int y,m,d;

	

	puts("请输入年月日：");

	scanf("%d %d %d", &y, &m, &d);

	

	decrement_date(&y,&m,&d);

	

	printf("减少了一天的时期为%d年%d月%d日\n",y,m,d);

	

	increment_date(&y,&m,&d);

	

	printf("增加了一天的时期为%d年%d月%d日",y,m,d);

	

	return 0;

 } 
