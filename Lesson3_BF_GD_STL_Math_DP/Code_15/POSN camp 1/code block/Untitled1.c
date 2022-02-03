#include<stdio.h>
int main()
{
    int n,m,l,k=1;
    scanf("%d",&n);
    for(m=1;m<=n;m++)
    {
       printf("%d ",m);
    }
    printf("\n");
    l=n;
    while(l>0)
   {
        printf("%d ",l);
        l--;
    }
    printf("\n");
    for(k=2;k<=n;k+=2)
    {
       printf("%d ",k);
    }
    printf("\n");
     for(k=n;k>=1;k-=1)
    {
        if(k%2==0)
        {
             printf("%d ",k);
        }
    }
     printf("\n");
     k=1;
    while(k<=n)
    {
       printf("%d ",k);
       k+=2;
    }
    printf("\n");
     for(k=n;k>=1;k-=1)
    {
        if(k%2==1)
        {
             printf("%d ",k);
        }
    }
    printf("\n");
    return 0;

}
