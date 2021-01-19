/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int arr[100100],qu[100100],gr[100100],lz[400100],seg[400100];
map<int,int> mp;
void build(int l,int r,int now){
    if(l==r){
        if(l%2) seg[now]=gr[l];
        else seg[now]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now]=seg[now*2]+seg[now*2+1];
    return ;
}
stack<int> ans;
void upd(int l,int r,int a,int b,int now){
    // printf("%d %d %d %d %d\n",l,r,a,b,now);
    if(lz[now]){
        lz[now]=0;
        seg[now]=arr[r]-arr[l-1]-seg[now];
        if(l!=r) lz[now*2]^=1,lz[now*2+1]^=1;
    }
    if(a>r || b<l) return ;
    if(l>=a && r<=b){
        seg[now]=arr[r]-arr[l-1]-seg[now];
        if(l!=r) lz[now*2]^=1,lz[now*2+1]^=1;
        // printf("%d\n",seg[now]);
        return ;
    }
    int mid=(l+r)>>1;
    upd(l,mid,a,b,now*2);
    upd(mid+1,r,a,b,now*2+1);
    seg[now]=seg[now*2]+seg[now*2+1];
    // printf("%d\n",seg[now]);
    return ;
}
int main(){
    int l,n,sum=0;
    scanf("%d %d",&l,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        qu[i]=arr[i];
    }
    arr[n+1]=l;
    sort(arr+1,arr+1+n+1);
    for(int i=1;i<=n+1;i++){
        mp[arr[i]]=i;
        gr[i]=arr[i]-arr[i-1];
    }
    build(1,n+1,1);
    ans.push(seg[1]);
    for(int i=n;i>1;i--){
        upd(1,n+1,mp[qu[i]]+1,n+1,1);
        ans.push(seg[1]);
    }
    while(!ans.empty()){
        printf("%d\n",ans.top());
        ans.pop();
    }
    return 0;
}