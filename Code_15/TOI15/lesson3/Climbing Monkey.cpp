/*
    TASK:Climbing Monkey
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],p[200100];
int main(){
    int m,n,k,i,s,w,h,ans,ma=0;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]=i;
    }
    for(i=1;i<=k;i++){
        scanf("%d %d",&w,&h);
        swap(p[w],p[w+1]);
    }
    scanf("%d",&s);
    ans=p[s];
}
