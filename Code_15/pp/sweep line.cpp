/*
    TASK:sweep line
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int idx,val;
    bool operator < (const A& o) const
    {
        return idx<o.idx;
    }
};
A event[200005];
int finalIndex[200005];
int finalValue[200005];
int main()
{
    int n,m,i,q,a,s,e,v,att;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&s,&e,&v);
        event[i*2+1]={s,v};
        event[i*2+2]={e+1,-v};
    }
    int val=0;
    sort(event+1,event+2*m+1);
    for(i=1;i<=2*m;i++)
    {
        val+=event[i].val;
        finalValue[i]=val;
        finalIndex[i]=event[i].idx;
    }
    finalIndex[i]=n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&a);
        att=upper_bound(finalIndex,finalIndex+i+1,a)-finalIndex-1;
        printf("%d\n",finalValue[att]);
    }
    return 0;
}
