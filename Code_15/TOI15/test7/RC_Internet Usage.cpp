/*
    TASK:RC_Internet Usage
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,n,now,sum=0;
    scanf("%d",&a);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&now);
        sum+=(a-now);
        //printf("%d\n",sum);
    }
    sum+=a;
    printf("%d\n",sum);
}
