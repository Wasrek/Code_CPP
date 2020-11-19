/*
    TASK:AP_Road Build
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
PII want[300100],edge[300100];
int p[300100];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main(){
    int q,i,l,r,mid,v,e,m,j,ch;
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d %d %d",&v,&e,&m);
        for(j=1;j<=m;j++){
            scanf("%d %d",&want[j].first,&want[j].second);
        }
        for(j=1;j<=e;j++){
            scanf("%d %d",&edge[j].first,&edge[j].second);
        }
        l=1;r=e+1;
        while(l<r){
            mid=(l+r)/2;
            for(j=1;j<=v;j++) p[j]=j;
            for(j=1;j<=mid;j++) p[fin(edge[j].first)]=fin(edge[j].second);
            for(j=1,ch=1;j<=m;j++){
                if(fin(want[j].first)!=fin(want[j].second)){
                    ch=0;break;
                }
            }
            if(ch) r=mid;
            else l=mid+1;
        }
        printf("C#%d: ",i);
        if(l<=e) printf("%d\n",l);
        else printf("-1\n");
    }
}
