/*
    TASK:Cats TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
stack<long long> st;
int main(){
    long long n,i,ma=-1,l,r,mid,t,t1,t2,ch;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ma=max(ma,a[i]);
    }
    l=0,r=ma+1;
    while(l<r){
        mid=(l+r)/2;
        for(i=1;i<=n;i++){
            if(a[i]>mid)st.push(a[i]);
        }
        ch=0;
        while(!st.empty()){
            t1=st.top();
            st.pop();
            if(!st.empty()){
            t2=st.top();
            st.pop();
            }
            if(t1!=t2){
                ch=1;
                while(!st.empty())st.pop();
                break;
            }
        }
        if(ch)l=mid+1;
        else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}
