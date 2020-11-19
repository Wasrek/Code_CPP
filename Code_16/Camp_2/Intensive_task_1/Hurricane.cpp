/*
    TASK:Hurricane
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long h,cnt;
};
stack< A > st;
int main()
{
    long long n,now,cnt,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&now);
        cnt=1;
        while(!st.empty() && st.top().h<=now){
            if(st.top().h==now) cnt+=st.top().cnt;
            ans+=st.top().cnt;
            st.pop();
        }
        if(!st.empty()) ans++;
        st.push({now,cnt});
    }
    printf("%lld\n",ans);
    return 0;
}