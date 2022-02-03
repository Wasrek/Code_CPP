#include<stdio.h>
char x[120][120];
int main()
{
   int n,m,N,M,l,k;
   scanf("%d %d %d %d",&n,&m,&N,&M);
   int r,c;
   for(r=0;r<n;r++)
   {
      for(c=0;c<m;c++)
      {
         scanf(" %c",&x[r][c]);
      }
   }
    for(r=0;r<n;r++){
        for(k=0;k<N;k++){
            for(c=0;c<m;c++){
                for(l=0;l<M;l++){
                    printf("%c",x[r][c]);
                }
            }
            printf("\n");
        }
    }
}
