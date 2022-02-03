/*
    TASK:Greatest Common Divisor
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)return b;
    else gcd(b,a%b);
}
int main(){
    int a,b,ans;
    scanf("%d %d",&a,&b);
    if(a==0){
        printf("%d\n",b);
        return 0;
    }
    if(b==0){
        printf("%d\n",a);
        return 0;
    }
    ans=gcd(a,b);
    printf("%d\n",ans);
    return 0;
}
