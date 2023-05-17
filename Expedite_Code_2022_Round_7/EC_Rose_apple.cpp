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
unordered_map< int,int > mpx,mpy,mpdif,mps;
int main()
{
    int n,k,a,b,ans=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        mpx[a]++;
        mpy[b]++;
        mpdif[a-b]++;
        mps[a+b]++;
        if(ans) continue;
        if(ans==0 && (mpx[a]==k || mpy[b]==k || mpdif[a-b]==k  || mps[a+b]==k)) ans=i;
    }
    printf("%d\n",ans);
    return 0;
}