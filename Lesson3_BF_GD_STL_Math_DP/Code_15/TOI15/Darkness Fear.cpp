/*
    TASK:Darkness Fear
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,dis;
    bool operator<(const A&o)const {
    return dis>o.dis;
    }
};
struct B{
    int i,j;
};
char a[10010][10010];
int dis[2100][2100],di[4]={0,0,-1,1},dj[4]={1,-1,0,0},ans[2100];
B vil[2100];
priority_queue< A > q;
int main(){
    int n,m,k,t,i,j,ii,kk,iii,d,ei,ej,si,sj,cou=1;
    scanf("%d %d %d",&n,&m,&k);
    //memset(dis,-1,sizeof dis);
    for(i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
            for(j=1;j<=m;j++){
            dis[i][j]=1<<30;
            if(a[i][j]=='A'){
                si=i,sj=j;
            }
            if(a[i][j]=='B'){ei=i,ej=j;}
            if(a[i][j]=='X'){vil[++cou].i=i,vil[cou].j=j;}
        }
    }
    vil[1].i=si;
    vil[1].j=sj;
    vil[++cou].i=ei;
    vil[cou].j=ej;
    for(i=1;i<=cou;i++){
        ans[i]=1<<30;
        for(j=1;j<=cou;j++){
            dis[i][j]=(abs(vil[i].i-vil[j].i)+abs(vil[i].j-vil[j].j));
            //printf("%d ",dis[i][j]);
        }
        //printf("\n");
    }
    q.push({1,0});
    ans[1]=0;
    while(!q.empty()){
        ii=q.top().i;
        d=q.top().dis;
        if(ii==cou)break;
        q.pop();
        for(t=1;t<=cou;t++){
            if(dis[ii][t]>k)continue;
            if(ans[t]>d+dis[ii][t]){
            ans[t]=d+dis[ii][t];
            q.push({t,d+dis[ii][t]});
            }
        }
    }
    //for(i=1;i<=cou;i++)printf("%d\n",ans[i]);
    if(ans[cou]!=1<<30)
    printf("%d\n",ans[cou]);
    else printf("-1\n");
}
/*
4 3 2
X.A
...
X..
.B.

3 3 1
..A
...
..B
*/
