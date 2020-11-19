#include<stdio.h>
char s[120],k[120][120],n[120];
int main()
{
   int x,y,z,r,t=0,m,c;
   scanf("%d %d %d",&x,&y,&z);
   if(x%y==0)
   {
      m=x/y;
   }else
   {
      m=(x/y)+1;
   }
   scanf(" %s",s);
   for(r=0;r<m;r++){
      for(c=0;c<y;c++){
          k[r][c]=s[t];
          t++;
      }
   }
   t=0;
   for(c=0;c<y;c++)
   {
      for(r=0;r<m;r++)
      {
          if (k[r][c]!=NULL)
          {
              printf("%c",k[r][c]);
              n[t]=k[r][c];
              t++;
          }
      }
   }
   printf("\n");
   for(r=0;r<x;r++){
    if(n[r]+z>90 && n[r]<=90)
        n[r]-=26;
    if(n[r]+z>122)
        n[r]-=26;
    n[r]+=z;
   }
   for(r=0;r<x;r++){
      printf("%c",n[r]);
   }
return 0;
}
