/*
    TASK:Peatt Pacman
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,ty,t;
    bool operator <(const A & o) const{
        return t<o.t;
    }
};
struct B{
    int i,j,ty,t;
    bool operator <(const B & o) const{
        if(t!=o.t)return t>o.t;
        return ty<o.ty;
    }
};
priority_queue< B >q;
char s[710][710];
A a[60010];
int mark[710][710],dis[710][710],di[]={-1,1,0,0},dj[]={0,0,-1,1};
int main()
{
    int Q,r,c,n,t,pi,pj,u,v,cou,now,ni,nj,pt;  
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d %d %d %d %d",&r,&c,&n,&t,&pi,&pj);
        pi++,pj++;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].t,&a[i].i,&a[i].j);
            a[i].i++;
            a[i].j++;
        }
        for(int i=1;i<=r;i++){
            scanf(" %s",s[i]+1);
            for(int j=1;j<=c;j++){
                mark[i][j]=2e9;
                dis[i][j]=2e9;
            }
        }
        if(s[pi][pj]=='#'){
            printf("NO -1\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            // printf("%d %d %d\n",a[i].i,a[i].j,a[i].t);
            if(s[a[i].i][a[i].j]=='#') continue;
            if(a[i].t==0){
            mark[a[i].i][a[i].j]=0;
            }
            q.push({a[i].i,a[i].j,2,a[i].t});
        }
        q.push({pi,pj,1,0});
        dis[pi][pj]=0;
        cou=1;
        now=0;
        int ti;
        // printf("%d\n",t);
        while(!q.empty() && q.top().t<=t){
            int i=q.top().i;
            int j=q.top().j;
            int ty=q.top().ty;
            ti=q.top().t;
            q.pop();
            // printf("- %d %d %d %d %d %d\n",i,j,ty,ti,cou,mark[i][j]);
            if(mark[i][j]<=ti && ty==1){
                // printf("here %d %d\n",mark[i][j],ti);
                cou--;
                goto check;
            }
            for(int k=0;k<4;k++){
                ni=i+di[k];
                nj=j+dj[k];
                // printf("%d %d\n",ni,nj);
                // printf("bar\n");
                if(ni<1 || ni>r || nj<1 || nj>c) continue;
                // printf("wall\n");
                if(s[ni][nj]=='#') continue;
                // printf("mark\n");
                if(mark[ni][nj]<ti)continue;
                if(ty==1){
                    if(dis[ni][nj]<=ti)continue;
                    // printf("-- %d %d %c\n",ni,nj,s[ni][nj]);
                    dis[ni][nj]=ti+1;
                    cou++;
                    q.push({ni,nj,1,ti+1});
                } else if(ty==2){
                    // printf("--- %d %d\n",ni,nj);
                    if(dis[ni][nj]<=ti){
                        cou--;
                    }
                    mark[ni][nj]=ti+1;
                    q.push({ni,nj,2,ti+1});
                }
            }
            check:;
            // printf("%d\n",cou);
            if(cou<=0){
                printf("NO %d\n",ti-1);
                goto jump;
            }
        }
        printf("YES\n");
            jump:;
        while(!q.empty())q.pop();
    }
    return 0;
}