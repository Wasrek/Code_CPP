/*
    TASK:Deva scales
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0,val=1,m,ans=0;
    scanf("%d",&n);
    while(n){
        m=n%3;
        n/=3;
        if(m==1) ans+=val;
        if(m==2) n++;
        if(m)cnt++;
        val*=3;
    }

    printf("%d %d\n",cnt,ans);
    return 0;
}