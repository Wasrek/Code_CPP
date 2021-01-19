/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int fw[50100],a[50100];
map<int,int> la,ans;
struct A{
    int l,i;
};
vector< A > qu[50100];
void upd(int u,int v){
    for(int i=u;i<50100;i+=(i&-i)) fw[i]+=v;
}
int que(int u){
    int now=0;
    for(int i=u;i>0;i-=(i&-i)) now+=fw[i];
    return now;
}
int main()
{
    int n,q,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        l++,r++;
        qu[r].push_back({l,i});
    }
    for(int i=1;i<=n;i++){
        if(la[a[i]])upd(la[a[i]],-1);
        la[a[i]]=i;
        upd(i,1);
        for(auto x: qu[i]){
            ans[x.i]=(i-x.l+1)-(que(i)-que(x.l-1));
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}