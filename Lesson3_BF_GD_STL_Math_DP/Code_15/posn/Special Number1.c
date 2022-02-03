#include<stdio.h>
#include<math.h>
int main()
{
int N[5],x,r[5][4],w=0,c[5],round,f=1;
for(x=0;x<5;x++)
{
scanf(" %d",&N[x]);
round=N[x];

   while(round>=1)
   {
      round=round/10;
      f=f*10;
   }
    while(f>1)
  {
      f = f/10;
      r[x][w]=N[x]/f;
      N[x] = N[x] % f;
      w++;
  }
  c[x]=0;
  for(w=0;w<4;w++)
  {
     c[x]=c[x]+pow(r[x][w],(w+1));
  }
}
for(x=0;x<5;x++)
{
   if(N[5]==c[5]){printf("Y");}else{printf("N");}
}
}


