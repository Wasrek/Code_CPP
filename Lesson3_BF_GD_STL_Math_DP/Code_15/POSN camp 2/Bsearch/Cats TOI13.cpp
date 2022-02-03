/*
    TASK:Cats TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
stack<long long> st;
int main(){
    long long n,ch=0,i,ans,l,r,Max=0,mid,b,d,c;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        Max=max(Max,a[i]);
    }
    l=0,r=Max+1;
    while(l<r){
        mid=(l+r)/2;
        for(i=1;i<=n;i++){
            if(a[i]>mid)st.push(a[i]);
        }
        c=0;
        while(!st.empty()){
            b=st.top();
            st.pop();
            d=st.top();
            st.pop();
            if(b!=d){
                c=1;//cant
            }
        }
        if(c)l=mid+1;
        else if(c==0)r=mid;
    }
    printf("%lld",l);
}
