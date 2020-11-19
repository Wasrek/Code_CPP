/*
    TASK:NC_Land Pair
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int qs[55][55],mp[5000100];
int main(){
    int n,i,j,k,l,x,y,cou=0,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&qs[i][j]);
            qs[i][j]=qs[i][j]+qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k = 1; k <= i; k++)
            {
                for(l = 1; l <= j; l++)
                {
                    mp[qs[i][j]-qs[k-1][j]-qs[i][l-1]+qs[k-1][l-1]+2500000]++;
                }
            }
            for(k = i+1; k <= n; k++)
            {
                for(l = j+1; l <= n; l++)
                {
                    ans+=mp[qs[k][l]-qs[k][j]-qs[i][l]+qs[i][j]+2500000];
                }
            }
            for(k = 1; k <= i; k++)
            {
                for(l = 1; l <= j; l++)
                {
                    mp[qs[i][j]-qs[k-1][j]-qs[i][l-1]+qs[k-1][l-1]+2500000]--;
                }
            }
            ////




            ////
            for(k = 1; k <= i; k++)
            {
                for(l = j;l <= n; l++)
                {
                    mp[qs[i][j]-qs[k-1][j]-qs[i][l-1]+qs[k-1][l-1]]++;
                }
            }
            for(k = i+1; k <= n; k++)
            {
                for(l = j+1; l <= n; l++)
                {
                    ans+=mp[qs[k][l]-qs[k][j]-qs[i][l]+qs[i][j]];
                }
            }
            for(k = 1; k <= n; k++)
            {
                for(l = 1; l <= n; l++)
                {
                    mp[qs[i][j]-qs[k-1][j]-qs[i][l-1]+qs[k-1][l-1]]--;
                }
            }
        }
    }
    printf("%d\n",ans);
}
/*
3
1 2 3
2 3 4
3 4 8
*/
