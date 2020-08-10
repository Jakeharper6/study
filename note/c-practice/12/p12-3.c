/*编写如下函数，从键盘输入int型、long型和double型的值，
将这些值作为xyz结构体的成员，返回该结构体的值。
struct xyz scan_xyz()*/
#include <stdio.h>

struct xyz {
    int x;
    long y;
    double z;
};

struct xyz xyz_of(int x, long y, double z)
{
    struct xyz temp;

    temp.x = x;
    temp.y = y;
    temp.z = z;
    return temp;
}

int main(void)
{   
    int a;
    long b;
    double c;
    struct xyz s = {0, 0, 0};

    printf("x:");	scanf("%d",&a);
	printf("y:");	scanf("%ld",&b);
	printf("z:");	scanf("%lf",&c);
    s = xyz_of(a, b, c);

    printf("xyz.x = %d\n", s.x);
    printf("xyz.y = %ld\n", s.y);
    printf("xyz.z = %f\n", s.z);

    return 0;
}