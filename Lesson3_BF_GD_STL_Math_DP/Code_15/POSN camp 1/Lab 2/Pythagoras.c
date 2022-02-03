/*
    TASK:Pythagoras
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
   double a,b,c,r;
   scanf("%lf %lf %lf",&a,&b,&c);
   if(a==0)
   {
     r=sqrt(pow(c,2)-pow(b,2));
   }else
   if(b==0)
   {
     r=sqrt(pow(c,2)-pow(a,2));
   }else
   if(c==0)
   {
     r=sqrt(pow(a,2)+pow(b,2));
   }
   printf("%.2lf\n",r);
    return 0;
}
