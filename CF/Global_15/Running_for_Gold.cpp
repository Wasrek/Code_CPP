/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[50100][6];
int rk[50100];
bool comp(int x,int y){
    int cnt=0;
    for(int i=1;i<=5;i++){
        if(a[x][i]<a[y][i]) cnt++;
    }
    if(cnt>=3) return 1;
    return 0;
}
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                scanf("%d",&a[i][j]);
            }
            rk[i]=i;
        }
        int ch=0;
        sort(rk+1,rk+1+n,comp);
        for(int i=1;i<=n;i++){
            if(rk[1]==i) continue;
            if(!comp(rk[1],i)){
                printf("-1\n");
                ch=1;
                break;
            }
        }
        if(!ch) printf("%d\n",rk[1]);
    }
    return 0;
}