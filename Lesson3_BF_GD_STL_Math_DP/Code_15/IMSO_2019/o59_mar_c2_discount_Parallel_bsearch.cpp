/*
    TASK:Discount
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A&o) const {
        return w<o.w;
    }
};
A  a[50100];
int p[20100],l[50100],r[50100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
vector<A> use,nn;
vector<int>q[20100];
int main()
{
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)p[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    sort(a+1,a+1+m);
    // cout<<endl;
    for(int i=1;i<=m;i++){
        x=a[i].u;
        x=fin(x);
        y=a[i].v;
        y=fin(y);
        if(x!=y){
            p[x]=y;
            // cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<endl;
            use.push_back(a[i]);
        }else{
            nn.push_back(a[i]);
        }
    }
    int us=use.size(),ns=nn.size();
    for(int i=0;i<ns;i++)r[i]=us-1;
    int ch=1,mid;
    while(ch){
        ch=0;
        for(int i=0;i<ns;i++){
            if(l[i]==r[i])continue;
            ch=1;
            mid=(l[i]+r[i])>>1;
            q[mid].push_back(i);
        }
        for(int i=0;i<n;i++)p[i]=i;
        for(int i=0;i<us;i++){
            x=use[i].u;
            y=use[i].v;
            x=fin(x),y=fin(y);
            p[x]=y;
            for(int j=0;j<q[i].size();j++){
                x=nn[q[i][j]].u;
                y=nn[q[i][j]].v;
                x=fin(x),y=fin(y);
                if(x==y){
                    r[q[i][j]]=i;
                }else {
                    l[q[i][j]]=i+1;
                }
            }
            q[i].clear();
        }
    }
    int ans=1e9;
    // cout<<endl;
    for(int i=0;i<ns;i++){
        // printf("%d %d %d\n",nn[i].u,nn[i].v,nn[i].w);
        ans=min(ans,nn[i].w-use[l[i]].w);
    }
    printf("%d\n",ans+1);
    return 0;
}
