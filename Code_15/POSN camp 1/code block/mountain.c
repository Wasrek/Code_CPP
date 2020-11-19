#include<stdio.h>
int a,d,f,s,t;
int main()
{
   printf("Enter number : ");
   scanf("%d",&d);
   for(a=1;a<=d;a++)
   {

   for(f=(d-a);f>=1;f--)
   {
      printf(" ");
   }

   for(s=1;s<=a;s++)
   {
      printf(" *");
   }
   for(f=((2*(d-a))-2);f>=1;f--)
   {
      printf(" ");
   }

   for(s=1;s<=a;s++)
   {
       if(s!=d){
      printf(" *");}
   }
   printf("\n");
   }

  /*  for(a=1;a<=d;a++)
   {

   for(f=((3*d)-a+);f>=1;f--)
   {
      printf(" ");
   }

   for(s=1;s<=a;s++)
   {
      printf(" *");
   }
   printf("\n");
   }*/
}
