/*
    TASK:RT_Zombie
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator<(const A&o)const{
    return w>o.w;
    }
};
int a[1010][1010],dis[1010][1010],di[]={1,-1,0,0},dj[]={0,0,1,-1};
priority_queue< A >h;
int main(){
    int r,c,k,i,j,ii,jj,ww,iii,jjj,kk;
    scanf("%d %d %d",&r,&c,&k);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            dis[i][j]=1<<30;
        }
    }
    for(i=1;i<k;i++){
        h.push({i,1,a[i][1]});
        dis[i][1]=a[i][1];
    }
    while(!h.empty()){
        ii=h.top().i;
        jj=h.top().j;
        ww=h.top().w;
        h.pop();
        if(jj==1 && ii>k){
            printf("%d\n",ww);
            return 0;
        }
        for(kk=0;kk<4;kk++){
        iii=ii+di[kk];
        jjj=jj+dj[kk];
        if(iii<1 || jjj<1 || iii>r || jjj>c)continue;
        if(ww+a[iii][jjj]>=dis[iii][jjj])continue;
        if(iii==k && jjj==1)continue;
        dis[iii][jjj]=ww+a[iii][jjj];
        h.push({iii,jjj,dis[iii][jjj]});
        }
    }
}
/*
5 5 3
999 999 999 999 999
1 1 999 999 999
999 1 1 1 999
999 4 1 2 999
1 1 1 1 1

5 5 3
282 23 14 172 587
361 924 9 11 545
638 69 333 1 256
442 641 860 79 638
54 66 18 67 729
*/
