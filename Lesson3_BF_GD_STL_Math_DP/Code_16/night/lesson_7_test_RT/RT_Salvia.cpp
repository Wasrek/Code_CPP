/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[110];
long long a[30];
int ans=0;
void permu(int i,int n,long long v){
    // printf("%d %d\n",i,n);
    if(i==n && v==(long long)((1<<26)-1)){
        ans++;
        return;
    }
    if(i==n) return ;
    permu(i+1,n,v|(a[i+1]));
    permu(i+1,n,v);
}
int main()
{
    int n,q,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf(" %s",s+1);
            a[i]=0;
            // printf("%d\n",strlen(s+1));
            for(int j=1;j<=strlen(s+1);j++){
                a[i]|=(1<<(s[j]-'a'));
                // printf("%d\n",s[j]-'a');
            }
        }
        // for(int i=1;i<=n;i++){
        //     printf("%d ",__builtin_popcount(a[i]));
        // }
        // printf("\n");
        ans=0;
        permu(0,n,0);
        printf("%d\n",ans);
    }
    return 0;
}