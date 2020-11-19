/*
    TASK:Good
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int rmq[20][1000100];
int main(){
    int n,q,i,j,a,b,k;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d",&rmq[0][i]);
    }
    for(i=1;(1<<i)<=n;i++){
        for(j=0;j+(1<<i)<=n;j++){
            rmq[i][j]=max(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
        }
    }
    while(q--){
        scanf("%d %d",&a,&b);
        k = log2(b-a+1);
        printf("%d\n",max(rmq[k][a],rmq[k][b-(1<<k)+1]));
    }
    return 0;
}
/*
6 3
1
3
2
4
2
6
0 5
0 2
3 5
*/
