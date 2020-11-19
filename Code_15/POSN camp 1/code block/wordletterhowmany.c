#include<stdio.h>
#include<string.h>
char n[250];
int h,x,k=0;
int main()
{
   printf("Enter String : ");
   gets(n);
   x=strlen(n);
   for(h=0;h<x;h++)
   {
      if(n[h]==' ')
      {
         k=k+1;
      }
   }
   printf("word = %d\n",(k+1));
   printf("letter = %d",(x-k));
}
