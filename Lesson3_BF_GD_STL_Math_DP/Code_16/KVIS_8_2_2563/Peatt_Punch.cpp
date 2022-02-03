/*
    TASK:Peatt Punch
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],p[100010];
struct A{
    int h,p;
};
stack<A> st;
int main()
{
    int l,q,now;
    scanf("%d %d",&l,&q);
    for(int i=1;i<=l;i++){
        scanf("%d",&a[i]);
    }
    st.push({a[1],0});
    p[1]=0;
    for(int i=1;i<=l;i++){
        while(!st.empty() && st.top().h>a[i]){
            st.pop();
        }
        if(st.empty()) p[i]=0;
        else p[i]=max(st.top().p,a[i]-st.top().h);
        st.push({a[i],p[i]});       
    }
    // for(int i=1;i<=l;i++){
    //     printf("%d ",p[i]);
    // }
    // printf("\n");
    sort(p+1,p+1+l);
    while(q--){
        scanf("%d",&now);
        now=upper_bound(p+1,p+l+1,now)-p-1;
        printf("%d\n",l-now);
    }
    return 0;
}