/*
    TASK:FC_Mine
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,n;
};
int a[4][1010][1010],qs[4][1010][1010],r[4][1010][1010],d[4][1010][1010];
deque<A> dq;
int main()
{
    int n,k,i,j,l,ma;
    scanf("%d %d",&n,&k);
    for(l=1; l<=3; l++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&a[l][i][j]);
                a[l][i][j]+=a[l][i-1][j]+a[l][i][j-1]-a[l][i-1][j-1];
                qs[l][i][j]=a[l][i][j];
                if(i-k>=0)qs[l][i][j]-=a[l][i-k][j];
                if(j-k>=0)qs[l][i][j]-=a[l][i][j-k];
                if(i-k>=0 && j-k>=0)qs[l][i][j]+=a[l][i-k][j-k];
            }
        }
    }
//    for(l=1;l<=3;l++){
//        for(i=1;i<=n;i++){
//            for(j=1;j<=n;j++){
//                printf("%d ",qs[l][i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//    }
    for(l=1;l<=3;l++){
    for(i=k;i<=n;i++){
        for(j=n;j>=k;j--){
            while(!dq.empty() && qs[l][i][j]>=dq.back().n)dq.pop_back();
            while(!dq.empty() && dq.front().id>=j+k)dq.pop_front();
            dq.push_back({j,qs[l][i][j]});
            r[l][i][j]=dq.front().n;
        }
        while(!dq.empty())dq.pop_back();
    }
    }
    for(l=1;l<=3;l++){
    for(j=k;j<=n;j++){
        for(i=n;i>=k;i--){
            while(!dq.empty() && r[l][i][j]>=dq.back().n)dq.pop_back();
            while(!dq.empty() && dq.front().id>=i+k)dq.pop_front();
            dq.push_back({i,r[l][i][j]});
            d[l][i][j]=dq.front().n;
        }
        while(!dq.empty())dq.pop_back();
    }
    }
    ma=0;
    for(i=k;i<=n;i++){
        for(j=k;j<=n;j++){
            ma=max(ma,d[1][i][j]+d[2][i][j]+d[3][i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",ma);
}
/*
3 2
1 2 3
4 5 6
7 8 9
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1
*/
/*
4 2
7 7 1 1
7 7 1 1
1 1 1 1
1 1 1 1
1 8 8 1
1 8 8 1
1 1 1 1
1 1 1 1
1 1 1 1
9 9 1 1
9 9 1 1
1 1 1 1
*/
