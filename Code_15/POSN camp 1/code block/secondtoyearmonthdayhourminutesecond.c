#include<stdio.h>
int main()
{
   int s,y,M,d,h,m,r,x,k;
   scanf("%d",&s);
   r=s%60;
   k=s/60;

   m=k%60;
   k=k/60;

   h=k%24;
   k=k/24;

   d=k%30;
   k=k/30;

   M=k%12;
   k=k/12;

   y=k;
   if(y>1)
   {
      printf("%d Years",y);
   }else
   printf("%d Year",y);

   if(M>1)
   {
      printf("%d Months",M);
   }else
   printf("%d Month",M);

   if(d>1)
   {
      printf("%d Days",d);
   }else
   printf("%d Day",d);

   if(h>1)
   {
      printf("%d Hours",h);
   }else
   printf("%d Hour",h);

   if(m>1)
   {
      printf("%d minutes",m);
   }else
   printf("%d minute",m);

   if(r>1)
   {
      printf("%d Seconds",r);
   }else
   printf("%d Second",r);
}
