/*
    TASK:RT_Canal
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100],dp[300100];
int main(){
    int n,k,i,cou=0,ans,l,r,mid,mi,ch;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[n+1]=1<<30;
    l=0,r=1000000;
    while(l<r){
        mid=(l+r+1)/2;
        mi=0;ch=0;
        for(i=1;i<=n+1;i++){
            if(a[i]>=mid && i-k<=mi)mi=i;
            else if(i-k>mi)ch=1;
        }
        //if(mid==3)printf("%d %d %d\n",l,r,ch);
        if(ch)r=mid-1;
        else l=mid;
    }
    printf("%d\n",l);
    return 0;
}
/*
10 2
51 16 52 36 21 81 42 52 73 1
*/
