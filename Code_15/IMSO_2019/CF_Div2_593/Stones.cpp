/*
    TASK:Exam MO's Algo
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r,i;
    bool operator< (const A & o) const{
        return r<o.r;
    }
};
vector< A > g[250];
vector< int > v;
int arr[50100],ans[500010], cou[50100];
unordered_map<int,int> mp;
int gro(int l){
    return ((l-1)/230)+1;
}
int main()
{
    int n, q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
      if(mp[v[i]]) continue;
      mp[v[i]] = cnt++;
    }
    for(int i=1 ; i<=n ; i++) arr[i] = mp[arr[i]];
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int l, r;
        scanf("%d %d",&l,&r);
        l++, r++;
        g[gro(l)].push_back({l, r, i});
        assert(gro(l) <= 230);
    }
    for(int i=1;i<=230;i++){
        if(g[i].empty()) continue;
        sort(g[i].begin(),g[i].end());
        int now=0, sz = g[i].size();
        memset(cou, 0, sizeof cou);
        int l=g[i][0].l,r=g[i][0].r;
        for(int j=l ; j<=r ; j++){
            cou[arr[j]]++;
            if(cou[arr[j]] >= 2) now++;
        }
        ans[g[i][0].i] = now;
        for(int j=1 ; j<sz ; j++){
            while(l<g[i][j].l){
                if(cou[arr[l]]>=2)now--;
                cou[arr[l]]--;
                l++; 
            }
            while(l>g[i][j].l){
                l--;
                cou[arr[l]]++;
                if(cou[arr[l]]>=2)now++;
            }

            while(r<g[i][j].r){
                r++;
                cou[arr[r]]++;
                if(cou[arr[r]]>=2)now++;
            }
            ans[g[i][j].i]=now;
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}