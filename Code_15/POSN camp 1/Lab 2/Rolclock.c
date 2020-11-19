/*
    TASK:Rolclock
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
       int x,a=6;
   scanf("%d",&x);
   x=x%360;
   while(x>=30)
   {
      a=(a+1);
      x=x-30;
   }
   a=a%12;
   if(a==0){a=12;}
   if(a!=12){
   if(x>15)
   {
      printf("%d",a+1);
   }else if(x<=15)
   {
      printf("%d",a);
   }
   }else
   if(a==12){if(x>=15){printf("1");}else{printf("12");}}
    return 0;
}
