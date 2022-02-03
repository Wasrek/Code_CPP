/*
    TASK:RT_Tsunami
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
int a[1010][1010],dis[1010][1010],di[]={1,-1,0,0},dj[]={0,0,-1,1};
queue< A >q;
vector<A>g[2100];
priority_queue< int > h;
int main(){
    int n,i,j,ii,jj,k,iii,jjj,d;
    A p;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    d=(n*2)-2;
    q.push({1,1});
    while(!q.empty()){
        ii=q.front().i;
        jj=q.front().j;
        q.pop();
        for(k=0;k<4;k++){
            iii=ii+di[k];
            jjj=jj+dj[k];
            if(iii==1 && jjj==1)continue;
            if(dis[iii][jjj])continue;
            if(iii<1 || jjj<1 || iii>n || jjj>n)continue;
            dis[iii][jjj]=dis[ii][jj]+1;
            p.i=iii;
            p.j=jjj;
            g[dis[iii][jjj]].push_back(p);
            q.push({iii,jjj});
        }
    }
    /*
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }*/
    int sum=0;
    while(d>0){
        for(auto x:g[d]){
            h.push(a[x.i][x.j]);
        }
        if(!h.empty()){
            sum+=h.top();
            h.pop();
            //printf("%d\n",sum);
        }
        d--;
    }
    printf("%d\n",sum);
    return 0;
}
