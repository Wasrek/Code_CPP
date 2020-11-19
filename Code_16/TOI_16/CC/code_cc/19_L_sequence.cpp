/*
    TASK:L Sequence
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],mark[1010];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(k--){
        for(int i=1;i<=n;i++){
            if(a[i]>a[i+1]){
                for(;i<=n;i++) a[i]=a[i+1];
                break;
            }
        }
        n--;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
