/*
    TASK:maxval
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int n,k,maxx=-1e9;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
        if(i-k>=0){
            maxx=max(maxx,a[i]-a[i-k]);
        }
    }
    printf("%d\n",maxx);
}