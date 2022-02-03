/*
    Prac
    TASK:Fluctuate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,ans=0,i,num;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++)
    {
        scanf("%d",&num);
        if(num-m>ans)
        {
            ans=num-m;
        }
        if(num<m)
        {
            m=num;
        }
    }
    printf("%d",ans);
}
