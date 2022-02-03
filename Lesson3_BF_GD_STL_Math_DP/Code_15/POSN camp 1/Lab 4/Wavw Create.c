/*
    TASK:\Wave Create
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int a[600][600];
main()
{
   int q,x,n,l,i,j,k,st;
   scanf("%d",&q);
   for(x=0;x<q;x++)
   {
       scanf("%d",&n);
       k=(n*4)-3;
       i=0,j=0,st=1;;
       l=(k*k);
       while(l--)
       {
           if(st%4==1)
           {
               if(j==k-1)
               {
                   a[i][j]=1;
                   st++;
               }else
               if(a[i][j+2]==1)
               {
                   st++;
                   if(a[i+2][j]==1){
                       a[i][j]=1;break;}
                   else {a[i][j]=1;}}else
                {
                   a[i][j]=1;j++;
                }
           }
           if(st%4==2)
           {
               if(i==k-1)
               {
                   st++;
               }else
               if(a[i+2][j]==1)
               {
                   a[i][j]=1;st+=1;}else
                {
                   a[i][j]=1;i++;
                }
           }
           if(st%4==3)
           {
               if(j==0)
               {
                   st++;
               }else
               if(a[i][j-2]==1)
               {
                   st+=1;}else
                {
                   a[i][j]=1;j--;
                }
           }else if(st%4==0)
           {
               if(i==0)
               {
                   st++;
               }else
               if(a[i-2][j]==1)
               {
                   st+=1;}else
                {
                   a[i][j]=1;i--;
                }
           }

       }
       for(i=0;i<k;i++)
       {
           for(j=0;j<k;j++)
           {
               if(a[i][j]==1){printf("#");}else {printf(".");}
               a[i][j]=0;
           }printf("\n");
       }
   }
   return 0;
}
