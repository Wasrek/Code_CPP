/*
    TASK:NC_Radius of Shell
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,idx;
};
stack<A> st;
int a[200010],r[200010],l[200010];
int main(){
    int q,n,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[n+i]=a[i];
        }
        for(i=1;i<=n*2;i++){
            if(st.empty()){
                st.push({a[i],i});
                continue;
            }
            while(!st.empty() && st.top().n<a[i]){
                l[st.top().idx]=i-st.top().idx;
                st.pop();
            }
            st.push({a[i],i});
        }
        while(!st.empty())st.pop();
        for(i=n*2;i>=1;i--){
            if(st.empty()){
                st.push({a[i],i});
                continue;
            }
            while(!st.empty() && st.top().n<a[i]){
                r[st.top().idx]=st.top().idx-i;
                st.pop();
            }
            st.push({a[i],i});
        }
//        for(i=1;i<=n*2;i++){
//            printf("%d ",r[i]);
//        }
//        printf("\n");
//        for(i=1;i<=n*2;i++){
//            printf("%d ",l[i]);
//        }
//        printf("\n");
        for(i=1;i<=n;i++){
            if(r[i+n]==0 && l[i]==0){
                printf("%d ",(n-1)/2);
                continue;
            }
            if(min(r[i+n],l[i])>0)
            printf("%d ",min(r[i+n],l[i])-1);
            else printf("0 ");
        }
        printf("\n");
        while(!st.empty())st.pop();
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
    }
}
/*
1
5
3 4 2 5 1
*/
