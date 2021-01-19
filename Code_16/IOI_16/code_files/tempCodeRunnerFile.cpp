/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b,dif;
    bool operator<(const A & o) const{
        return dif>o.dif;
    }
};
priority_queue< A > h;
int main()
{
    int n,k,q,a,b,ca,cb,ansa,ansb;;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        ansa=ansb=ca=cb=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            if(a<b){
                ca++;
                ansa+=a;
            }else{
                cb++;
                ansb+=b;
            }
            h.push({a,b,abs(a-b)});
        }
        if(abs(ca-cb)<=k){
            printf("%d\n",ansa+ansb);
            while(!h.empty()) h.pop();
            continue;
        }
        if(ca>cb){
            while(ca-cb>k){
                ansa-=h.top().a;
                ansb+=h.top().b;
                ca--;
                cb++;
                h.pop();
            }
        }else{
            while(cb-ca>k){
                ansb-=h.top().b;
                ansa+=h.top().a;
                cb--;
                ca++;
                h.pop();
            }
        }
        while(!h.empty()) h.pop();
        printf("%d\n",ansa+ansb);
    }
    return 0;
}
