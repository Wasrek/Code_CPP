/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int c[100100];
vector< int > g[100100];
int main()
{
    int q,n,u,v,ch=0;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            c[u]++;
            c[v]++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ch=0;
        for(int i=1;i<=n;i++){
            if(c[i]==1){
                ch=0;
                for(auto x:g[g[i][0]]){
                    if(c[x]==1) ch++;
                }
                if(ch>=2){
                    printf("SAFE\n");
                    goto here;
                }
            }
        }
        printf("UNSAFE\n");
        here:;
        for(int i=1;i<=n;i++){
            g[i].clear();
            c[i]=0;
        }
    }
    return 0;
}