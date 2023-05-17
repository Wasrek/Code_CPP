/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int mk[1010][4];
int main()
{
    int r,c,cnt=0,si=0,sj=0,ch=0,lai=0;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        scanf(" %s",a[i]+1);
        mk[i][0]=2e9;
        mk[i][1]=0;
        for(int j=1;j<=c;j++){
            if(a[i][j]=='J' || a[i][j]=='Z'){
                mk[i][0]=min(mk[i][0],j);
                mk[i][1]=max(mk[i][1],j);
                if(lai==0) lai=i;  
            }
            if(a[i][j]=='Z') si=i,sj=j;
            // if(si!=0 && i>si && a[i][j]=='J') ch=-1; 
        }
    }
    // if(mk[si][0]<sj) ch=-1;
    // if(ch==-1){
    //     printf("-1\n");
    //     return 0;
    // }
    int la=1,now,ans=0;
    for(int i=r;i>lai;i--){
        if(mk[i][0]==2e9){
            ans++;
            continue;
        }
        if((r-i)%2==0){//r
            now=max(mk[i][1],mk[i-1][1]);
            ans+=now-la+1;
            la=now;
        }else{//l
            now=min(mk[i][0],mk[i-1][0]);
            ans+=la-now+1;
            la=now;
        }
    }
    if((r-1)%2==0){
        ans+=(mk[lai][1]-la);
    }else{
        ans+=(la-mk[lai][0]);
    }
    printf("%d\n",ans);
    return 0;
}