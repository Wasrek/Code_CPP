/*
    TASK:Swift Beads AB
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int dpa[1000010],dpb[1000010];
int main(){
    int n,cnta=0,cntb=0,len,i,j,ans;
    scanf("%d",&n);
    scanf(" %s",a+1);
    len=strlen(a+1);
    for(i=1;i<=len;i++){
        if(a[i]=='A')dpa[i]=dpa[i-1],dpb[i]=min(dpb[i-1]+1,dpa[i-1]+1);
        if(a[i]=='B')dpb[i]=dpb[i-1],dpa[i]=min(dpb[i-1]+1,dpa[i-1]+1);
    }
    ans=min(dpb[len]+1,dpa[len]);
    printf("%d\n",ans);
}
