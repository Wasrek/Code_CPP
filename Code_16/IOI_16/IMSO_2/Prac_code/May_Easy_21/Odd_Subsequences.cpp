/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int a[1010],even[1010][1010],odd[1010][1010];
int main()
{
    int q,n,k,ev,od,ans;
    scanf("%d",&q);
    while(q--){
        ev=od=0;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            even[1][i]=even[1][i-1];
            odd[1][i]=odd[1][i-1];
            if(a[i]%2) odd[1][i]++;
            else even[1][i]++;
        }
        for(int i=2;i<=k;i++){
            for(int j=1;j<=n;j++){
                even[i][j]=even[i][j-1];
                odd[i][j]=odd[i][j-1];
                if(a[j]%2){
                    odd[i][j]+=even[i-1][j-1];
                    odd[i][j]%=MOD;
                    even[i][j]+=odd[i-1][j-1];
                    even[i][j]%=MOD;
                }else{
                    odd[i][j]+=odd[i-1][j-1];
                    odd[i][j]%=MOD;
                    even[i][j]+=even[i-1][j-1];
                    even[i][j]%=MOD;
                }
            }
        }
        printf("%d\n",odd[k][n]%MOD);
    }    
    return 0;
}