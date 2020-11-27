/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,ma,cl,now;
};
char a[220][220];
int mag[220][220],di[]={-1,1,0,0,0},dj[]={0,0,1,-1,0},dis[220][220][1<<7][7];
queue< A > h;
int main()
{
    int n,m,now=0,si,sj,ti,tj,ni,nj,tw,ma,cl;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(int j=1;j<=m;j++){
            if(a[i][j]=='G')mag[i][j]=(1<<(now++));
            if(a[i][j]=='S') si=i,sj=j;
            if(a[i][j]=='6') a[i][j]='0';
        }
    }
    dis[si][sj][0][1]=1;
    h.push({si,sj,0,0,1,0});
    while(!h.empty()){
        ti=h.front().i;
        tj=h.front().j;
        tw=h.front().w;
        ma=h.front().ma;
        cl=h.front().cl;
        now=h.front().now;
        h.pop();
        if(now==7){
            printf("%d\n",tw);
            return 0;
        }
        for(int k=0;k<5;k++){
            ni=ti+di[k];
            nj=tj+dj[k];
            if(ni<1 || ni>n || nj<1 || nj>m) continue;
            if(a[ni][nj]=='#') continue;
            if(dis[ni][nj][ma|mag[ni][nj]][(cl+1)%6]) continue;
            if(a[ni][nj]>='0' && a[ni][nj]<='5'){
                if(a[ni][nj]!='0' && (cl+1)%6!=a[ni][nj]-'0' && now<a[ni][nj]-'0') continue; 
                if(a[ni][nj]=='0' && (cl+1)%6!=a[ni][nj]-'0' && now<6) continue; 
            }
            dis[ni][nj][ma|mag[ni][nj]][(cl+1)%6] = 1;
            if(!(ma & mag[ni][nj]) && mag[ni][nj]) h.push({ni,nj,tw+1,ma|mag[ni][nj],(cl+1)%6,now+1});
            else h.push({ni,nj,tw+1,ma|mag[ni][nj],(cl+1)%6,now});
        }
    }
    printf("-1\n");
    return 0;
}
/*
2 6
S##GGG
.6GGGG

2 7
S11GGGG
111#GGG
*/