#include<stdio.h>
int main()
{
   int n,m,j,k,i,o,p,l;
   scanf("%d %d",&n,&m);
   int x[n][m];
   int r,c;
   for(r=0;r<n;r++)
   {
      for(c=0;c<m;c++)
      {
         scanf("%d",&x[r][c]);
      }
    }
    scanf("%d",&i);
    while(i--)
    {
       scanf("%d %d %d",&o,&l,&k);
       l-=1;
       if(o==1){
            for(c=0;c<m;c++)
            {
               x[l][c]=k;
            }
       }else{
            for(r=0;r<n;r++)
            {
               x[r][l]=k;
            }
       }
    }
    for(r=0;r<n;r++)
   {
      for(c=0;c<m;c++)
      {
         printf("%d  ",x[r][c]);
      }printf("\n");
    }
}
