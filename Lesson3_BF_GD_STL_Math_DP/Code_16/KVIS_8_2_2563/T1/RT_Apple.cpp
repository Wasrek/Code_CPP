/*
    TASK:RT_Apple
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[550][550];
int di[550][550];
int main()
{
    int r,c,cnt=0;
    char now;
    scanf("%d %d",&r,&c);  
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            di[i][j]=1e9;
            for(int k=1;k<=r;k++){
                if(a[k][j]=='.') continue;
                di[i][j]=min(di[i][j],abs(i-k));
            }
        }
    }
    // for(int i=1;i<=r;i++){
    //     for(int j=1;j<=c;j++){
    //         printf("%d ",di[i][j]);
    //     }
    //     printf("\n");
    // }
    int q,u,v,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&u,&v);
        if(a[u][v]=='x'){
            printf("0\n");
            continue;
        }
        long long ans=1e18;
        for(int j=1;j<=c;j++){
            if(di[u][j]==1e9) continue;
            b=(abs(j-v)*abs(j-v))+(di[u][j]*di[u][j]);
            ans=min(ans,(long long)b);
        }
        printf("%lld\n",ans);
        a[u][v]='x';
        for(int i=1;i<=r;i++){
            di[i][v]=min(di[i][v],abs(i-u));
        }
    }
    return 0;
}
/*
5 5
..x..
....x
.....
.....
.....
4
3 1
5 3
2 5
4 5
*/