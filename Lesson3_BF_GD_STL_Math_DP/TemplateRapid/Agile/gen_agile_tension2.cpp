/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
*/
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
long long ran(long long l, long long r)
{
    // return l + (rand() % (r - l + 1));
    return rnd.next(l,r);
}
long long node;
long long q,minN,maxN,minM,maxM,minL,maxL,minG,maxG,ch;
long long N,M,L,G;
vector<long long> a;
vector<pair<int,int>> eg;
vector<pair<long long,long long>> vab;
vector< long long > grval,ga,gb,ql;
void get_group(long long n,long long le){
    if(le==0) return ;
    if(le==1){
        a.push_back(n);
        return ;    
    }
    if(n<(le*2)) n+=(le*4),N+=(le*4);
    long long now=ran(2,n/le);
    a.push_back(now);
    get_group(n-now,le-1);
}
void gen_edge(int st,int sz,int gm){
    // printf("%d %d %d\n",st,sz,gm);
    for(int i=st+1;i<st+sz;i++){
        eg.push_back({i,ran(st,i-1)});
    }
    for(int i=1;i<=gm;i++){
        eg.push_back({ran(st,sz+st-1),ran(st,sz+st-1)});
    }
    return ;
}
void gen_val(int gri){
    long long va,vb;
    ga.clear();gb.clear();
    for(int i=1;i<=a[gri];i++){
        va=ran(0,1000000);
        vb=ran(0,1000000);
        if(gri%2){
            if(i%3==0 && va>vb) swap(va,vb);
            else if(va<vb) swap(va,vb);
        } else{
            if(i%3==0 && va<vb) swap(va,vb);
            else if(va>vb) swap(va,vb);
        }
        // printf("%d %d %lld %lld\n",gri,i,va,vb);
        vab.push_back({va,vb});
        ga.push_back(va);
        gb.push_back(vb);
    }
    sort(ga.begin(),ga.end(),greater<long long>());
    sort(gb.begin(),gb.end());
    long long gv=0;
    for(int i=0;i<ga.size();i++){
        if(ga[i]<gb[i]) break;
        gv+=ga[i]-gb[i];
    }
    grval.push_back(gv);
}
int main(int argc,char* argv[])
{
    // srand(time(0));
    int cnt=0;
    q = atoi(argv[++cnt]);
	minN = atoi(argv[++cnt]);
	maxN = atoi(argv[++cnt]);
	minM = atoi(argv[++cnt]);
	maxM = atoi(argv[++cnt]);
	minG = atoi(argv[++cnt]);
	maxG = atoi(argv[++cnt]);
	ch = atoi(argv[++cnt]);
    // scanf("%lld %lld %lld %lld %lld %lld %lld %d",&q,&minN,&maxN,&minM,&maxM,&minG,&maxG,&ch);
    N=ran(minN,maxN); M=ran(minM,maxM); L=ran(minL,maxL); G=ran(minG,maxG);
    node=N;
    get_group(N,G);
    int nowm,now;
    now=1;
    for(int i=0;i<a.size();i++){
        if(i!=a.size()-1){
            nowm=ran(0,M/(a.size()-i));
            M-=nowm;
        }else nowm=M;
        gen_edge(now,a[i],nowm);
        now+=a[i];
        gen_val(i);
    }
    sort(grval.begin(),grval.end());
    if(!ch){
        for(auto x:grval){
            ql.push_back(max(0ll,x-1));
            ql.push_back(x+1);
        }
        long long diff=grval[grval.size()-1]+1000-max(grval[0]-1000,0ll),lef=q-ql.size();
        diff/=lef;
        diff=max(1ll,diff);
        for(int i=1;i<=lef;i++){
            ql.push_back(max(grval[0]-1000,0ll)+diff*(i-1));
            // ql.push_back(ran(grval[0],grval[grval.size()-1]));
        }
    }else if(ch==4){
        ql.push_back(max(0ll,grval[0]-1));
        ql.push_back(grval[grval.size()-1]+1);
        long long diff=grval[grval.size()-1]+1000-max(grval[0]-1000,0ll),lef=q-ql.size();
        diff/=lef;
        diff=max(1ll,diff);
        for(int i=1;i<=lef;i++){
            ql.push_back(max(grval[0]-1000,0ll)+diff*(i-1));
            // ql.push_back(ran(grval[0],grval[grval.size()-1]));
        }
    }else if(ch==1){
        for(int i=1;i<=q;i++)
            ql.push_back(1000000000000);
    }else{
        for(int i=1;i<=q/2;i++){
            ql.push_back(1000000000000);
            ql.push_back(0);
        }
    }
    printf("%lld %d %d\n",N,eg.size(),ql.size());
    // for(auto x:a){
    //     printf("%lld ",x);
    // }
    // printf("\n");
    for(auto x:vab){
        printf("%lld %lld\n",x.first,x.second);
    }
    for(auto x:eg){
        printf("%d %d\n",x.first,x.second);
    }
    for(auto x:ql){
        printf("%lld\n",x);
    }
    return 0;
}
/*
gen 9800 300000 300000 700000 700000 1 1 0 > 1
gen 9800 300000 300000 700000 700000 1 1 0 > 2
gen 9800 300000 300000 700000 700000 100 1000 1 > 3
gen 9800 300000 300000 700000 700000 100 1000 2 > 4
gen 9800 300000 300000 700000 700000 100 1000 2 > 5
gen 9800 300000 300000 700000 700000 100 1000 0 > 6
gen 9800 300000 300000 700000 700000 100 1000 0 > 7
gen 9800 300000 300000 700000 700000 100 1000 0 > 8
gen 9800 300000 300000 700000 700000 100 1000 0 > 9
gen 9800 300000 300000 700000 700000 100 1000 0 > 10
*/