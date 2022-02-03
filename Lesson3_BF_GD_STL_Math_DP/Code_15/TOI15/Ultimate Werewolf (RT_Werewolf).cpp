/*
    TASK:Ultimate Werewolf (RT_Werewolf)
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],in[100010],c[1000010];
void dfs(int now,int col){
    if(c[now])return ;
    c[now]=col;
    in[a[now]]--;
    if(in[a[now]]==0 || col==1)dfs(a[now],3-col);
}
int main(){
    int q,n,i,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){scanf("%d",&a[i]);in[a[i]]++;}
        for(i=1;i<=n;i++){
            if(in[i]==0)dfs(i,1);
        }
        for(i=1;i<=n;i++){
            if(!c[i])dfs(i,2);
        }
        ans=0;
        for(i=1;i<=n;i++)if(c[i]==2)ans++;
        printf("%d\n",ans);
        memset(in,0,sizeof in);
        memset(c,0,sizeof c);
    }
}
