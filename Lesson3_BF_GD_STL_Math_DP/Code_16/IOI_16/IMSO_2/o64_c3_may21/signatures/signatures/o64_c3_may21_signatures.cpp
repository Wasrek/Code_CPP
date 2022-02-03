/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map< int ,bool> mp;
char str[25];
int main()
{
    freopen("8.in","r",stdin);
    freopen("8.out","w",stdout);
    printf("8\n");
    int k,n,now;
    long long cnt=0;
    scanf("%d %d",&k,&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",str);
        now=0;
        for(int j=0;j<k;j++){
            now+=((1<<(k-1-j))*(str[j]-'0'));
        }
        mp[now]=1;
        // printf("%d\n",now);
    }
    now=0;
    while(mp[now]){
        now++;
    }
    mp[now]=1;
    for(int i=(k-1);i>=0;i--){
        printf("%d",((1<<i) & now));
        cnt++;
    }
    while(1){
        now-=((1<<(k-1))&now);
        now*=2;
        if(!mp[now+1]){
            mp[now+1]=1;
            now+=1;
            printf("1");
            cnt++;
        }else if(!mp[now]){
            mp[now]=1;
            printf("0");
            cnt++;
        }else{
            break;
        }
    }
    printf("\n%lld\n",cnt);
    return 0;
}