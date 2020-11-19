/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long ti,mp,ty,hl,da;
    bool operator<(const A & o) const {
        if(mp!=o.mp) return mp<o.mp;
        else return da>o.da;
    }
};
priority_queue < A > h;
int main()
{
    int k,m,ha,tim,u;
    char opr,ty;
    A now;
    long long ans=0,have=0;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf(" %c",&opr);
        if(opr == 'c'){
            have++;
            scanf(" %c",&ty);
            if(ty=='n'){
                scanf("%d",&m);
                h.push({i,m,1,0,i});
            }else{
                scanf("%d %d",&m,&ha);
                h.push({i,m,2,ha,i});
            }
        }else{
            while(!h.empty()){
            if(h.top().mp==0){
                h.pop();
                have--;
                continue;
            }
            if(h.top().ty==1){
                ans+=h.top().mp;
                // cout << ans<<endl;
                have--;
                h.pop();
                break;
            }else{
                if(i-h.top().ti<h.top().hl){
                    ans+=h.top().mp;
                    // cout << ans<< endl;
                    have--;
                    h.pop();
                    break;
                }else{
                    // tim=(i-h.top().ti)/h.top().hl;
                    // // cout << tim << endl;
                    now=h.top();
                    h.pop();
                    // u=(int)(log2((double)now.mp));
                    // if(tim>u+1){
                    //     have--;continue;
                    // }
                    // now.mp/=(1<<tim);
                    // cout << now.mp << endl;
                    now.mp/=2;
                    if(now.mp<1){have--;continue;}
                    else{
                        now.ti+=(now.hl);
                        h.push(now);
                    }
                }
            }
            }
        }
    }
    while(!h.empty()){
        if(h.top().ty == 1){
            if(h.top().mp==0) have--;
            h.pop();
            continue;
        }else{
            if(k-h.top().ti< h.top().hl){
                h.pop();
                continue;
            }else{
                now=h.top();
                h.pop();
                now.mp/=2;
                if(now.mp<1){have--;}
                else{
                    now.ti+=(now.hl);
                    h.push(now);
                }
            }
        }
    }
    printf("%lld\n%lld\n",ans,have);
    return 0;
}