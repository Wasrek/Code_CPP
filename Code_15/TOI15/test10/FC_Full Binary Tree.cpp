/*
    TASK:FC_Full Binary Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[(1<<11)];
long long ans[11][1030],b[11];
void tree(int l,int r,int c){
    if(l==r){ans[c][++b[c]]=a[l];return ;}
    int mid=(r-l)/2+l;
    ans[c][++b[c]]=a[mid];
    tree(l,mid-1,c+1);
    tree(mid+1,r,c+1);
}
int main(){
    long long k,i,j;
    scanf("%lld",&k);
    for(i=1;i<(1<<k);i++){
        scanf("%lld",&a[i]);
    }
    tree(1,(1<<k)-1,1);
    for(i=1;i<=k;i++){
        for(j=1;j<=b[i];j++){
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }
}
