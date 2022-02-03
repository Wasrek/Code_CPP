/*
    TASK:AP_Road Build
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int p[300010],f[250010][2],h[250010][2];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int q,v,e,m,a,b,l,r;
    scanf("%d",&q);
    for(int j=1;j<=q;j++){
        scanf("%d %d %d",&v,&e,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&f[i][0],&f[i][1]);
        }
        for(int i=1;i<=e;i++){
            scanf("%d %d",&h[i][0],&h[i][1]);
        }
        l=0,r=e+1;
        while(l<r){
            int mid=(l+r)/2,ch=0;
            for(int i=1;i<=v;i++){
            p[i]=i;
            }
            for(int i=1;i<=mid;i++){
                p[fin(h[i][0])]=fin(h[i][1]);
            }
            for(int i=1;i<=m;i++){
                if(fin(f[i][0]) != fin(f[i][1])){
                    ch=1;
                }
            }
            if(ch){
                l=mid+1;
            }else r=mid;
        }
        // printf("%d %d",l,r);
        printf("C#%d: ",j);
        if(l<=e) printf("%d\n",l);
        else
        printf("-1\n");
    }
    return 0;
}