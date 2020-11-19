/*
    TASK:
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > gt[1010];
priority_queue< int > h;
int in[1010],ori[1010],mark[1010];
int main(){
    int n,m,q,a,b,p,u,ch,i;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        gt[b].push_back(a);
        ori[a]++;
    }
    scanf("%d",&q);
    while(q--){
        for(i=1;i<=n;i++){
            in[i]=ori[i];
        }
        memset(mark,0,sizeof mark);
        scanf("%d",&p);
        while(p--){
            scanf("%d",&u);
            in[u]=0;
        }
        for(i=1;i<=n;i++){
            if(in[i]==0){
                 mark[i]=1;
                h.push(i);
            }
        }
        while(!h.empty()){
            u=h.top();
            h.pop();
            for(auto x: gt[u]){
                if(mark[x])continue;
                in[x]--;
                if(in[x]==0){
                    mark[x]=1;
                    h.push(x);
                }
            }
        }
        ch=1;
        for(i=1;i<=n;i++){
            if(!mark[i]){
                printf("%d ",i);
                ch=0;
            }
        }
        if(ch)printf("-1");
        printf("\n");
    }
}
