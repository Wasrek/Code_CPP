#include<stdio.h>
int main()
{
int b=10;
int *p;
printf("%d\n",b);
//printf("\n%d",&b);
p=&b;
printf("%d\n",&p);
*p=20;
printf("%d\n",b);
}
