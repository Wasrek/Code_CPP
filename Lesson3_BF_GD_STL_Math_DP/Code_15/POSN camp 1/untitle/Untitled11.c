#include<stdio.h>
void main()
{
  int w,d,y,x;
  scanf(" %d %d",&w,&d);
  y=w-1;
  for(x=0;x<y;x++)
  {
  printf("   ");
  }
  for(x=1;x<=d;x++)
  {
   if(x<10){printf(" %d ",x);y++;}else{
  printf("%d ",x);y++;}
  if(y==7){printf("\n");y=0;}
  }
}
