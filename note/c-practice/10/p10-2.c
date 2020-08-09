/*编写如下函数，将*y年*m月*d日的日期，修改为其前一天或后一天的曰期。
void decrement_date(int *y,int *m,int *d)
void increment_date(int *y,int *m,int *d)
注意计算时要考虑到闰年的问题。*/
#include<stdio.h>

void decrement_date(int *y,int *m,int *d){
     if (*d != 1)
     {
         (*d)--;
     }
     else
     {
         if (*m == 1)
         {
             *d = 31;
             *m = 12;
             (*y)--;
         }
         else if (*m == 3)
         {
             if ((*y % 4 ==0 && *y % 100 != 0) || (*y % 400 == 0))
            {
                *d = 29;
            }
            else
            {
                *d = 28;
            }
            *m = 2;
         }
         else if (*m <= 7)
         {
             if ((*m == 2)||(*m == 4)||(*m == 6))
             {
                 *d = 31;
             }
             else
             {
                 *d = 30;
             }
             (*m)--;
         }
         else
         {
             if ((*m == 10)||(*m == 12))
             {
                 *d = 30;
             }
             else
             {
                 *d = 31;
             }
             (*m)--;
         }    
     }
}

void increment_date(int *y,int *m,int *d){
    if (*m == 12)
    {
        if (*d == 31)
        {
            *d = 1;
            *m = 1;
            (*y)++;
        }
        else
        {
            (*d)++;
        }        
    }
    else if (*m == 2)
    {
        if ((*y % 4 ==0 && *y % 100 != 0) || (*y % 400 == 0))
        {
            if (*d == 29)
            {
                *m = 3;
                *d = 1;
            }
            else
            {
                (*d)++;
            } 
        }
        else
        {
            if (*d == 28)
            {
                *m = 3;
                *d = 1;
            }
            else
            {
                (*d)++;
            }   
        }     
    }
    else if (*m <= 8)
    {
        if ((*m == 4) || (*m == 6))
        {
            if (*d == 30)
            {
                *d = 1;
                (*m)++;
            }
            else
            {
                (*d)++;
            }    
        }
        else
        {
            if (*d == 31)
            {
                *d = 1;
                (*m)++;
            }
            else
            {
                (*d)++;
            }    
        }
    }
    else
    {
        if (*m == 10)
        {
            if (*d == 31)
            {
                *d = 1;
                (*m)++;
            }
            else
            {
                (*d)++;
            }
        }
        else
        {
            if (*d == 30)
            {
                *d = 1;
                (*m)++;
            }
            else
            {
                (*d)++;
            }
        }
    }   
}

int main(void){
    int a, b, c;
    int n, m, o;
    

    printf("请输入日期：\n");
    printf("年：");
    scanf("%d",&a);
    do
    {
        printf("月：");
        scanf("%d",&b);
        if (b <=0 || b > 12)
        {
            printf("请输入合理日期！\n");
        }
    } while (b <=0 || b > 12);
    
    do
    {
        printf("日：");
        scanf("%d",&c);
        if (c <= 0 || c > 31)
        {
            printf("请输入合理日期！\n");
        }
    } while (c <= 0 || c > 31);
    
    n = a;
    m = b;
    o = c;

    decrement_date(&a,&b,&c);
    increment_date(&n,&m,&o);

    printf("此日期前一天是：%d年%d月%d日\n",a,b,c);
    printf("此日期后一天是：%d年%d月%d日",n,m,o);
    

    return 0;
}