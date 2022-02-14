/*
    TASK: o62_oct_c2_customers
    LANG: CPP
    AUTHOR: WasreK
    ALGO: SQUARE DECOMPOSITION
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
#define SQ 490 //sum(mumbers)<=240000
int now[120010],val[120010];
vector<int> shop[120010],custo[120010];
bool ch[120010];
int main()
{
    int n,m,q,k,num;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&num);
            if(k<=490){
                ch[i]=1;
                shop[i].push_back(num);
            }else{
                custo[num].push_back(i);
            }
        }
    }
    int t,x,y,z,dis,ans;
    while(q--){
        scanf("%d",&t);
        if(t==1){
            scanf("%d %d",&x,&y);
            dis=y-now[x];
            if(ch[x]){
                for(auto i:shop[x]){
                    val[i]+=dis;
                }
            }
            now[x]=y;
        }else{
            scanf("%d",&z);
            ans=val[z];
            for(auto i:custo[z]){
                ans+=now[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}