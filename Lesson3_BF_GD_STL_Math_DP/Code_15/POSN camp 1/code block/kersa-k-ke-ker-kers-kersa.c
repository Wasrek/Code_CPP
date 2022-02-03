#include<stdio.h>
char n[30];
int x,v,h;
int main()
{
  printf("Enter your name : ");
  gets(n);
  x=strlen(n);
  for(v=0;v<x;v++)
  {
     for(h=0;h<=v;h++)
     {
        printf("%c",n[h]);
     }
     printf("\n");
  }

}
