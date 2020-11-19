/*
    TASK:Bie's Wedding
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,w;
};
struct B
{
    int i,j,w;
    bool operator < (const B&o) const
    {
        if(w!=o.w)
            return w>o.w;
        return j>o.j;
    }
};
priority_queue<B> h;
vector<A> v[130];
int mark[128];
int main()
{
    int n,we;
    char a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf(" %c %c %d",&a,&b,&we);
        v[a].push_back({b,we});
        v[b].push_back({a,we});
    }
    h.push({'Z','Z',0});
    int i,j,nw,ans=1e9,cha;
    while(!h.empty()){
        j=h.top().j;
        mark[j]=1;
        nw=h.top().w;
        h.pop();
        if(j<'Z' && nw<ans){
            ans=nw,cha=j;
        }
        for(i=0;i<v[j].size();i++){
            if(mark[v[j][i].i]==0)
            h.push({j,v[j][i].i,v[j][i].w+nw});
        }
    }
    printf("%c %d",cha,ans);
}
/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/
