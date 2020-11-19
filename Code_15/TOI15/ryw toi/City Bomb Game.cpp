/*
    TASK:City Bomb Game
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1010];
// num will tell if it win or lose if the num that return is not equal to num%2 which is if num ==1 the first player is lose if num==0 the first people win
int ma[1010],kk,ans=-1;
void dfs(int k,int f){
    int state=1;
    for (auto x:g[k]){
        if(x==f)continue;
        dfs(x,k);
        if(state && ma[x]){
            state=0;
            if(k==kk && ans==-1)ans=x;
        }
    }
    ma[k]=state;
    return ;
}
int main(){
    int i,l,n,x,y;
    scanf("%d %d",&n,&kk);
    l=n-1;
    while(l--){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
    dfs(kk,-1);
    if(ans==-1)printf("First player loses\n");
    else printf("First player wins traveling to city %d\n",ans);
}
