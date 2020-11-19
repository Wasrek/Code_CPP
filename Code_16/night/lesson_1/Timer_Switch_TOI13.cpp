/*
    TASK:timer Switch
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[10000100];
int p[5000100];
int main()
{
    int n,k,ans;
    scanf("%d",&n);
    scanf(" %s",s+1);
    for(int i=1;i<=n;i++){
        s[n+i]=s[i];
    }
    k=0;
    for(int i=2;i<=n;i++){
        while(k>0 && s[k+1]!=s[i]) k=p[k];
        if(s[k+1]==s[i]) k++;
        p[i]=k;
    }
    // for(int i=1;i<=n;i++) printf("%d ",p[i]);
    k=0;
    for(int i=2;i<=n*2;i++){
        while(k>0 && s[k+1]!=s[i]) k=p[k];
        if(s[k+1]==s[i]) k++;
        if(k==n){
            ans=i;
            break;
        } 
    }
    // printf("%d\n",ans);
    printf("%d\n",ans-n);
    return 0;
}