#include<stdio.h>
void main()
{
   int x,y=0;
   scanf(" %d",&x);
   do{
   /*printf("%d ",y);
   y+=10;*/if(y%10==0){printf("%d ",y);}y++;
   }while(y<=x);
}
