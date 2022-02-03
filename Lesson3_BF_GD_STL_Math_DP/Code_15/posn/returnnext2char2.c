#include<stdio.h>
#include<math.h>
int main()
{
   char n,x;
   scanf("%c",&n);
   x=(((n%32)+1)%26);
   if (65<=n && n<=90)
   {
       printf("%c",x+65);
   }
   if (97<=n && n<=122)
   {
       printf("%c",x+97);
   }
   return 0;
}
