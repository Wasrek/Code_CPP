/*
    TASK:wir
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int h[100010];
struct A
{
    int h,pow;
};
stack< A > st;
int p[100010];
int main()
{
    int n,m,i,j,ans;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&h[i]);
        while(!st.empty() && st.top().h>h[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            p[i]=max(st.top().pow,h[i]-st.top().h);
        }
        st.push({h[i],p[i]});
    }
    sort(p+1,p+1+n);
    while(m--)
    {
        scanf("%d",&i);
        ans=upper_bound(p+1,p+1+n,i)-p;
        ans=n-ans+1;
        printf("%d\n",ans);
    }
}