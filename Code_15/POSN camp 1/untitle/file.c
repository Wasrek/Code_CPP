#include<stdio.h>
#include<stdlib.h>
int main()
{
   FILE *fp;
   fp = fopen("D:words.txt","r");
   int len=0;
   while(!feof(fp))
   {
      fscanf(fp," %s");
      len++;
   }
   printf("%d\n",len);
   return 0;
}
