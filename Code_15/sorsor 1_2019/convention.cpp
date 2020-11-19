/*
    TASK:convention
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100010
int arr[200100],ch=0;
int aa[200100],bb[200100];
int seg[4*N],lazy[4*N];
unordered_map<int,int>mp,re;
void update(int l,int r,int a,int b,int now){
    if(lazy[now]){
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        seg[now]+=lazy[now];
        lazy[now]=0;
    }
    if(l>b || r<a) return ;
    if(l>=a && r<=b){
        if(l!=r){
        lazy[now*2]++;
        lazy[now*2+1]++;
        }
        seg[now]++;
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,now*2);
    update(mid+1,r,a,b,now*2+1);
    seg[now]=max(seg[now*2],seg[now*2+1]);
}
int query(int l,int r,int a,int b,int now){
    if(lazy[now]){
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        seg[now]+=lazy[now];
        lazy[now]=0;
    }
    if(l>b || r<a) return -1e9;
    if(a<=l && r<=b) return seg[now];
    int mid=(l+r)>>1;
    int ll=query(l,mid,a,b,now*2);
    int rr=query(mid+1,r,a,b,now*2+1);
    return max(ll,rr);
}
int main()
{
    int n,m,a,b,cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&aa[i],&bb[i]);
        arr[i*2]=aa[i];
        arr[i*2+1]=bb[i];
    }
    sort(arr+1,arr+2+n*2);
    for(int i=1;i<=n*2+1;i++){
        if(arr[i]==arr[i-1])continue;
        mp[arr[i]]=++cnt;
        re[cnt]=mp[arr[i]];
    }
    for(int i=1;i<=n;i++){
        if(query(1,cnt,mp[aa[i]],mp[bb[i]],1)>=m){printf("no\n");continue;}
        printf("yes\n");
        update(1,cnt,mp[aa[i]],mp[bb[i]],1);
    }
    return 0;
}
