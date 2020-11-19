/*
    TASK:Destroy Bottle
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,v;
    bool operator<(const A & o) const{
        return v<o.v;
    }
};
int ma[100010];
priority_queue< A > h;
int main()
{
    int n,m,now;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        h.push({i,now});
        ma[i]=m+1;
    }
    int ans=0;
    ma[0]=ma[n+1]=0;
    for(int q=1;q<=m;q++){
        ans=0;
        scanf("%d",&now);
        while(!h.empty()){
            // printf("-- %d\n",h.top().i);
            if(h.top().v<=now){
                break;
            }else{
                if(ma[h.top().i]<q){
                    h.pop();
                    continue;
                }
                // printf(" - %d - \n",h.top().i);
                if(ma[h.top().i+1]>q)ans++,ma[h.top().i+1]=q;
                if(ma[h.top().i-1]>q)ans++,ma[h.top().i-1]=q;
                if(ma[h.top().i]>q)ans++,ma[h.top().i]=q;
                h.pop();
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}