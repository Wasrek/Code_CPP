/*
    TASK:FC_threeparen
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[100010];
stack< char > st;
int main(){
    int q,len,i,ch;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len=strlen(a);
        ch=0;
        for(i=0;i<len;i++){
            if(a[i]=='(' || a[i]=='{' || a[i]=='[')st.push(a[i]);
            else{
                if(a[i]==')' && !st.empty() && st.top()=='(')st.pop();
                else
                if(a[i]=='}' && !st.empty() && st.top()=='{')st.pop();
                else
                if(a[i]==']' && !st.empty() && st.top()=='[')st.pop();
                else{
                    ch=1;
                    break;
                }
            }
        }
        if(!ch && st.empty())printf("yes\n");
        else printf("no\n");
        while(!st.empty())st.pop();
    }
}
