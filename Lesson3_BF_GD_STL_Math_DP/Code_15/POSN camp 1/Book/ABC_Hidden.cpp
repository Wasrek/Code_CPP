/*
    TASK:ABC_Hidden
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long qsumA[1000002],qsumC[1000002];
char a[1000009];
int main()
{
    long long q,i,ans,len;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s",a+1);
        len = strlen(a+1);
        for(i=1;i<=len;i++){
            qsumA[i]=qsumA[i-1],qsumC[i]=qsumC[i-1];
            if(a[i]=='A') qsumA[i]++;
            if(a[i]=='C') qsumC[i]++;
        }
        for(ans=0,i=1;i<=len;i++){
            if(a[i]=='B')
                ans+=(qsumA[i-1]*(qsumC[len]-qsumC[i]));
        }
        printf("%lld\n",ans);
    }
}
