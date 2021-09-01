/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[45],ss[45];
int main()
{
    int q,n,ans;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d",&n);
        scanf(" %s",s+1);
        for(int i=1;i<=n;i++){
            ss[i]=s[i];
        }
        sort(ss+1,ss+1+n);
        for(int i=1;i<=n;i++){
            if(s[i]==ss[i]) ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}