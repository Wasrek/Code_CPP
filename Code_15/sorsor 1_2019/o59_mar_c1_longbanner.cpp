/*
    TASK:longbanner
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int x[100010],y[100010],s[100010],fw[100100];
map<int,int> mp;
deque<int> dq;
void update(int a,int v){
    for(int i=a;i<=100000;i+=(i&-i)){
        fw[i]+=v;
    }
}
int query(int idx){
    int ans=0;
    if(idx<=0){
        return ans;
    }
    for(int i=idx;i>0;i-=(i&-i)){
        ans+=fw[i];
    }
    return ans;
}
int main(){
    int n,h,l,cnt=1;
    scanf("%d %d %d",&n,&h,&l);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
        s[i] = y[i];
        // s[2*i-1]=y[i]; 
        // s[2*i]=y[i]-1; 
    }
    sort(s+1,s+1+n);
    for(int i=1;i<=n;i++){
        if(s[i]==s[i-1])continue;
        mp[s[i]]=cnt++;
    }
//    for(int i=1;i<=n*2;i++){
//        printf("%d %d\n",s[i],mp[s[i]]);
//    }
    int ma=0;
    for(int i=1;i<=n;i++){
        while(!dq.empty() && x[dq.front()]+h<x[i]){update(mp[y[dq.front()]],-1);dq.pop_front();}
        dq.push_back(i);
//        printf("%d %d %d\n %d %d\n",i,dq.front(),x[dq.front()],dq.back(),x[dq.back()]);
        update(mp[y[i]],1);
        // cout<<mp[y[i]]<<"ch"<<endl;
        for(int j=0;j<=l;j++){
            if(mp[y[i]+j]){
                for(int k=0;k<=l;k++){
                    if(mp[y[i]+j-k]){
                        // cout << y[i]+j << ' ' << mp[y[i]+j] << ' ' << query(mp[y[i]+j]) << ' ' << y[i]+j-k << ' ' << mp[y[i]+j-k-1] << ' ' << query(mp[y[i]+j-k-1]) << endl;
                        ma=max(ma,query(mp[y[i]+j])-query(mp[y[i]+j-k]-1));
                    }
                }
            }
        }
//        printf("%d\n",ma);
    }
    printf("%d\n",ma);
}