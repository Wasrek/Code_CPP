/*
    TASK:Bomb Tower
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main(){
    long long i,j,cou=0,n,b;
    a[2]=1;
    scanf("%lld %lld",&n,&b);
    for(i=3;i<=n;i+=2){
        a[i]=1;
    }
    for(i=1;i<=n;i++){
        if(a[i]){
            for(j=i*i;j<=n;j+=i){
                a[j]=0;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(a[i])cou++;
    }
    if(cou<=b)printf("0\n");
    else printf("%lld\n",cou-b);
}
