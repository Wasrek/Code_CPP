/*
    TASK:RC_Circuit Board
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator<(const A& o)const{
        if(a!=o.a)return a<o.a;
    }
};
A ar[100100];
int lis[100100];
int main(){
    int n,i,a,b,ub;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&ar[i].a,&ar[i].b);
    }
    sort(ar+1,ar+1+n);
    int cnt=0;
    for(i=1;i<=n;i++){
        ar[i].b*=-1;
        ub=upper_bound(lis,lis+cnt,ar[i].b)-lis;
        if(ub==cnt)cnt++;
        lis[ub]=ar[i].b;
    }
    printf("%d\n",cnt);
}
