#include<stdio.h>
int main()
{
   char n;
   scanf("%c",&n);
   if (n!='z' && n!='Z' && n!='Y' && n!='y')
   {
      printf("%c",n+2);
   }

   if (n=='z')
   {
      printf("b");
   }

    if (n=='Z')
   {
      printf("B");
   }
    if (n=='y')
   {
      printf("a");
   }
    if (n=='Y')
   {
      printf("A");
   }

   return 0;
}
