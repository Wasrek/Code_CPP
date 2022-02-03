/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j,ma;
    bool operator < (const A & o) const{
        return ma>o.ma;
    }
};
long long a[1010][1010],ma[1010][1010],di[]={1,-1,0,0},dj[]={0,0,1,-1};
priority_queue< A > h;
int main()
{
    long long n,si=0,sj,ei,ej;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
            if(!a[i][j] && !si) si=i,sj=j;
            if(!a[i][j] && si) ei=i,ej=j;
            ma[i][j]=1<<30;
        }
    }
    long long i,j,ii,jj,maxx;
    h.push({si,sj,0});
    ma[si][sj]=0;
    while(!h.empty()){
        i=h.top().i;
        j=h.top().j;
        maxx=h.top().ma;
        h.pop();
        // printf("%lld %lld %lld\n",i,j,maxx);
        if(i==ei && j==ej){
            printf("%lld\n",maxx);
            return 0;
        }
        for(int k=0;k<4;k++){
            ii=i+di[k];
            jj=j+dj[k];
            if(ii<1 || ii>n || jj<1 || jj>n || (ii==si && jj==sj)) continue;
            if(max(maxx,a[ii][jj])>=ma[ii][jj]) continue;
            ma[ii][jj]=max(maxx,a[ii][jj]);
            h.push({ii,jj,ma[ii][jj]});
        }
    }

    return 0;
}
/*
3
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