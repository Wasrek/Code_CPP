/*
    TASK:RT_Arrows
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],mark[1000010];
int main(){
    int n,i,j;
    long long sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
//        for(j=1;j<=5;j++)printf("%d ",mark[j]);
//        printf("\n");
        mark[a[i]]++;
        if(mark[a[i]+1])mark[a[i]+1]--;
    }
    for(i=1;i<=n;i++){
        sum+=mark[a[i]];
        mark[a[i]]=0;
    }
    printf("%lld\n",sum);
}
