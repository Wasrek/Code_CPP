/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
};
queue< A > q;
int a[150][150],ma[150][150][2600],di[]={-1,-1,0,0,1,1},dj[]={-1,0,-1,1,-1,0},dj2[]={0,1,-1,1,0,1};
int main()
{
    int n,m,ti,tj,tw,ii,jj;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    // printf("%d\n",int(ceil(n/2.00)));
    if(a[int(ceil(n/2.00))-1][1]!=0) q.push({int(ceil(n/2.00))-1,1,1});
    if(a[int(ceil(n/2.00))][1]!=0) q.push({int(ceil(n/2.00)),1,1});
    if(a[int(ceil(n/2.00))+1][1]!=0) q.push({int(ceil(n/2.00))+1,1,1});
    while(!q.empty()){
        ti=q.front().i;
        tj=q.front().j;
        tw=q.front().w;
        q.pop();
        // printf("%d %d %d\n",ti,tj,tw);
        if(ti==int(ceil(n/2.00)) && tj==m){
            printf("%d\n",tw);
            return 0;
        }
        for(int i=0;i<6;i++){
            ii=ti+di[i];
            if(ti%2) jj=tj+dj2[i];
            else jj=tj+dj[i];
            if(ii<1 || ii>n || jj<1 || jj>m) continue;
            if(a[ii][jj]==0) continue;
            if((tw+1)%a[ii][jj]!=0) continue;
            if(ma[ii][jj][(tw+1)%2520])continue;
            ma[ii][jj][(tw+1)%2520]=1;
            q.push({ii,jj,tw+1});
        }
    }

    return 0;
}
/*
5 4
1 1 3 8
0 1 1 0
1 6 5 7
1 3 2 3  
2 5 2 0 
*/