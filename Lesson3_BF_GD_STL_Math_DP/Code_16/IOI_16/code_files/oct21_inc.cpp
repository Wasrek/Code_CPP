/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010];
vector< int > g[1010],ans;
int main()
{
    int n,idx=0,now;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        now=lower_bound(b,b+idx,a[i])-b;
        if(now==idx) idx++;
        b[now]=a[i];
        g[now].push_back(a[i]);
    }
    int la=g[idx-1][0],j;
    ans.push_back(la);
    for(int i=idx-2;i>=0;i--){
        for(auto x: g[i]){
            if(x<la){
                la=x;
                ans.push_back(la);
                break;
            }
        }
    }
    printf("%d\n",idx);
    for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
    return 0;
}