/*
    TASK: Q_Dwarf
    LANG: CPP
    AUTHOR: Kers
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int pos[200005],h[200005],MA[800005],MI[800005];
void build(int l,int r,int now){
    if(l==r){ // is leaf
        MA[now]=MI[now]=pos[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2); build(mid+1,r,now*2+1);
    MA[now] = max(MA[now*2],MA[now*2+1]);
    MI[now] = min(MI[now*2],MI[now*2+1]);
}
void update(int l,int r,int now,int idx,int w){
    if(l==r&&r==idx){ // is leaf
        MA[now]=MI[now]=w;
        return ;
    }
    if(l>idx || r<idx) return ;
    int mid=(l+r)>>1;
    update(l,mid,now*2,idx,w); update(mid+1,r,now*2+1,idx,w);
    MA[now] = max(MA[now*2],MA[now*2+1]);
    MI[now] = min(MI[now*2],MI[now*2+1]);
}
int queryMA(int l,int r,int now,int ll,int rr){
    if(l>rr || r<ll) return -1<<30;
    if(l>=ll && r<=rr) return MA[now];
    int mid=(l+r)>>1;
    return max( queryMA(l,mid,now*2,ll,rr) , queryMA(mid+1,r,now*2+1,ll,rr) );
}
int queryMI(int l,int r,int now,int ll,int rr){
    if(l>rr || r<ll) return 1<<30;
    if(l>=ll && r<=rr) return MI[now];
    int mid=(l+r)>>1;
    return min( queryMI(l,mid,now*2,ll,rr) , queryMI(mid+1,r,now*2+1,ll,rr) );
}
int main()
{
    int n,q,i,cmd,a,b;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){
        scanf(" %d",&h[i]);
        update(1,n,1,h[i],i);
        pos[ h[i] ] =i;
	}
//	build(1,n,1);
	while(q--){
        scanf(" %d %d %d",&cmd,&a,&b);
        if(cmd==1){
            update(1,n,1,h[a],b); update(1,n,1,h[b],a);
            swap(h[a],h[b]);
//        swap(pos[h[a]],pos[h[b]]);

        }else{
            int len=queryMA(1,n,1,a,b)-queryMI(1,n,1,a,b);
            printf((len==b-a)?"YES\n":"NO\n");
        }
	}
    return 0;
}
/*
7 7 4 7 3 5 1 2 6 2 1 7 1 3 7 2 4 6 2 4 7 2 1 4 1 1 4
2 1 4
*/
