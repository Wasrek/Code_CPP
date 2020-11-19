#include<stdio.h>
#include<string.h>
char turn(char a){
   printf("R");
   if(a=='N') return 'E';
   if(a=='E') return 'S';
   if(a=='S') return 'W';
   if(a=='W') return 'N';
}
char str[1000];
int main()
{
   int i,len;
   char tid='N';
   scanf(" %s",str);
   len=strlen(str);
   for(i=0;i<len;i++)
   {
      if(str[i]=='N'){
         while(tid!='N') tid=turn(tid);
         printf("F");
      }
      if(str[i]=='E'){
         while(tid!='E') tid=turn(tid);
         printf("F");
      }
      if(str[i]=='S'){
         while(tid!='S') tid=turn(tid);
         printf("F");
      }
      if(str[i]=='W'){
         while(tid!='W') tid=turn(tid);
         printf("F");
      }
      if(str[i]=='Z')
      {
         printf("Z");tid='N';
      }
   }
   return 0;
}
