#include<stdio.h>
#include<math.h>
int main()
{
   int N;
   scanf(" %d",&N);
   int x[N],y[N],s=0,a;
   float l[N];
   for(a=0;a<N;a++)
   {
      scanf(" %d %d",&x[a],&y[a]);
      l[a]=sqrt(pow(x[a],2)+pow(y[a],2));
      if(l[a]<=2)
      {s=s+5;}else
      if(l[a]<=4)
      {s=s+4;}else
      if(l[a]<=6)
      {s=s+3;}else
      if(l[a]<=8)
      {s=s+2;}else
      if(l[a]<=10)
      {s=s+1;}
   }
   printf("%d",s);
}
