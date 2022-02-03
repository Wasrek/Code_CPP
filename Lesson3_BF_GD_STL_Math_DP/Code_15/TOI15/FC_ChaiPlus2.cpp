/*
    TASK: FC_ChaiPlus2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> m[3];
int a[2],v[35],w[35],W,wei[1<<16],val[1<<16];
void play(int type,int i,int we,int va){
    if(we>W) return ;
    if(i==a[type]){
        m[type][we]=max(va,m[type][we]);
        return ;
    }
    play(type,i+1,we+w[i],va+v[i]);//Pick
    play(type,i+1,we,va);
}
int main(){
    int q,ans,n,idx,i;
    scanf("%d",&q);
    while(q--){
        m[0].clear();
        m[1].clear();
        ans=0;
        scanf("%d %d",&n,&W);
        a[0]=n/2;
        a[1]=n;
        for(i=0;i<n;i++){
            scanf("%d %d",&w[i],&v[i]);
        }
        play(0,0,0,0);
        play(1,n/2,0,0);
    //Matching
    i=0;
    for(auto it=m[0].begin();it!=m[0].end();it++,i++){
        wei[i] = it->first,val[i]= it->second;
        if(i>0) val[i] = max(val[i],val[i-1]);
    }
    for(auto it = m[1].begin();it!=m[1].end();it++){
        idx = upper_bound(wei,wei+i,W-it->first)-wei;
        idx--;
        if(idx!=-1){
            ans=max(ans,it->second+val[idx]);
        }
    }
    printf("%d\n",ans);
    }
}
