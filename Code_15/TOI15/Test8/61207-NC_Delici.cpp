/*
    TASK:NC_Delicious
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    long long n,i,ch=0,cou=0,sum=0,c=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<0){ch=1;}
    }
    //printf("%d\n",ch);
    if(!ch){printf("%lld\n",n);return 0;}
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        if(a[i]>0)break;
        sum+=a[i];
        c++;
    }
    //printf("%lld\n",sum);
    for(i=n;i>=1;i--){
        sum+=a[i];
        cou++;
        if(sum>0)break;
    }
    cou=max(cou,c);
    printf("%lld\n",n-cou);
}
/*
5
10
-2
-30
40
-1
*/
