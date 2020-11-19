#include<stdio.h>
char n[120],a[160];
int main()
{
   int x,y,z,k;
   scanf(" %s",n);
   x=strlen(n);
   y=3-(x%3);
   for(z=0;z<y;z++)
   {
      a[z]='0';
   }
   strcat(a,n);
   for(k=0;k<x;k+=3)
   {
       if(a[k]=='0')
       {
           if(a[k+1]=='0')
           {
               if(a[k+2]=='0')
               {
                   printf("0");
               }else if(a[k+2]=='1')
               {
                   printf("1");
               }
           }else if(a[k+1]=='1')
           {
               if(a[k+2]=='0')
               {
                   printf("2");
               }else if(a[k+2]=='1')
               {
                   printf("3");
               }
           }
       }else if(a[k]=='1')
       {
           if(a[k+1]=='0')
           {
               if(a[k+2]=='0')
               {
                   printf("4");
               }else if(a[k+2]=='1')
               {
                   printf("5");
               }
           }else if(a[k+1]=='1')
           {
               if(a[k+2]=='0')
               {
                   printf("6");
               }else if(a[k+2]=='1')
               {
                   printf("7");
               }
           }
   }

   }
}
