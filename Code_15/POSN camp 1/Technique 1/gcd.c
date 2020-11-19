/*
    TASK:GCD
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    int n,i,ans,now;
    scanf("%d %d",&n,&ans);
    for(i=0;i<n-1;i++){
        scanf("%d",&now);
        ans = gcd(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}
