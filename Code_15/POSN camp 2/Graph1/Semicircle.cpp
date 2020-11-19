/*
    TASK:Semicircle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int f,t;
};
A a[710];
vector<int>g[710];
int col[710];
int check(int i,int j){
    if(a[i].t>a[j].f && a[j].f>a[i].f && a[j].t>a[i].t)return 1;
    swap(i,j);
    if(a[i].t>a[j].f && a[j].f>a[i].f && a[j].t>a[i].t)return 1;
    return 0;
}
int dfs(int u,int c){
    if(col[u]!=-1 && col[u]==c) return 1;
    if(col[u]!=-1 && col[u]!=c) return 0;
    col[u]=c;
    for(auto x:g[u]){
        if(dfs(x,3-c)==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int q,n,i,j,ans,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].f,&a[i].t);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(check(i,j))
                    g[i].push_back(j),g[j].push_back(i);
            }
        }
        memset(col,-1,sizeof col);
        ch=1,ans=1;
        for(i=0;i<n;i++){
            if(col[i]==-1){
            if(dfs(i,1)==0){
                ch=0;
                break;
            }else{
                ans*=2;
                ans%=1001;//find component
            }
            }
        }
        if(ch==1) printf("%d\n",ans);
        else printf("0\n");
        for(i=0;i<n;i++)g[i].clear();
    }
    return 0;
}
/*
2
2 1 4 2 5
 3 3 9 6 9 3 6
 */
