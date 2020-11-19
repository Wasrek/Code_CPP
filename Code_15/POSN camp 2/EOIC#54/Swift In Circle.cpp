/*
    TASK:Swift In Circle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,n,k;
    double ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        ans=(double)k*(double)k*(double)n*sqrt(3.00)/4;
        printf("%.1f",ans);
    }
}
