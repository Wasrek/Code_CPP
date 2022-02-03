/*
    TASK:Reya
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[110];
int main(){
    long long q,m,n,ans,sum,i;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s %lld",a,&m);
        if(strlen(a)>6)
            n=m-1;
        else
            sscanf(a,"%lld",&n);//change string to int
        if(m==1)printf("0\n");
        else if(n==0) printf("1\n");
        else {
            ans=1,sum=1;
            for(i=1;i<=n;i++){
                sum*=i;
                ans+=sum;
                sum%=m,ans%=m;
            }
            printf("%lld",ans);
        }
    }
    return 0;
}
