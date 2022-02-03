/*
    TASK:Silly Bakery
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int main()
{
    int n,q,a=0,b=0,c=0,d=0,e=0,ans=0,A,B,C,D,E;
    int quarter,eight;
    scanf(" %d",&n);
    for(q=0;q<n;q++)
    {
        scanf(" %d %d %d %d %d",&A,&B,&C,&D,&E);
        a=a+A;
        b=b+B;
        c=c+C;
        d=d+D;
        e=e+E;
    }
    ans=a+b+(c/2);
    quarter =b;
    if(c%2==1)
    {
        ans++,quarter+=2;
    }
    if(quarter>=d)
    {
        eight = (quarter-d)*2;
    }else
    {
        ans+=(d-quarter)/4;
        if((d-quarter)%4!=0)
        {
            ans++,eight=(4-((d-quarter)%4))*2;
        }
    }
    if(eight < e)
    {
        ans+=(e-eight)/8;
        if((e-quarter)%8!=0)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
