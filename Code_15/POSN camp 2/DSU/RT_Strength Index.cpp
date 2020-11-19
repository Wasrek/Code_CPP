/*
    TASK:RT_Strength Index
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
A ar[600000];
int p[1010],a[1010][2];
int fin(int i){
    if(p[i]==i)return i;
    else return p[i]=fin(p[i]);
}
int main(){
    int q,n,k,i,j,cnt,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
            scanf("%d %d",&a[i][0],&a[i][1]),p[i]=i;
        for(i=1,cnt=0;i<=n;i++)
            for(j=i+1;j<=n;j++)
                ar[cnt++]={i,j,abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1])};
        sort(ar,ar+cnt);
        for(i=0;i<cnt;i++){
            u=fin(ar[i].u),v=fin(ar[i].v);
            if(u!=v){
                if(n==k){
                    printf("%d\n",ar[i].w);
                    break;
                }
                n--;
                p[u]=v;
            }
        }
    }
    return 0;
}
