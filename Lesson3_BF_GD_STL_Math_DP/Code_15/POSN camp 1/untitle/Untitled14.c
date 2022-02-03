#include<stdio.h>
#include<string.h>
int main()
{
   char s[100];
   gets(s);
   char x;
   scanf(" %c",&x);
   int l=strlen(s),f,k=0;
   for(f=0;f<l;f++)
   {
       if(s[f]==x)
       {
       printf("yes");k=1;
       break;
       }
   }
   if(k==0)
   printf("NO");
}
