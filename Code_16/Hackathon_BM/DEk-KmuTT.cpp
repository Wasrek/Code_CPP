/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    long long ans=0;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
        if(s[i]=='u') ans+=15;
        if(s[i]=='k') ans+=2;
        if(s[i]=='t') ans+=1000;
        if(s[i]=='-') ans-=2;
        if(s[i]=='m') ans+=3;
        if(s[i]=='p') ans+=40;
        if(s[i]=='c') ans+=500;
        if(s[i]=='e') ans+=5;
    }
    printf("%lld\n",ans);
    return 0;
}