/*
    TASK:RT_Mean K
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int n,i,j,cou=0,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    scanf("%d",&k);
//    for(i=1;i<=n;i++)printf("%d ",a[i]);
//    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            if(((a[j+i-1]-a[j-1])/i)>=k){cou++;}//printf("%d %d %d\n",i,j,a[j+i-1]-a[j-1]);}
        }
    }
    printf("%d\n",cou);
}
