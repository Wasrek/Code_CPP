/*
    TASK:RC_Pokemon
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int m[1010][1010],in[1010],ou[1010];
char a[5],b[5];
map<string,int> mp;
vector<int> g[1010];
queue<int> q;
int main(){
    int n,i,cou=0,ch=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %s %s",a,b);
        if(!mp[a])mp[a]=++cou;
        if(!mp[b])mp[b]=++cou;
        g[mp[a]].push_back(mp[b]);
        ou[mp[a]]++;
        in[mp[b]]++;
    }
    for(i=1;i<=cou;i++){
        if(in[i]==0)q.push(i);
    }
    int cnt=0,qq;
    while(!q.empty()){
        qq=q.front();
        cnt++;
        q.pop();
        for(auto x:g[qq]){
            in[x]--;
            if(in[x]==0)q.push(x);
        }
    }
    if(cnt==cou)printf("OK");
    else printf("BUG");
}
/*
3
000 001
001 002
000 002
*/
