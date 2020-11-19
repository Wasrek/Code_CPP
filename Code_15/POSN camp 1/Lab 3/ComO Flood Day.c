/*
    TASK:ComO Flood Day
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int n,x,a=0;
    scanf(" %d",&n);
    int d[n];
    for(x=0;x<n;x++)
    {
    scanf(" %d",&d[x]);
    if(d[x]>=80)
    {
       a=a+1;
    }else
    if(d[x]>=20 && (d[x]-10)>=d[x-1] && x!=0)
    {
       a=a+1;
    }
    }
    printf("%d",a);


    return 0;
}
