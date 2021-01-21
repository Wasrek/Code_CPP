/*
    TASK:A-QAQ
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[110];
int main()
{
    scanf(" %s",s+1);
    long long q,i,qa,qaq,n;
    q=qa=qaq=0;
    n=strlen(s+1);
    for(i=1;i<=n;i++){
        if(s[i]=='Q'){
            q++;
            if(qa!=0)qaq+=qa;
        }
        if(s[i]=='A')qa+=q;
    }
    printf("%lld",qaq);
    return 0;
}
