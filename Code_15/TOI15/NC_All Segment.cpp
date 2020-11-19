/*
    TASK:NC_All Segment
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,va;
    bool operator<(const A&o)const{
        return id<o.id;
    }
};
A event[200010];
int main(){
    int n,i,s,e,ma=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&s,&e);
        event[i*2+1]={s,1};
        event[i*2+2]={e+1,-1};
    }
    int v=0;
    sort(event+1,event+2*n+1);
    for(i=1;i<=2*n;i++){
        v+=event[i].va;
        if(event[i].id!=event[i+1].id)
        ma=max(ma,v);
    }
    printf("%d\n",ma);
    return 0;
}
