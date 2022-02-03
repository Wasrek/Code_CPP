/*
    TASK:RC_And 0
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],mark[1000100];
int main(){
    int n,q,i,l,r;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(q--){
        scanf("%d %d",&l,&r);
        mark[l]+=1;
        mark[r+1]+=-1;
    }
    for(i=1;i<=n;i++){
        mark[i]+=mark[i-1];
        if(mark[i])printf("0 ");
        else printf("%d ",a[i]);
    }
}
