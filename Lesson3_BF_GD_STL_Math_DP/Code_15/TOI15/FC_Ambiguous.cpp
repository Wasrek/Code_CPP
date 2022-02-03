/*
    TASK:FC_Ambiguous
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 500009
struct A{
    char s[55];
};
A has[53][mod];
A s;
char a[100010],temp[53];
int main(){
    long long n,i,j,len,now,tmp,q,k,ans=0,l;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf(" %s",s.s+1);
        len=strlen(s.s+1);
        now=0;
        for(j=1;j<=len;j++){
            now*=29;
            now+=(s.s[j]-'a'+1);
            now%=mod;
        }
        while(has[len][now].s[1])now++,now%=mod;
        strcpy(has[len][now].s+1,s.s+1);
    }
    scanf("%lld",&q);
    while(q--){
        ans=0;
        scanf(" %s",a+1);
        len=strlen(a+1);
        for(k=1;k<=len && k<=50;k++){
            for(i=1;i<=len-k+1;i++){
                j=i+k-1;
                now=0;
                for(l=i;l<=j;l++){
                now*=29;
                now+=(a[l]-'a'+1);
                now%=mod;
                }
                while(has[k][now].s[1] && strncmp(has[k][now].s+1,&a[i],k))now++,now%=mod;
                if(!strncmp(has[k][now].s+1,&a[i],k)){ans++;strcpy(temp,has[k][now].s+1);}
            }
        }
        if(ans==0)printf("NO\n");
        else if(ans==1) printf("%s\n",temp);
        else printf("AMBIGUOUS\n");
    }
    return 0;
}
