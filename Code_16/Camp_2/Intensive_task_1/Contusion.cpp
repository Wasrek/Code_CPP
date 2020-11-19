/*
    TASK:Contusion
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int cnt[20010];
int main()
{
    int n,x,y,c,now;
    scanf("%d %d %d %d",&n,&x,&y,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            now=abs(i-x)+abs(j-y);
            // printf("%d ",now);
            cnt[now]++;
        }
        // printf("\n");
    }
    for(int i=0;i<=n*2;i++){
        if(i>0)
        cnt[i]+=cnt[i-1];
        if(cnt[i]>=c){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}