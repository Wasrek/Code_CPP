/*
    TASK: 120J Minimum Sum - CF
    LANG: CPP
    AUTHOR: WasreK
    ALGO: Closest Pair - Sweep Line 
    TYPE: BATCH
    SCORE: 100
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
pii pts[100010],ori[100010];
int ty[100010];//++ -+ +- --
set<pii> s;
void findk(int t,int opr){
    if(opr==1){
        printf("%d ",t);
        return ;
    }
    if(t==1){
        printf("4 "); return ;
    }else if(t==2){
        printf("3 "); return ;
    }else if(t==3){
        printf("2 "); return ;
    }else if(t==4){
        printf("1 "); return ;
    }
    return;

}
int main()
{
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n,x,y,pt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&pts[i].x,&pts[i].y);
        if(pts[i].x>=0 && pts[i].y>=0){
            ty[i]=1;
        }else if(pts[i].x<0 && pts[i].y>=0){
            ty[i]=2;
        }else if(pts[i].x>=0 && pts[i].y<0){
            ty[i]=3;
        }else{
            ty[i]=4;
        }
        pts[i].x=abs(pts[i].x);
        pts[i].y=abs(pts[i].y);
        ori[i]=pts[i];
    }
    sort(pts+1,pts+n+1);
    pt=1;
    int dx,dy,d;
    pii ansa,ansb;
    long long dis=2e9;
    for(int i=1;i<=n;i++){
        d=ceil(sqrt(dis));
        //pop front -> x
        while(pt<i && abs(pts[i].x-pts[pt].x)>=d){
            s.erase({pts[pt].y,pts[pt].x});
            pt++;
        }
        //find y that you interest
        auto lb=s.lower_bound({pts[i].y-d,pts[i].x});
        auto ub=s.upper_bound({pts[i].y+d,pts[i].x});
        for(auto it=lb;it!=ub;it++){
            dx=abs(pts[i].x-it->y);
            dy=abs(pts[i].y-it->x);
            if(1LL*dx*dx+1LL*dy*dy<dis){
                dis=1LL*dx*dx+1LL*dy*dy;
                ansa={it->y,it->x};
                ansb=pts[i];
            }
        }
        s.insert({pts[i].y,pts[i].x});
    }
    int ch=0;
    for(int i=1;i<=n;i++){
        if(ch==3) return 0;
        if(ansa==ori[i] && !(ch&(1<<0))){
            printf("%d ",i);
            findk(ty[i],1);
            ch|=(1<<0);
            continue;
        }
        if(ansb==ori[i] && !(ch&(1<<1))){
            printf("%d ",i);
            findk(ty[i],-1);
            ch|=(1<<1);
        }
    }
    return 0;
}