#include<stdio.h>
int main()
{
   int n[9][9];
   int x,y,c=0,f=0,l,a,b=0,v=0,r=0;
   for(x=0;x<9;x++){
      for(y=0;y<9;y++){
        scanf(" %d",&n[x][y]);
      }
   }
   for(x=0;x<9;x++){
      for(y=0;y<9;y++){
        if(n[x][y]==0)
        {
               for(a=0;a<9;a++){
               b=n[x][a]+b;
               v=n[a][y]+v;
               }
               if((45-b)<=9){r=b;}else{r=v;}
               if(c==0)
                {c=45-r;b=0;}else{f=45-r;}
        }
       /* if(n[y][x]==0)
        {
               for(a=0;a<9;a++){
               v=n[y][a]+v;
               }
               if(v<=9){r=v;
               if(c==0)
                {c=45-r;v=0;}else{f=45-r;}}
        }*/
      }
   }

   if(c<=f)
   {printf("%d %d",c,f);}else{printf("%d %d",f,c);}
}
