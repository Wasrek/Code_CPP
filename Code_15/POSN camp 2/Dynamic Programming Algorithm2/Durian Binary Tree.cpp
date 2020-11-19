/*
    TASK:Durian Binary Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v[110];
int p[110];
int mic[105][105];
vector<int> child[110];
void dfs(int now)
{
    for(auto x:v[now])
    {
        if(p[x.first]==-1){
            p[x.first]=x.second;
            child[now].push_back(x.first);
            dfs(x.first);
        }
    }
}
int play(int now,int k){
    if(mic[now][k]!=-1) return mic[now][k];
    if(k==0) return 0;
    if(child[now].size()==0)return p[now];
    if(child[now].size()==1) return mic[now][k] = play(child[now][0],k-1)+p[now];
    int Max=-1;
    for(int i=0;i<=k-1;i++){
        Max=max(Max,play(child[now][0],i)+play(child[now][1],k-i-1));
    }
    return mic[now][k]=Max+p[now];
}
int main(){
    int n,k,s,e,val;
    scanf("%d %d",&n,&k);
    memset(p,-1,sizeof p);
    memset(mic,-1,sizeof mic);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&s,&e,&val);
        v[s].push_back({e,val});
        v[e].push_back({s,val});
    }
    p[1]=0;
    dfs(1);
    printf("%d\n",play(1,k+1));
}
