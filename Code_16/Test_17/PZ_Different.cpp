/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[10010][25];
int sta[25][3],qs0[25],qs1[25];
int main()
{
    int q,n,k,mi,ma,la;
    scanf("%d",&q);
    while(q--){
        mi=ma=0;
        memset(sta,0,sizeof sta);
        memset(qs1,0,sizeof qs1);
        memset(qs0,0,sizeof qs0);
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%s",a[i]+1);
            for(int j=1;j<=k;j++){
                qs1[j]+=(a[i][j]-'0');
                qs0[j]=n-qs1[j];
                if(j>1 && a[i][j-1]=='0')sta[j][0] |= 1<<(a[i][j]-'0');
                if(j>1 && a[i][j-1]=='1')sta[j][1] |= 1<<(a[i][j]-'0');
            }
        }
        // for(int i=1;i<=k;i++){
        //     printf("%d %d\n",qs0[i],qs1[i]);
        // }
        for(int i=1;i<=k;i++){
            // printf("%d %d %d\n",i,mi,ma);
            if(mi==ma){
                if(qs1[i]<qs0[i]){
                    printf("1");
                    la=1;
                    if(qs1[i]) ma++;
                }else {
                    printf("0");
                    la=0;
                    if(qs0[i]) ma++;
                }
                continue;
            }
            if(sta[i][la]==3 || sta[i][la]==2){
                printf("0");
                if(sta[i][la^1]==2){
                    ma++;
                }
                mi++;
                la=0;
            }else if(sta[i][la]==1){
                printf("1");
                if(sta[i][la^1]==1){
                    ma++;
                }
                mi++;
                la=1;
            }
        }
        printf("\n");
    }
    return 0;
}
/*
3
3 5
01001
11100
10111
1 4
0000
4 2
00
01
10
11
*/