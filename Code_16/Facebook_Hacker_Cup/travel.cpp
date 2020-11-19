/*
    TASK:Travel Restrictions
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char in[60],out[60];
int ans[60][60];
int main()
{
    freopen("travel_restrictions_input.txt","r",stdin);
    freopen("output_travel_l.txt","w",stdout);
    int q,Q,n,ii,jj;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        memset(ans,0,sizeof ans);
        scanf("%d",&n);
        scanf(" %s",in+1);
        scanf(" %s",out+1);
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         printf("%d ",ans[i][j]);
        //     }
        //     printf("\n");
        // }
        for(int i=1;i<=n;i++){
            if(out[i]=='Y'){
                if(in[i-1]=='Y'){
                    ans[i][i-1]=1;
                }
                if(in[i+1]=='Y'){
                    ans[i][i+1]=1;
                }
            }
            if(in[i]=='Y'){
                if(out[i-1]=='Y'){
                    ans[i-1][i]=1;
                }
                if(out[i+1]=='Y'){
                    ans[i+1][i]=1;
                }
            }
            ans[i][i]=1;
        }
        // printf("\n");
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         printf("%d ",ans[i][j]);
        //     }
        //     printf("\n");
        // }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(ans[i][k] && ans[k][j]){
                        ans[i][j]=1;
                    }
                }
            }
        }
        printf("Case #%d:\n",q);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][j]){
                    printf("Y");
                }else printf("N");
            }
            printf("\n");
        }
    }
    return 0;
}