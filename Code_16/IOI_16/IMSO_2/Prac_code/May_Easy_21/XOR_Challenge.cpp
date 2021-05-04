/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,ch=1;
    long long a=0,b=0;
    scanf("%d",&c);
    for(int i=20;i>=0;i--){
        if(c & (1<<i)){
            if(a<b){
                a+=(1<<i);
            }else{
                b+=(1<<i);
            }
            ch=0;
        }else{
            if(ch) continue; 
            a+=(1<<i);
            b+=(1<<i);
        }
    }
    printf("%lld",a*b);
    return 0;
}