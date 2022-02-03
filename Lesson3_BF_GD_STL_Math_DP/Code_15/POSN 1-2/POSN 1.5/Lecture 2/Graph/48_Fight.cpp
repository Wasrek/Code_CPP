/*
    TASK:48_Fight
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> r;
r p[300100];
int color[100100];
vector< int >v[100100];
int dfs(int i,int col){
    int j,k;
    if(color[i]!=0 && color[i]!=col)return 0;
    if(color[i]!=0 && color[i]==col)return 1;
    color[i]=col;
    for(k=0;k<v[i].size();k++){
        if(dfs(v[i][k],3-col)==0)
        return 0;
    }
    return 1;
}
int main()
{
    int n,w,a,b,l,r,mid,i,ch;
    scanf("%d %d",&n,&w);
    for(i=1; i<=w; i++)
    {
        scanf("%d %d",&a,&b);
        p[i].first=a;
        p[i].second=b;
    }
    l=1,r=w;
    while(l<r)
    {
        ch=1;
        mid=(l+r)/2;
        memset(color,0,sizeof color);
        for(i=1;i<=mid;i++){
            a=p[i].first;
            b=p[i].second;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1;i<=n;i++){
            if(color[i]==0){
                if(dfs(i,1)==0){
                    ch=0;
                    break;
                }
            }
        }
        for(i=0;i<=n;i++){
            v[i].clear();
        }
        if(ch) l=mid+1;
        else r=mid;
    }
    printf("%d\n",l);


    return 0;
}
/*
6 8
3 4
1 2
5 6
1 6
1 3
4 5
2 4
2 6
*/
