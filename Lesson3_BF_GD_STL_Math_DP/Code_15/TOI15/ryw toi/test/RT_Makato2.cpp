/*
    TASK:RT_Makato2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],xr[100100],all=0,mi=1<<30;
vector<int> g[100100];
int fin(int i,int last){
    int xo=a[i],sum=0;
    for(auto x: g[i]){
        if(x==last)continue;
        xo^=fin(x,i);
        sum+=xr[x];
    }
    sum+=(all^xo);
    mi=min(sum,mi);
    return xr[i]=xo;
}
int main(){
    int n,i,l,x,y,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        all^=a[i];
    }
    l=n-1;
    while(l--){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    xr[1]=fin(1,-1);
    //for(i=1;i<=n;i++)printf("%d\n",xr[i]);
    printf("%d\n",mi);
}
/*
5
7 3 8 5 2
4 3
1 5
3 2
3 1
*/
