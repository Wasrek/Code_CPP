/*
    TASK:Swift Candy Divide
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100];
int main(){
    int n,b,i,l,r,mid,now;
    scanf("%d %d",&n,&b);
    for(i=1;i<=b;i++){
        scanf("%d",&a[i]);
    }
    l=1,r=1e9;
    while(l<r){
        mid=(l+r)/2;
        now=0;
        for(i=1;i<=b;i++){
            now+=a[i]/mid;
            if(a[i]%mid){
                now++;
            }
        }
        if(now<=n)r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
}
