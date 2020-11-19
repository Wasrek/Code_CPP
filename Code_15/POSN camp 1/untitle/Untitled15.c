#include<stdio.h>
void main()
{
   int x;int *p;
   printf("Address = %p\n",p);
   p++;
   printf("Address = %p\n",p);
   x = 5;
   p = &x;
   printf("Address %p\n",&x);
   printf("Address %p\n",p);
   printf("Data %d\n",*p);
}
