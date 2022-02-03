#include<stdio.h>
#include<string.h>
int main()
{
   char s[100];
   gets(s);
   printf("%d\n",strlen(s));
   int l=strlen(s),x;
   for(x=(l-1);x>=0;x--)
   {
       printf("%c",s[x]);
   }
   printf("\n%s",strrev(s));

}
