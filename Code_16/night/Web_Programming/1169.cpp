/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[220];
stack< char > st;
int main()
{
    scanf(" %s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        if(!st.empty() && s[i]==')' && st.top()=='(') st.pop();
        else st.push(s[i]);
    }
    int cnt=0;
    while(!st.empty()){
        cnt++;
        st.pop();
    }
    printf("%d\n",cnt);
    return 0;
}