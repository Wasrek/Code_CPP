/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
struct A{
    int i,l,r;
    bool operator <(const A& o) const{
        if(r!=o.r)return r<o.r;
        return l<o.l;
    }
};
int fw[50010];
void upd(int u,int v){
    for(int i=u;i<=50000;i+=(i&-i)) fw[i]+=v;
    return ;
}
int que(int u){
    int now=0;
    for(int i=u;i>0;i-=(i&-i)) now+=fw[i];
    return now;
}
// sol1 O(nlogn) -- fenwick
void sol1(int n, int q, int (&arr)[50100], vector< A > &g){
    vector< PII > gr[50010];
    int cnt[50010];
    unordered_map<int,int> mp,ans;
    for(auto x: g){
        gr[x.r].push_back({x.l,x.i});
    }
    for(int i=1;i<=n;i++){
        if(mp[arr[i]]) upd(mp[arr[i]],-1);
        upd(i,1);
        mp[arr[i]]=i;
        cnt[i]=que(i);
        for(auto x: gr[i]){
            ans[x.second]=(i-x.first+1)-(cnt[i]-que(x.first-1));
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return ;
}
// sol2 O(n*sqrt(n)) -- MO square root decomposition
void sol2(int n, int q, int (&arr)[50100], vector< A > &g){
    vector< A > gr[250],val;
    unordered_map<int,int> ma,answ;
    int l,r,cnt,mp[50100],grz;
    for(int i=1,cou=0;i<=n;i++){
        if(!ma[arr[i]]) ma[arr[i]]=++cou;
        arr[i]=ma[arr[i]];
    }
    for(auto x: g){
        gr[x.l/230].push_back(x);
    }
    for(int i=0;i<=230;i++) {
        if(gr[i].empty()) continue;
        sort(gr[i].begin(),gr[i].end());
        memset(mp,0,sizeof mp);
        l=gr[i][0].l;
        r=gr[i][0].r;
        grz=gr[i].size();
        cnt=0;
        for(int j=l;j<=r;j++){
            if(!mp[arr[j]]) cnt++;
            mp[arr[j]]++;
        }
        answ[gr[i][0].i]=(r-l+1)-cnt;
        for(int j=1;j<grz;j++){
            while(r<gr[i][j].r){
                r++;
                if(!mp[arr[r]]) cnt++;
                mp[arr[r]]++;
            }
            while(l>gr[i][j].l){
                l--;
                if(!mp[arr[l]]) cnt++;
                mp[arr[l]]++;
            }
            while(l<gr[i][j].l){
                mp[arr[l]]--;
                if(!mp[arr[l]]) cnt--;
                l++;
            }
            answ[gr[i][j].i]=(gr[i][j].r-gr[i][j].l+1)-cnt;
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",answ[i]);
    return ;
} 
vector< A > gr[250],val;
unordered_map<int,int> ma,answ;
int mp[50100],a[50100],ans[500010];   
int main()
{
    int n,q,l,r,cnt;
    vector< A > g;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    } 
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        l++;r++;
        g.push_back({i,l,r});
    }
    sol1(n,q,a,g);
    return 0;
}