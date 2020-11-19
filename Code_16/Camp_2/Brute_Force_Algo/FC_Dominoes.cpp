/*
    TASK:FC_Dominoes
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],h[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i],&h[i]);
    }
    int ma=0,m=0,cnt=0,ans=0,ansi=0;
    for(int i=1;i<=n;i++){
        if(ma>a[i]){
            ma=max(ma,a[i]+h[i]);
            cnt++;
            if(cnt>ans){
                ans=cnt;
                ansi=m;
            }
        }else{
            m=i;
            cnt=1;
            ma=a[i]+h[i];
            if(cnt>ans){
                ans=cnt;
                ansi=m;
            }
        }
    }
    ma=2e9,m=n+1,cnt=0;
    int ans1=0,ansi1=0;
    for(int i=n;i>=1;i--){
        if(ma<a[i]){
            ma=min(ma,a[i]-h[i]);
            cnt++;
            if(cnt>ans1){
                ans1=cnt;
                ansi1=m;
            }
        }else{
            m=i;
            cnt=1;
            ma=a[i]-h[i];
            if(cnt>ans1){
                ans1=cnt;
                ansi1=m;
            }
        }
    }
    // printf("%d %d\n",ans,ansi);
    // printf("%d %d\n",ans1,ansi1);
    if(ans>ans1){
        printf("%d R\n",ansi);
    }else if(ans<ans1){
    printf("%d L\n",ansi1);
    }else {
        if(ansi<ansi1){
            printf("%d R\n",ansi);
        }else if(ansi>=ansi1){
            printf("%d L\n",ansi1);
        }
    }
    return 0;
}