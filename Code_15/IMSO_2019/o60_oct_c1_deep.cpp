/*
    TASK:Deep
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
};
A ar[200100];
int l,s,a,b;
int dir(){
    int res = ((s&8)>>3);
    s = (s*a+b)%40507;
    return res;
}
int tra(int lvl,int now){
    if(lvl==l || (ar[now].l==-1 && ar[now].r==-1)){
        return now;
    }else
    if(ar[now].l==-1){
        tra(lvl+1,ar[now].r);
    }else
    if(ar[now].r==-1){
        tra(lvl+1,ar[now].l);
    }else{
        int d=dir();
        if(d==0){
            tra(lvl+1,ar[now].l);
        }else{
        tra(lvl+1,ar[now].r);
        }
    }
}
int main()
{
    int n,q,i,j,ans;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d %d",&ar[i].l,&ar[i].r);
    }
    while(q--){
        scanf("%d %d %d %d",&l,&s,&a,&b);
        ans=tra(0,0);
        printf("%d\n",ans);
    }
    return 0;
}