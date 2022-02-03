/*
    TASK:\
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e;
    bool operator <(const A&o) const{
    if(s!=o.s)return s<o.s;
    else return e>o.e;
    }
};
A a[100100];
int main(){
    int q,n,t,i,v,maxx,st,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&t);
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].s,&v),a[i].e=a[i].s+v*t;
        sort(a,a+n);
        maxx=-1,st=-1,ans=0;
        for(i=0;i<n;i++){
            if(a[i].e<maxx || a[i].e==maxx && a[i].s>st)continue;
            ans++;
            maxx=a[i].e,st=a[i].s;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
5 2
0 10
0 5
10 5
8 8
9 7
*/
