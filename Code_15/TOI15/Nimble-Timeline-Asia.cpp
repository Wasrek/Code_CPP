#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
vector< int > g[N];
int arr[N];
int fw[N*2];
pair< pair< int,int > ,int > qq[N];
int ans[N];
void update(int idx)
{
    if(!idx)    return;
    while(idx<=1000000)    ++fw[idx],idx+=idx&-idx;
}
int query(int idx,int ans=0)
{
    while(idx)  ans+=fw[idx],idx-=idx&-idx;
    return ans;
}
int main()
{
    int n,q,ptr=0;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)   scanf("%d",&arr[i]);
    for(int i=1,a,b;i<=q;i++)
    {
        scanf("%d %d",&a,&b);
        qq[i]={{a,b},i};
    }
    sort(qq+1,qq+q+1);
    for(int i=1;i<=q;i++)
    {
        while(ptr<=qq[i].first.first)    update(arr[ptr++]);
        int l=1,r=1e6+2;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(query(mid)<qq[i].first.second)   l=mid+1;
            else                                r=mid;
        }
        ans[qq[i].second]=l;
    }
    for(int i=1;i<=q;i++)   printf("%d\n",ans[i]);
    return 0;
}
