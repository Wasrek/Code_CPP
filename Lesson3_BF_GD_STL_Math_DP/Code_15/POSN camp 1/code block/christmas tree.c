#include<stdio.h>
int a,d,f,s,t;
int main()
{
   printf("Enter number : ");
   scanf("%d",&d);
   for(a=1;a<=d;a++)
   {

   for(f=(d-a+4);f>=1;f--)
   {
      printf(" ");
   }

   for(s=1;s<=a;s++)
   {
      printf(" *");
   }
   printf("\n");
   }


   for(a=1;a<=(d+2);a++)
   {

   for(f=(d-a+4);f>=1;f--)
   {
      printf(" ");
   }

   for(s=1;s<=a;s++)
   {
      printf(" *");
   }
   printf("\n");
   }


   for(a=1;a<=(d+4);a++)
   {

   for(f=(d-a+4);f>=1;f--)
   {
      printf(" ");
   }

   for(s=1;s<=a;s++)
   {
      printf(" *");
   }
   printf("\n");
   }
}
