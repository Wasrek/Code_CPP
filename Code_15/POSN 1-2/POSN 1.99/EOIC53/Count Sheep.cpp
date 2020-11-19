/*
    TASK:Count Sheep
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int mark[15];
int main()
{
    int cou,i,q,n,ans,j,sum,k,t;
    scanf("%d",&q);
    for(i=1; i<=q; i++)
    {
        cou=0;
        scanf("%d",&n);
        if(n==0)
        {
            printf("Case #%d: INSOMNIA\n",i);
            continue;
        }
        else
        {
            sum=0,cou=0;
            for(j=1; j<=100; j++)
            {
                sum+=n;
                k=sum;
                while(k>0)
                {
                    t=k%10;
                    k/=10;
                    if(mark[t]==0)
                        mark[t]=1,cou++;
                }
                if(cou==10)
                {
                    ans=sum;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",i,ans);
        memset(mark,0,sizeof mark);
    }
}

