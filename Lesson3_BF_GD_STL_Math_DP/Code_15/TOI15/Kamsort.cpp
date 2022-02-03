/*
    TASK:Kamsort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010],mark[1010];
map<int,int> mp;
void dfs(int i){
    if(mark[i])return ;
    mark[i]=1;
    dfs(mp[b[i]]);

}
int main(){
    int n,i,cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        mp[a[i]]=i;
    }
    for(i=1;i<=n;i++){
        if(i!=mp[b[i]] && !mark[i])dfs(i),cnt++;
    }
    if(cnt<=2)
    printf("%d\n",cnt);
    else printf("2\n");
    return 0;
}
