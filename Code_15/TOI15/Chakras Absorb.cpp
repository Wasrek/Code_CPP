/*
    TASK:Chakras Absorb
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,ma;
    bool operator <(const A&o)const{
        return ma>o.ma;
    }
} ;
int a[1010][1010],di[4]={1,-1,0,0},dj[4]={0,0,1,-1},mark[1010][1010];
priority_queue< A >h;
int main(){
    int n,i,j,si,sj,ei,ej,ch=0,ii,jj,im,k,iii,jjj;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0 && ch==0){si=i,sj=j,ch++;continue;}
            if(a[i][j]==0 && ch==1)ei=i,ej=j,ch++;
        }
    }
    h.push({si,sj,a[si][sj]});
    while(!h.empty()){
        ii=h.top().i;
        jj=h.top().j;
        im=h.top().ma;
        h.pop();
        mark[ii][jj]=1;
        if(ii==ei && jj==ej){
            printf("%d\n",im);
            return 0;
        }
        //printf("%d %d %d\n",ii,jj,im);
        for(k=0;k<4;k++){
            iii=ii+di[k];
            jjj=jj+dj[k];
            if(mark[iii][jjj])continue;
            if(iii<1 || iii>n || jjj<1 || jjj>n)continue;
            h.push({iii,jjj,max(im,a[iii][jjj])});
        }
    }
    return 0;
}
/*
3
10 100 10
0 10 100
12 5 03
10 100 10
0 10 100
12 5 0

5
1 1 1 0 1
3 1 1 1 1
0 3 4 3 2
1 1 1 4 1
1 4 2 2 2
*/
