/*
    TASK:o64_feb_c2_kon
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100],fr[1000100],pa[1000100][3],la[1000100],gt[1000100],h[1000100];
vector< int > a;
stack<char> st;
int main()
{
    //freopen("kon.in","r",stdin);
    freopen("kon.out","w",stdout);
    int n,ch=0;
    scanf("%d",&n);
    while(n!=1){
        ch=0;
        // printf("%d\n",n);
        for(int i=2;i<=int(sqrt((double)n));i++){
            if(n%i==0){
                a.push_back(i);
                n/=i;
                ch=1;
                break;
            }
        }
        if(ch==0) a.push_back(n),n=1;
    }
    // for(auto x: a) printf("%d ",x);
    int ans=0,now;
    for(int i=0;i<a.size();i++){
        if(i==0){
            dp[i]=a[i]+2;
            la[i]=a[i];
            h[i]=1;
            gt[i]=-1;
            continue;
        }
        dp[i]=dp[i-1]+2+a[i];
        la[i]=a[i];
        h[i]=1;
        gt[i]=i-1;
        now=1;
        for(int j=i;j>=1;j--){
            now*=a[j];
            if(dp[j-1]+2+now<dp[i]){
                dp[i]=dp[j-1]+2+now;
                la[i]=now;
                h[i]=1;
                gt[i]=j-1;
            }
        }
        if(now*a[0]+2<dp[i]){
            dp[i]=now*a[0]+2;
            la[i]=now*a[0];
            h[i]=1;
            gt[i]=-1;
        }
    }
    // printf("%d\n",dp[n]);
    int at=a.size()-1;
    while(1){
        // printf("%d %d\n",at,la[at]);
        for(int i=1;i<=la[at];i++){
            st.push('V');
            // printf("V");
        }
        if(h[at]){
            st.push('C');
            st.push('A');
            // printf("CA\n");
        }
        if(gt[at]==-1) break;
        at=gt[at];
    }
    while(!st.empty()){
        printf("%c",st.top());
        st.pop();
    }
    return 0;
}