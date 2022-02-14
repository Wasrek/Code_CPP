/*
    TASK: 1122_band
    LANG: CPP
    AUTHOR: WasreK
    ALGO: DP
    TYPE: BATCH
    SCORE: 100
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],ch[1010][1010];
int main()
{
    int n,m,ans5,ans6;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a[i],&b[i]);
        ch[a[i]][b[i]]=1;
        ch[b[i]][a[i]]=1;
    }
    int cnt;
    ans5=ans6=0;
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(a[i]==a[j] || a[i]==b[j] || b[i]==b[j] || b[i]==a[j]) continue;
            cnt=0;
            if(ch[a[i]][a[j]]) cnt++;
            if(ch[b[i]][b[j]]) cnt++;
            if(ch[a[i]][b[j]]) cnt++;
            if(ch[a[j]][b[i]]) cnt++;
            if(cnt==3) ans5++;
            if(cnt==4) ans6++; 
        }
    }
    printf("%d\n",(ans5/2)+(ans6/3));
    return 0;
}