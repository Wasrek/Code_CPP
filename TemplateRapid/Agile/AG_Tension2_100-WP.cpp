/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 300100
struct A{
    long long idx,p;
    bool operator <(const A & o) const{
        return p<o.p;
    }
};
long long a[N],b[N],now,qs[N];
A id[N];
long long p[N];
long long fin(long long i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
vector< long long > ga,gb,gr;
int main()
{
    long long l,q,n,m,u,v,ub;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&a[i],&b[i]);
        id[i]={i,i};
        p[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        p[fin(u)]=fin(p[v]);
    }
    for(int i=1;i<=n;i++) id[i].p=p[i];
    sort(id+1,id+1+n);
    for(int i=1;i<=n;i++){
        // printf(" %lld %lld %lld %lld\n",id[i].idx,fin(id[i].idx),a[id[i].idx],b[id[i].idx]);
        ga.push_back(a[id[i].idx]);
        gb.push_back(b[id[i].idx]);
        if(fin(id[i].idx)!=fin(id[i+1].idx)){
            sort(ga.begin(),ga.end(),greater<long long>());
            sort(gb.begin(),gb.end());
            now=0;
            for(int j=0;j<ga.size();j++){
                if(ga[j]-gb[j]>0){
                    // printf("pl %lld %lld\n",ga[j],gb[j]);
                    now+=ga[j]-gb[j];
                }else{
                    break;
                }
            }
            gr.push_back(now);
            ga.clear();
            gb.clear();
        }
    }
    //gr.push_back(0);
    sort(gr.begin(),gr.end());
    // for(auto x: gr) printf("%lld ",x);
    // printf("\n");
    qs[1]=gr[0];
    for(int i=2;i<=gr.size();i++) qs[i]=qs[i-1]+gr[i-1];
    // for(int i=0;i<=gr.size();i++) cout<< qs[i]<<" ";
    // cout<<endl;
    while(q--){
        scanf("%lld",&l);
        ub=upper_bound(gr.begin(),gr.end(),l)-gr.begin();
        // printf("%d %d\n",ub,gr.size());
        now=qs[gr.size()]-qs[ub]-((gr.size()-ub-1)*l);
        printf("%lld\n",max(gr[gr.size()-1],now));
    }
}
/*
10 8 2
9 7
3 1
2 9
1 1
3 6
2 5
10 1
20 12
10 2
3 1
1 2
2 3
4 5
6 4
6 7
8 9
9 8
8 10
5
9

*/
