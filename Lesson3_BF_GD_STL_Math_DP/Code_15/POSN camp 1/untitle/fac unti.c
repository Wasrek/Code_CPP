#include<stdio.h>
long fac(long);
int main(){
   int i,k;
   printf("Enter Num");
   scanf("%d",&k);
   for(i=1;i<=k;i++)
   {printf("%2d! = %d\n",i,fac(i));}
}
long fac(long number){
   if(number<=1)
   return 1;
   else
   return(number*fac(number-1));
}

